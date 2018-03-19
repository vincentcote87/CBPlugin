#include "FileValidator.h"

#include "logmanager.h"
#include "wx/string.h"
using std::getline;

FileValidator::FileValidator(istream* file) : InterfaceValidator(file) {

}

FileValidator::FileValidator(ifstream* file) {
    _interface = dynamic_cast<ifstream*>(file);
}

FileValidator::FileValidator(const ifstream& file) {
    _interface = new ifstream(file.getloc().name());
}

FileValidator::FileValidator(const string& filename) {
    _file = new ifstream(filename);

    _currentLine = findStartingLine();
    wxString lineNumber = wxString::Format(wxT("%i"), _currentLine);
    Manager::Get()->GetLogManager()->Log(_("currentLine = ") + lineNumber);
}

string FileValidator::next() {
    string nextLine = readLine();
    if(validate(nextLine)) {
        Manager::Get()->GetLogManager()->Log(wxString(nextLine.c_str(), wxConvUTF8) + _(" is valid!"));
        size_t firstLetter = nextLine.find_first_not_of("\t ");
        if(firstLetter == string::npos)
            return "";
        nextLine = nextLine.substr(firstLetter);
        size_t terminatorPos = nextLine.find(';');
        if(terminatorPos == string::npos)
            return "";
        nextLine = nextLine.erase(terminatorPos);
        nextLine += " {\n\t\n}\n\n";
        nextLine = _fileName + "::" + nextLine;
        return nextLine;
    }

    if(nextLine.find("};") != string::npos)
        _endOfFile = true;

    return "";
}

bool FileValidator::validate(const string& str) const {
    if(str.find("public") != string::npos || str.find("protected") != string::npos || str.find("private") != string::npos) {
        Manager::Get()->GetLogManager()->Log(_("Found a p-key word!"));
        return false;
    }

    if(str.find("};") != string::npos) {
        Manager::Get()->GetLogManager()->Log(_("Found end of file"));
        return false;
    }

    if(str == "") {
        Manager::Get()->GetLogManager()->Log(_("String is empty"));
        return false;
    }

    if(str.find('{') != string::npos) {
        Manager::Get()->GetLogManager()->Log(_("Function is implemented"));
        return false;
    }

    return true;
}

string FileValidator::readLine() {
    if(_file->eof())
        return "";
    string line;
    getline(*_file, line);
    Manager::Get()->GetLogManager()->Log(wxString(line.c_str(), wxConvUTF8));
    return line;
}

void FileValidator::setInterface(const string& filename) {
    _file = new ifstream(filename);
    if(!_file->is_open()) {
        Manager::Get()->GetLogManager()->Log(wxString(filename.c_str(), wxConvUTF8));
        return;
    }

    size_t lastDir = filename.find_last_of('/');
    Manager::Get()->GetLogManager()->Log(_("filename: ") + wxString(filename.c_str(), wxConvUTF8));
    if(lastDir != string::npos) {
        _fileName = filename.substr(lastDir+1);
    }

    size_t extension = _fileName.find_last_of('.');

    if(extension != string::npos) {
        _fileName = _fileName.erase(extension);
    }
}

bool FileValidator::endOfStream() const {
    return _endOfFile;
}

int FileValidator::findStartingLine() {
    //search for the class keyword
    if(!_file->is_open()) {
        Manager::Get()->GetLogManager()->Log(_("File is not open!"));
        return -1;
    }

    int lineNumber = 1;
    string current = "";
    while(!getline(*_file, current).eof()) {
        Manager::Get()->GetLogManager()->Log(wxString(current.c_str(), wxConvUTF8));
        if(current.find("class") != string::npos) {
            return lineNumber;
        }
        ++lineNumber;
    }

    return -1;
}

FileValidator& FileValidator::operator=(const FileValidator& rhs) {
    if(rhs._interface == this->_interface)
        return *this;

    if(_interface == nullptr)
        delete _interface;

    _interface = rhs._interface;
}
