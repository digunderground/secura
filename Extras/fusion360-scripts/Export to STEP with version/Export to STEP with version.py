import adsk.core, adsk.fusion, traceback
import os

app = adsk.core.Application.get()
ui = app.userInterface

def get_export_folder():
    folder_dialog = ui.createFolderDialog()
    folder_dialog.title = 'Select Folder to Save STEP Files'
    if folder_dialog.showDialog() == adsk.core.DialogResults.DialogOK:
        return folder_dialog.folder
    return None

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

        filename = f"{prefix}_{component.name}".replace(" ", "_")
        file_path = os.path.join(export_path, f"{filename}.step")

        step_options = export_mgr.createSTEPExportOptions(file_path, component)
        step_options.exportAsOneFile = True
        export_mgr.execute(step_options)

    def process_component(component, prefix=''):
        export_component(component, prefix)

        for occ in component.occurrences:
            if occ.isLightBulbOn:
                child_prefix = f"{prefix}_{occ.component.name}".replace(" ", "_")
                process_component(occ.component, child_prefix)

    root_comp = design.rootComponent
    process_component(root_comp, root_comp.name)

def run(context):
    try:
        folder = get_export_folder()
        if not folder:
            ui.messageBox('No folder selected. Aborting.')
            return

        save_all_components_as_step(folder)
        ui.messageBox("Visible-layer components successfully exported as STEP files.")

    except Exception as e:
        ui.messageBox('Failed:\n{}'.format(traceback.format_exc()))
