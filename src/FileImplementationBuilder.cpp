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
    string headerName = getHeaderFileName(headerFile);
    file << "#include \"" + headerName + "\""; // Add an include with the name of the header file

    size_t extension = headerName.find(".h");
    string className;
    if(extension != string::npos) {
        className = headerName;
        className.erase(extension);
    }

    while(!_validator->endOfStream()) {
        string lineToWrite = _validator->next();
        if(lineToWrite != "") {
            char argument = 97;
            size_t uselessSpace = lineToWrite.find_first_not_of("\t "); // Check if tabs or spaces exist
            if(uselessSpace != string::npos) {
                lineToWrite = lineToWrite.substr(uselessSpace); // If they do, get rid of them.
            }

            bool isAbstract = false;
            for(int i = 0; i < specifiersToCheck.size(); ++i) {
                if(lineToWrite.find(specifiersToCheck[i]) != string::npos) {
                    lineToWrite = lineToWrite.substr(specifiersToCheck[i].size() + 1);
                    if(specifiersToCheck[i] == "virtual") {
                        size_t abstract = lineToWrite.find("= 0");
                        if(abstract != string::npos) {
                            isAbstract = true;
                        }
                    }
                }
            }

            if(isAbstract)
                continue;

            file << "\n\n";

            size_t space = lineToWrite.find(' ');
            size_t paran1 = lineToWrite.find('(');
            size_t paran2 = lineToWrite.find(')');
            string scopeOperator = className + "::";
            string returnType = "";
            if(space != string::npos) {
                if(space < paran1) {
                    lineToWrite.insert(space+1, scopeOperator);
                    returnType = lineToWrite.substr(0, space);
                }
                else
                    lineToWrite.insert(0, scopeOperator);
            }

            else {
                lineToWrite.insert(0, scopeOperator);
            }

            paran1 = lineToWrite.find('(');
            paran2 = lineToWrite.find(')');

            if((paran2 - paran1) > 1) {
                string arg = " ";
                size_t comma = lineToWrite.find(',');
                if(comma != string::npos) {
                    while(comma != string::npos) {
                        arg = " ";
                        arg += argument++;
                        lineToWrite.insert(comma, arg);
                        comma = lineToWrite.find(',', comma + 3);
                    }

                    arg = " ";
                    arg += argument;
                    paran2 = lineToWrite.find(')');
                    lineToWrite.insert(paran2, arg);
                }

                else {
                    arg += argument;
                    lineToWrite.insert(paran2, arg);
                }
            }

            size_t semicolon = lineToWrite.find(';');
            lineToWrite = lineToWrite.erase(semicolon);
            lineToWrite += " {\n\t";
            if(returnType != "" && returnType != "void") {
                if(returnTypes.find(returnType) != returnTypes.end()) {
                    lineToWrite += "return " + returnTypes[returnType] + ";";
                }

                else {
                    lineToWrite += "throw not_implemented();";
                }
            }

            lineToWrite += "\n}";
            file << lineToWrite;
        }
    }

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
