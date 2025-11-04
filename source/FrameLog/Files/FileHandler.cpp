//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include <fstream>

#include "Common.hpp"
#include "FileHandler.hpp"

namespace FrameLog {
    FileHandler::FileHandler(std::string_view Name, FileHandler::WriteType Write, FileHandler::ReadType Read) {
        std::ios::openmode readType = std::ios::in;
        std::ios::openmode writeType = std::ios::app;

        writeType = DefineWrite(Write);
        readType = DefineRead(Read);

        File = std::fstream(std::string(Name), readType | writeType);
    }

    FileHandler::~FileHandler() {
        if (File && File.is_open()) {
            File.close();
        }
    }

    bool FileHandler::Write(std::string_view Message) {
        if (File && File.is_open()) {
            File << Message;
            return true;
        } else {
            return false;
        }
    }

    bool FileHandler::WriteLine(std::string_view Message) {
        if (File && File.is_open()) {
            File << Message << '\n';
            return true;
        } else {
            return false;
        }
    }

    std::string FileHandler::FindLine(int TargetLine) {

        TargetLine++;

        if (!File || !File.is_open()) {
            return "File Not Opened";
        }

        File.clear();
        File.seekg(0);

        std::string Line;
        int CurrentLine = 1;

        while (std::getline(File, Line)) {
            if (CurrentLine == TargetLine) {
                return Line;
            }
            CurrentLine++;
        }
        return "Not find target String";
    }

    bool FileHandler::OpenFile(std::string_view Name, FileHandler::WriteType Writetype, FileHandler::ReadType Readtype) {
        if (File && File.is_open()) {
            File.close();
        }

        std::ios::openmode writeType = DefineWrite(Writetype);
        std::ios::openmode readType = DefineRead(Readtype);

        File = std::fstream(std::string(Name), readType | writeType);
        this->LastFileName = Name;

        if (!File) {
            return false;
        }

        return true;
    }

    bool FileHandler::CloseFile() {
        if (!File.is_open()) {
            return false;
        } else {
            File.close();
        }
        return true;
    }

    bool FileHandler::DeleteFile() {
        if (std::remove(LastFileName.c_str()) == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool FileHandler::DeleteFile(std::string_view Name) {
        if (std::remove(std::string(Name).c_str()) == 0) {
            return true;
        } else {
            return false;
        }
    }

    bool FileHandler::IsOpen() {
        if (this->File.is_open()) {
            return true;
        } else {
            return false;
        }
    }

    bool FileHandler::Flush() {
        if (File.flush()) {
            return true;
        } else {
            return false;
        }
    }

    std::streamsize FileHandler::SizeFile() {
        if (!File.is_open()) {
            return -1;
        }
        return File.tellg();
    }

    std::streamsize FileHandler::SizeFile(std::string Name) {
        std::ifstream file(Name, std::ios::binary | std::ios::ate);
        if (!file.is_open()) {
            return -1;
        }
        return file.tellg();
    }

    std::string FileHandler::LastFile() {
        return this->LastFileName;
    }

    std::ios::openmode FileHandler::DefineWrite(FileHandler::WriteType Write) {

        switch (Write) {
            case FileHandler::WriteType::Write:
                return std::ios::app | std::ios::binary;
                break;
            case FileHandler::WriteType::ReWrite:
                return std::ios::out | std::ios::trunc | std::ios::binary;
                break;
            default:
                return std::ios::app | std::ios::binary;
                break;
        }
    }

    std::ios::openmode FileHandler::DefineRead(FileHandler::ReadType Read) {

        switch (Read) {
            case FileHandler::ReadType::Read:
                return std::ios::in | std::ios::binary;
                break;
            default:
                return std::ios::in;
                break;
        }
    }
}