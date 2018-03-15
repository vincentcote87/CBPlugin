#ifndef CBIMPLEMENTATIONBUILDER_H
#define CBIMPLEMENTATIONBUILDER_H

#include "logmanager.h"
#include "editormanager.h"
#include "projectmanager.h"
#include "ImplementationBuilder.h"
#include "editorbase.h"
#include "cbproject.h"

class CBImplementationBuilder {
    public:
        explicit CBImplementationBuilder(ImplementationBuilder*);
        ~CBImplementationBuilder();
        int build();

    private:
        ImplementationBuilder* _builder;
        LogManager* _logManager;
        EditorManager* _editorManager;
        ProjectManager* _projectManager;

        void init();
        string toString(const wxString&);
        wxString toWxString(const string&);
};

#endif // CBIMPLEMENTATIONBUILDER_H
