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

}

bool FileValidator::validate(bool next) const {

}

string FileValidator::readLine() {
    string line;
    getline(*_interface, line);


}

void FileValidator::setInterface(const string& filename) {
    _file = new ifstream(filename);
        if(!_file->is_open()) {
        Manager::Get()->GetLogManager()->Log(wxString(filename.c_str(), wxConvUTF8));
        return;
    }
    _currentLine = findStartingLine();
    wxString lineNumber = wxString::Format(wxT("%i"), _currentLine);
    Manager::Get()->GetLogManager()->Log(_("currentLine = ") + lineNumber);
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
        if(current.find("class") != 0) {
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
