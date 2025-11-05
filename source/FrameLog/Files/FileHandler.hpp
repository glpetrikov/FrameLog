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

        FRAMELOG_API FileHandler(std::string_view Name, FileHandler::WriteType Write = WriteType::Write, FileHandler::ReadType Read = ReadType::Read);
        FRAMELOG_API ~FileHandler();

        FRAMELOG_API bool Write(std::string_view Message);
        FRAMELOG_API bool WriteLine(std::string_view Message);

        FRAMELOG_API std::string FindLine(int Line);

        FRAMELOG_API bool OpenFile(std::string_view Name,
                                   FileHandler::WriteType Writetype = FileHandler::WriteType::Write,
                                   FileHandler::ReadType Readtype = FileHandler::ReadType::Read);
        FRAMELOG_API bool CloseFile();
        FRAMELOG_API bool DeleteFile();
        FRAMELOG_API bool DeleteFile(std::string_view Name);

        FRAMELOG_API bool IsOpen();
        FRAMELOG_API bool Flush();

        FRAMELOG_API std::streamsize SizeFile();
        FRAMELOG_API std::streamsize SizeFile(std::string Name);

        FRAMELOG_API std::string LastFile();

        FRAMELOG_API std::ios::openmode DefineWrite(FileHandler::WriteType Write);
        FRAMELOG_API std::ios::openmode DefineRead(FileHandler::ReadType Read);

    protected:
        std::string LastFileName = "";
        std::fstream File;
    };
}