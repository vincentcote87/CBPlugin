#include "FileImplementationBuilder.h"

FileImplemenationBuilder::FileImplemenationBuilder(InterfaceValidator* validator) : ImplementationBuilder(validator) {

}

FileImplemenationBuilder::~FileImplemenationBuilder() {
    logManager = nullptr;
    editorManager = nullptr;
    projectManager = nullptr;
}

void FileImplemenationBuilder::init() {
    logManager = Manager::Get()->GetLogManager();
    editorManager = Manager::Get()->GetEditorManager();
    projectManager = Manager::Get()->GetProjectManager();
}

int FileImplemenationBuilder::build(wxString implementationToBuild) {
    wxString headerFile = implementationToBuild; // The title is the name that appears on the tab above
    wxString implementationFile = getImplementationName(headerFile);

    wxString srcPath = _("src/"); // Additional path interface. Trying to be extensible to something like src/whatever.cpp
    if(srcPath == _(""))
        srcPath = implementationFile; // It will be this everytime until we add a way to read in the actual file path
    else
        srcPath.Append(implementationFile);

    if(wxFileExists(srcPath)) {
        logManager->Log(_("File already exists! For now we are not dealing with this case... Sorry."));
        return -1;
    }

    wxFile file(srcPath, wxFile::OpenMode::write); // Open a file with the name of the implementation source file.

    if(!file.IsOpened()) {
        logManager->Log(_("Could not open that was made!"));
        return -1;
    }

    logManager->Log(_("Opened File!"));
    // TODO: May not need as people will usually link their include folders
    wxString includeDirectory(_("")); // Once again, open for extensibility of something like include/whatever.h
    if(includeDirectory == (_(""))) {
        file.Write(_("#include \"") + headerFile + _("\"")); // Add an include with the name of the header file
    }

    else
        file.Write(_("#include \"") + includeDirectory + _("/") + headerFile + _("\"")); // For include/whatever.h

    file.Close();

    cbProject* project = projectManager->GetActiveProject();

    project->BeginAddFiles();
    // TODO: User chooses a target path.

    wxString activeTarget = project->GetActiveBuildTarget();
    if(project->AddFile(activeTarget, srcPath) == nullptr) {
        logManager->Log(_("Adding file did not work"));
        return -1;
    }

    logManager->Log(_("Added file!"));
    project->EndAddFiles();
    cbProjectManagerUI& uiManager = projectManager->GetUI();
    uiManager.RebuildTree();

    editorManager->Open(srcPath);
    return 0;
}

int FileImplemenationBuilder::buildActiveFile() {
    wxString fileToBuild = Manager::Get()->GetEditorManager()->GetActiveEditor()->GetTitle();
    build(fileToBuild);
}

string FileImplemenationBuilder::getImplementationName(const string& headerName) const {
    string implementationName = headerName;
    size_t indexOfExtension = implementationName.find(".h");
    if(indexOfExtension == string::npos)
        return "";

    implementationName = implementationName.erase(indexOfExtension);
    implementationName += ".cpp";

    return implementationName;
}
