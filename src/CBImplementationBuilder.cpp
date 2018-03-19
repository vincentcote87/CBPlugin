#include "CBImplementationBuilder.h"

CBImplementationBuilder::CBImplementationBuilder(ImplementationBuilder* builder) {
    _builder = builder;
    init();
}

CBImplementationBuilder::~CBImplementationBuilder() {
    _logManager = nullptr;
    _projectManager = nullptr;
    _editorManager = nullptr;
    delete _builder;
}

int CBImplementationBuilder::build() {
    wxString header = _editorManager->GetActiveEditor()->GetName();
    wxString title = _editorManager->GetActiveEditor()->GetTitle();

    wxChar nl = '\n';
    header = header.Remove(header.Find(nl));
    _logManager->Log(_("Name of path given: ") + header);

   // _editorManager->CloseActive();

    string output = _builder->build(toString(header));

    if(output == "" || output.back() == '!') {
        wxString wxOutput = toWxString(output);
        _logManager->Log(_("File was unable to be opened!"));
        _logManager->Log(wxOutput);
        return -1;
    }

    _logManager->Log(_("Name of file path returned: "));
    _logManager->Log(toWxString(output));

    wxString filePath = toWxString(output);

    cbProject* project = _projectManager->GetActiveProject();

    project->BeginAddFiles();
    wxString buildTarget = project->GetActiveBuildTarget();

    if(!project->AddFile(buildTarget, filePath)) {
        _logManager->Log(_("Could not add file to project!"));
        return -1;
    }

    project->EndAddFiles();
    _projectManager->GetUI().RebuildTree();

    _editorManager->Open(filePath);
    return 0;
}

void CBImplementationBuilder::init() {
    _logManager = Manager::Get()->GetLogManager();
    _editorManager = Manager::Get()->GetEditorManager();
    _projectManager = Manager::Get()->GetProjectManager();
}

string CBImplementationBuilder::toString(const wxString& wx) {
    string convertedString;
    for(const char c : wx) {
        convertedString += c;
    }

    return convertedString;
}

wxString CBImplementationBuilder::toWxString(const string& str) {
    wxString convertedWxString;
    for(const char c : str) {
        convertedWxString += c;
    }

    return convertedWxString;
}
