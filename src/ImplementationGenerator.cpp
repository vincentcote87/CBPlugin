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

#include "FileValidator.h"
#include "FileImplementationBuilder.h"
#include "CBImplementationBuilder.h"

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

    InterfaceValidator* validator = new FileValidator();
    ImplementationBuilder* fileBuilder = new FileImplemenationBuilder(validator);

    CBImplementationBuilder* cbIB = new CBImplementationBuilder(fileBuilder);

    return cbIB->build();
}
