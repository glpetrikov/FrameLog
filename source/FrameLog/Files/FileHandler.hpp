//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#pragma once

#include <fstream>
#include <sstream>

#include "../Common.hpp"

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

        FRAMELOG_API FileHandler(std::string_view Name,
                                 FileHandler::WriteType Write = WriteType::Write,
                                 FileHandler::ReadType Read = ReadType::Read);
        FRAMELOG_API ~FileHandler();

        // --- FIleWriter -----

        FRAMELOG_API bool Write(std::string_view Message);
        FRAMELOG_API bool WriteLine(std::string_view Message);

        // --- FileReader -----

        FRAMELOG_API std::string FindLine(int TargetLine);
        FRAMELOG_API std::string FindLine(int TargetLine, std::string FileName);
        FRAMELOG_API std::string FindLine(int TargetLine, std::fstream &file);

        FRAMELOG_API std::string ReadFile();
        FRAMELOG_API std::string ReadFile(std::string fIleName);
        FRAMELOG_API std::string ReadFile(std::fstream &file);

        // --- Tools -----

        FRAMELOG_API bool SetFile(std::string_view Name,
                                  WriteType Writetype = WriteType::Write,
                                  ReadType Readtype = ReadType::Read);
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