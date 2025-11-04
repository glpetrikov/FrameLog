//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <fstream>

#include "Common.hpp"

namespace FrameLog {
    class FileHandler {
    public:
        enum class WriteType {
            Write,   // app
            ReWrite, // out
        };
        enum class ReadType {
            Read
        };

        FileHandler(std::string_view Name, FileHandler::WriteType Write = WriteType::Write, FileHandler::ReadType Read = ReadType::Read);
        ~FileHandler();

        bool Write(std::string_view Message);
        bool WriteLine(std::string_view Message);

        std::string FindLine(int Line);

        bool OpenFile(std::string_view Name,
                      FileHandler::WriteType Writetype = FileHandler::WriteType::Write,
                      FileHandler::ReadType Readtype = FileHandler::ReadType::Read);
        bool CloseFile();
        bool DeleteFile();
        bool DeleteFile(std::string_view Name);

        bool IsOpen();
        bool Flush();

        std::streamsize SizeFile();
        std::streamsize SizeFile(std::string Name);

        std::string LastFile();

        std::ios::openmode DefineWrite(FileHandler::WriteType Write);
        std::ios::openmode DefineRead(FileHandler::ReadType Read);

    protected:
        std::string LastFileName = "";
        std::fstream File;
    };
}