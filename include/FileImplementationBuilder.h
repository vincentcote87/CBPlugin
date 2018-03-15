#ifndef FILEIMPLEMENTATIONBUILDER_H
#define FILEIMPLEMENTATIONBUILDER_H

#include "ImplementationBuilder.h"

// TODO: Clean up
#include <string>
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
#include <wx/dynarray.h>
#include <wx/filefn.h>
#include <fstream>

using std::ofstream;
using std::string;

class FileImplemenationBuilder : public ImplementationBuilder {
    public:
        explicit FileImplemenationBuilder(InterfaceValidator*);
        virtual ~FileImplemenationBuilder();
        virtual string build(string) override;


    private:
        string getImplementationName(const string&) const;
        string getHeaderFileName(const string&) const;

};

#endif // FILEIMPLEMENTATIONBUILDER_H
