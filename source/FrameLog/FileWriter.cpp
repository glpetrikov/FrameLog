//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================
#include <cstdio>
#include <fstream>

#include "Common.hpp"
#include "FileWriter.hpp"

namespace FrameLog {
    FileWriter::FileWriter(std::string Name, TypeWrite Type) {
        if (Type == TypeWrite::ReWrite) {
            this->File = new std::ofstream(Name, std::ios_base::out);
            this->LastFileName = Name;
        } else if (Type == TypeWrite::Write) {
            this->File = new std::ofstream(Name, std::ios_base::app);
            this->LastFileName = Name;
        }
    }

    FileWriter::FileWriter(const char *Name, TypeWrite Type) {
        if (Type == TypeWrite::ReWrite) {
            this->File = new std::ofstream(Name, std::ios_base::out);
            this->LastFileName = Name;
        } else if (Type == TypeWrite::Write) {
            this->File = new std::ofstream(Name, std::ios_base::app);
            this->LastFileName = Name;
        }
    }

    FileWriter::~FileWriter() {
        this->File->flush();
        this->File->close();
        delete this->File;
    }

    int FileWriter::Write(std::string Text) {
        if (!File) {
            return -1;
        }
        if (File && File->is_open()) {
            (*File) << Text;
            return 0;
        }

        return -1;
    }

    int FileWriter::WriteLine(std::string Text) {
        if (!File) {
            return -1;
        }
        if (File && File->is_open()) {
            (*File) << Text << "\n";
            return 0;
        }
        return -1;
    }

    int FileWriter::CloseFile() {
        if (!File) {
            return -1;
        }
        if (File->is_open()) {
            File->flush();
            File->close();
            return 0;
        }
        return -1;
    }

    int FileWriter::DeleteFile(std::string Name) {
        if (std::remove(Name.c_str()) == 0) {
            return 0;
        } else {
            return -1;
        }
    }

    int FileWriter::DeleteFile(bool DeleteLastFileName) {
        if (this->File != nullptr && this->File->is_open()) {
            this->File->close();
            delete File;
            File = nullptr;
        }
        if (std::remove(this->LastFileName.c_str()) == 0) {
            if (DeleteLastFileName == true) {
                this->LastFileName.clear();
            }
            return 0;
        } else {
            return -1;
        }
    }

    bool FileWriter::IsOpen() {
        if (this->File->is_open()) {
            return true;
        } else if (!this->File->is_open()) {
            return false;
        } else {
            return false;
        }
    }

    int FileWriter::OpenFile(std::string Name, TypeWrite Type) {
        if (File && File->is_open()) {
            File->close();
        }
        if (File) {
            delete File;
            File = nullptr;
        }

        if (Type == TypeWrite::ReWrite) {
            this->File = new std::ofstream(Name, std::ios_base::out);
            this->LastFileName = Name;
        } else if (Type == TypeWrite::Write) {
            this->File = new std::ofstream(Name, std::ios_base::app);
            this->LastFileName = Name;
        }

        return 0;
    }

    int FileWriter::Flush() {
        if (!File) {
            return -1;
        }
        File->flush();
        return 0;
    }

    std::string FileWriter::LastFile() { return LastFileName; }

    std::streamsize FileWriter::SizeFile(const std::string &filename) {
        std::ifstream file(filename, std::ios::binary | std::ios::ate);
        if (!file.is_open()) {
            return -1;
        }
        return file.tellg();
    }
} // namespace FrameLog