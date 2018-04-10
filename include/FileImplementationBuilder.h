#ifndef FILEIMPLEMENTATIONBUILDER_H
#define FILEIMPLEMENTATIONBUILDER_H

#include "ImplementationBuilder.h"

// TODO: Clean up
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using std::ofstream;
using std::string;
using std::vector;
using std::map;

class FileImplemenationBuilder : public ImplementationBuilder {
    public:
        explicit FileImplemenationBuilder(InterfaceValidator*);
        virtual ~FileImplemenationBuilder();
        virtual string build(string) override;


    private:
        string getImplementationName(const string&) const;
        string getHeaderFileName(const string&) const;
        vector<string> specifiersToCheck = { "virtual", "explicit"};
        map<string, string> returnTypes = { {"int", "-1"}, {"string", "\"\""}, {"char", "\' \'"}, { "double", "0.0" }, { "float", "0.0" } };

};

#endif // FILEIMPLEMENTATIONBUILDER_H
