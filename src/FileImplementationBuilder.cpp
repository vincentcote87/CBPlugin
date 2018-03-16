#include "FileImplementationBuilder.h"

FileImplemenationBuilder::FileImplemenationBuilder(InterfaceValidator* validator) : ImplementationBuilder(validator) {

}

FileImplemenationBuilder::~FileImplemenationBuilder() {}


string FileImplemenationBuilder::build(string implementationToBuild) {
    string headerFile = implementationToBuild; // The title is the name that appears on the tab above
    string implementationFile = getImplementationName(headerFile);

    string srcPath = "src/"; // Additional path interface. Trying to be extensible to something like src/whatever.cpp
    if(srcPath == "")
        srcPath = implementationFile; // It will be this everytime until we add a way to read in the actual file path
    else
        srcPath += implementationFile;

    fstream file(srcPath);


    // TODO: May not need as people will usually link their include folders
    file << "#include \"" + headerFile + "\"\n"; // Add an include with the name of the header file
    return srcPath;
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
