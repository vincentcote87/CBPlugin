#include "FileValidator.h"

FileValidator::FileValidator(fstream* file) : InterfaceValidator(file) { }

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
