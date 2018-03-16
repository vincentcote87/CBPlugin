#include "FileValidator.h"
FileValidator::FileValidator(istream* file) : InterfaceValidator(file) {

}

FileValidator::FileValidator(fstream* file) {
    _interface = file;
}

FileValidator::FileValidator(const fstream& file) {
    _interface = new fstream(file.getloc().name());
}

string FileValidator::next() {

}

bool FileValidator::validate(bool next) const {

}

string FileValidator::readLine() {
    string line;
    std::getline(*_interface, line);


}

int FileValidator::findStartingLine() {

}

FileValidator& FileValidator::operator=(const FileValidator& rhs) {
    if(rhs._interface == this->_interface)
        return *this;

    if(_interface == nullptr)
        delete _interface;

    _interface = rhs._interface;
}
