#include "FileImplementationBuilder.h"


FileImplemenationBuilder::FileImplemenationBuilder(InterfaceValidator* validator) : ImplementationBuilder(validator) {

}

FileImplemenationBuilder::~FileImplemenationBuilder() {}


string FileImplemenationBuilder::build(string implementationToBuild) {
    _validator->setInterface(implementationToBuild);

    string headerFile = implementationToBuild;
    string implementationFile = getImplementationName(headerFile);

    if(implementationFile == "")
        return implementationFile;

    ofstream file(implementationFile);

    if(!file.is_open()) {
        implementationFile += "!";
        return implementationFile;
    }

    // TODO: May not need as people will usually link their include folders
    file << "#include \"" + getHeaderFileName(headerFile) + "\"\n\n"; // Add an include with the name of the header file
    while(!_validator->endOfStream()) {
        string lineToWrite = _validator->next();
        if(lineToWrite != "")
            file << lineToWrite;
    }
    // Validation steps

    file.close();
    return implementationFile;
}

string FileImplemenationBuilder::getImplementationName(const string& headerName) const {
    string implementationName = headerName;
    size_t indexOfFileName = implementationName.find_last_of('/');
    if(indexOfFileName == string::npos)
        return "";

    string fileName = implementationName.substr(indexOfFileName+1);

    size_t indexOfFolderName = implementationName.find("include");
    if(indexOfFolderName == string::npos)
        return "";

    implementationName = implementationName.erase(indexOfFolderName);
    implementationName += "src/";

    size_t indexOfExtension = fileName.find('.');
    if(indexOfExtension == string::npos)
        return "";

    fileName = fileName.erase(indexOfExtension);
    fileName += ".cpp";

    implementationName += fileName;

    return implementationName;
}

string FileImplemenationBuilder::getHeaderFileName(const string& headerName) const {
    string filePath = headerName;
    size_t indexOfFileName = filePath.find_last_of('/');
    size_t indexOfEndOfFileName = filePath.find_last_of(".h");

    if(indexOfEndOfFileName == string::npos) {
        return "";
    }

    string fileName = filePath.erase(indexOfEndOfFileName+1);
    if(indexOfFileName == string::npos) {
        return "";
    }

    return filePath.substr(indexOfFileName+1);
}
