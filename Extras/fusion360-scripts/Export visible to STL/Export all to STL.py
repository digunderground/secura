import adsk.core, adsk.fusion, traceback
import os
import re  # For regex to strip version numbers

def get_export_folder():
    folder_dialog = ui.createFolderDialog()
    folder_dialog.title = 'Select Folder to Save STL Files'
    if folder_dialog.showDialog() == adsk.core.DialogResults.DialogOK:
        return folder_dialog.folder
    return None

def clean_name(name):
    # Remove common version suffixes like _v1, -v2, (v3), etc.
    return re.sub(r'[\-_ ]?v\d+\b', '', name, flags=re.IGNORECASE).strip().replace(' ', '_')

def save_all_bodies_as_stl(export_path):
    design = adsk.fusion.Design.cast(app.activeProduct)
    root_comp = design.rootComponent
    export_mgr = design.exportManager

    def process_component(component):
        for body in component.bRepBodies:
            if not body.isSolid:
                continue

            clean_body_name = clean_name(body.name)
            file_path = os.path.join(export_path, f"{clean_body_name}.stl")

            # Create STL export options
            stl_options = export_mgr.createSTLExportOptions(body, file_path)
            stl_options.meshRefinement = adsk.fusion.MeshRefinementSettings.MeshRefinementMedium
            export_mgr.execute(stl_options)

        for occ in component.occurrences:
            process_component(occ.component)

    process_component(root_comp)

def run(context):
    try:
        global app, ui
        app = adsk.core.Application.get()
        ui  = app.userInterface

        folder = get_export_folder()
        if not folder:
            ui.messageBox('No folder selected. Aborting.')
            return

        save_all_bodies_as_stl(folder)
        ui.messageBox("All bodies successfully exported.")

    except Exception as e:
        if ui:
            ui.messageBox('Failed:\n{}'.format(traceback.format_exc()))
