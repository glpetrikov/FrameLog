#include <fstream>
#include <sstream>

#include "Common.hpp"
#include "FileReader.hpp"

namespace FrameLog {

    FileReader::FileReader(std::string Name) {
        File = new std::ifstream(Name);
        this->LastFileName = Name;
    }

    FileReader::FileReader(const char *Name) {
        File = new std::ifstream(std::string(Name));
        this->LastFileName = std::string(Name);
    }

    FileReader::~FileReader() {
        File->close();
        delete File;
    }

    std::string FileReader::LastFile() {
        return LastFileName;
    }

    void FileReader::OpenFile(std::string Name) {
        if (File && File->is_open()) {
            File->close();
        }
        delete File;
        File = nullptr;

        this->File = new std::ifstream(Name);
        this->LastFileName = Name;

        return;
    }

    void FileReader::CloseFile() {
        if (!File->is_open()) {
            return;
        } else {
            File->close();
        }
    }

    std::string FileReader::FindLine(int TargetLine) {

        TargetLine -= 1;

        if (!File || !File->is_open()) {
            return "File Not Opened";
        }

        File->clear();
        File->seekg(0);

        std::string Line;
        int CurrentLine = 0;

        while (std::getline(*File, Line)) {
            if (CurrentLine == TargetLine) {
                return Line;
            }
            CurrentLine++;
        }
        return "Not Find target String";
    }

    std::string FileReader::ReadFile() {
        if (!File || !File->is_open()) {
            return "";
        }

        std::stringstream temp;
        temp << File->rdbuf();
        std::string data = temp.str();

        return data;
    }

    std::string FileReader::ReadFile(std::string Name) {
        std::ifstream TempFile(Name);
        if (!TempFile || !TempFile.is_open()) {
            return "";
        }

        std::stringstream temp;
        temp << TempFile.rdbuf();
        std::string data = temp.str();
        return data;
    }
}