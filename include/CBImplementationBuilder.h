#ifndef CBIMPLEMENTATIONBUILDER_H
#define CBIMPLEMENTATIONBUILDER_H

#include "logmanager.h"
#include "editormanager.h"
#include "projectmanager.h"
#include "ImplementationBuilder.h"

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
};

#endif // CBIMPLEMENTATIONBUILDER_H
