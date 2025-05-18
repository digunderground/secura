import adsk.core, adsk.fusion, traceback
import os
import re

app = adsk.core.Application.get()
ui = app.userInterface

def get_export_folder():
    folder_dialog = ui.createFolderDialog()
    folder_dialog.title = 'Select Folder to Save STEP Files'
    if folder_dialog.showDialog() == adsk.core.DialogResults.DialogOK:
        return folder_dialog.folder
    return None

def clean_version(name):
    # Remove version suffixes like _v1, -v2.3, v7, etc.
    return re.sub(r'([_-]?v\d+(\.\d+)?)+', '', name, flags=re.IGNORECASE)

def save_all_components_as_step(export_path):
    design = adsk.fusion.Design.cast(app.activeProduct)
    export_mgr = design.exportManager

    def has_visible_bodies(component):
        try:
            for body in component.bRepBodies:
                if body.isVisible:
                    return True
        except:
            pass
        return False

    def export_component(component, prefix=''):
        if not has_visible_bodies(component):
            return

        cleaned_prefix = clean_version(prefix).strip('_- ')
        cleaned_name = clean_version(component.name).strip('_- ')

        if cleaned_prefix == cleaned_name or not cleaned_prefix:
            filename = cleaned_name
        else:
            filename = f"{cleaned_prefix}_{cleaned_name}"

        filename = filename.replace(" ", "_")
        file_path = os.path.join(export_path, f"{filename}.step")

        step_options = export_mgr.createSTEPExportOptions(file_path, component)
        step_options.exportAsOneFile = True
        export_mgr.execute(step_options)

    def process_component(component, prefix=''):
        export_component(component, prefix)

        for occ in component.occurrences:
            if occ.isLightBulbOn:
                child_name = clean_version(occ.component.name).strip('_- ')
                child_prefix = f"{prefix}_{child_name}".replace(" ", "_") if prefix else child_name
                process_component(occ.component, child_prefix)

    root_comp = design.rootComponent
    process_component(root_comp, clean_version(root_comp.name))

def run(context):
    try:
        folder = get_export_folder()
        if not folder:
            ui.messageBox('No folder selected. Aborting.')
            return

        save_all_components_as_step(folder)
        ui.messageBox("STEP export complete — filenames cleaned and deduplicated.")

    except Exception as e:
        ui.messageBox('Failed:\n{}'.format(traceback.format_exc()))
