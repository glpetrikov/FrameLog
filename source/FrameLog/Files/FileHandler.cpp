//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include <fstream>

#include "../Common.hpp"
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

    // ==============================
    // FileWriter
    // ==============================

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

    // ==============================
    // FileReader
    // ==============================

    int FileHandler::FindLine(std::string target) {
        std::string fileData = ReadAll();

        if (fileData.find(target) != std::string::npos) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int FileHandler::FindLine(std::string target, std::string FileName) {
        std::string fileData = ReadAll(FileName);

        if (fileData.find(target) != std::string::npos) {
            return 1;
        }
        else {
            return 0;
        }
    }
    int FileHandler::FindLine(std::string target, std::fstream &file) {
        std::string fileData = ReadAll(file);

        if (fileData.find(target) != std::string::npos) {
            return 1;
        }
        else {
            return 0;
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

    std::string FileHandler::FindLine(int TargetLine, std::string FileName) {
        std::fstream file(FileName);
        TargetLine++;

        if (!file || !file.is_open()) {
            return "File Not Opened";
        }

        file.clear();
        file.seekg(0);

        std::string Line;
        int CurrentLine = 1;

        while (std::getline(file, Line)) {
            if (CurrentLine == TargetLine) {
                return Line;
            }
            CurrentLine++;
        }
        return "Not find target String";
    }

    std::string FileHandler::FindLine(int TargetLine, std::fstream &file) {
        TargetLine++;

        if (!file || !file.is_open()) {
            return "File Not Opened";
        }

        file.clear();
        file.seekg(0);

        std::string Line;
        int CurrentLine = 1;

        while (std::getline(file, Line)) {
            if (CurrentLine == TargetLine) {
                return Line;
            }
            CurrentLine++;
        }
        return "Not find target String";
    }

    std::string FileHandler::ReadAll() {
        std::ostringstream buffer;
        buffer << this->File.rdbuf();
        return buffer.str();
    }

    std::string FileHandler::ReadAll(std::fstream &file) {
        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    std::string FileHandler::ReadAll(std::string fileName) {
        std::fstream file(fileName);
        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    // ==============================
    // Tools
    // ==============================

    bool FileHandler::SetFile(std::string_view Name, FileHandler::WriteType Writetype, FileHandler::ReadType Readtype) {
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
        if(!File){
            return false;
        }
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