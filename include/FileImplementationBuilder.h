#ifndef FILEIMPLEMENTATIONBUILDER_H
#define FILEIMPLEMENTATIONBUILDER_H

#include "ImplementationBuilder.h"
#include <string>
#include "wx/file.h"

using std::string;

class FileImplemenationBuilder : public ImplementationBuilder {
    public:
        explicit FileImplemenationBuilder(InterfaceValidator*);
        virtual ~FileImplemenationBuilder() {}
        virtual void build(string) override;
        virtual void buildActiveFile() override;
    private:
        wxFile _file;
};

#endif // FILEIMPLEMENTATIONBUILDER_H
