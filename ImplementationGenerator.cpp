#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include "ImplementationGenerator.h"

#include <logmanager.h>
#include <manager.h>
#include <editormanager.h>
#include <wx/string.h>
#include <wx/file.h>
#include <editorbase.h>
#include <cbeditor.h>
#include <projectmanager.h>
#include <cbproject.h>
#include <iostream>
#include <fstream>
#include <string>
#include <wx/dynarray.h>
#include <wx/filefn.h>

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
    PluginRegistrant<ImplementationGenerator> reg(_T("ImplementationGenerator"));
}

// constructor
ImplementationGenerator::ImplementationGenerator()
{
    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("ImplementationGenerator.zip")))
    {
        NotifyMissingFile(_T("ImplementationGenerator.zip"));
    }
}

// destructor
ImplementationGenerator::~ImplementationGenerator()
{
}

void ImplementationGenerator::OnAttach()
{
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
}

void ImplementationGenerator::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
}

int ImplementationGenerator::Execute()
{
    if(!IsAttached())
        return -1;

    // Store the master Manager and EditorMaster
    Manager* instance = Manager::Get();
    EditorManager* editInstance = instance->GetEditorManager();
    EditorBase* active = editInstance->GetActiveEditor(); // Get the active editor. ImplementationGenerator.cpp if you are reading this ;)

    wxString headerFile = active->GetTitle(); // The title is the name that appears on the tab above
    wxString implementationFile = headerFile; // Copy the string into the implementation file name
    if(implementationFile.Replace(_(".h"), _(".cpp")) == 0) { // Replace .h with .cpp. If the count is 0, that means it didn't replace anything and it is not a .h file
        instance->GetLogManager()->Log(_("Run on a .h file!"));
        return -1;
    }

    wxString srcPath = _(""); // Additional path interface. Trying to be extensible to something like src/whatever.cpp
    if(srcPath == _(""))
        srcPath = implementationFile; // It will be this everytime until we add a way to read in the actual file path
    else
        srcPath.Append(implementationFile);

    if(wxFileExists(srcPath)) {
        instance->GetLogManager()->Log(_("File already exists! For now we are not dealing with this case... Sorry."));
        return -1;
    }

    wxFile file(srcPath, wxFile::OpenMode::write); // Open a file with the name of the implementation source file.

    if(!file.IsOpened()) {
        instance->GetLogManager()->Log(_("Could not open that was made!"));
        return -1;
    }

    instance->GetLogManager()->Log(_("Opened File!"));
    wxString includeDirectory(_("")); // Once again, open for extensibility of something like include/whatever.h
    if(includeDirectory == (_(""))) {
        file.Write(_("#include \"") + headerFile + _("\"")); // Add an include with the name of the header file
    }

    else
        file.Write(_("#include \"") + includeDirectory + _("/") + headerFile + _("\"")); // For include/whatever.h

    file.Close();

    cbProject* project = instance->GetProjectManager()->GetActiveProject();

    project->BeginAddFiles();
    // TODO: User chooses a target path.

    wxString activeTarget = project->GetActiveBuildTarget();
    if(project->AddFile(activeTarget, srcPath) == nullptr) {
        instance->GetLogManager()->Log(_("Adding file did not work"));
        return -1;
    }

    instance->GetLogManager()->Log(_("Added file!"));
    project->EndAddFiles();
    cbProjectManagerUI& uiManager = instance->GetProjectManager()->GetUI();
    uiManager.RebuildTree();

    editInstance->Open(srcPath);
    return 0;
}
