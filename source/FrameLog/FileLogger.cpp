//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================
#include <fstream>

#include "Common.hpp"
#include "FileLogger.hpp"

namespace FrameLog
{
    FileWriter::FileWriter(std::string Name, TypeWrite Type)
    {
        if (Type == TypeWrite::ReWrite)
        {
            this->File = new std::ofstream(Name, std::ios_base::out);
        }
        else if (Type == TypeWrite::Write)
        {
            this->File = new std::ofstream(Name, std::ios_base::app);
        }
    }
    FileWriter::FileWriter(const char *Name, TypeWrite Type)
    {
        if (Type == TypeWrite::ReWrite)
        {
            this->File = new std::ofstream(Name, std::ios_base::out);
        }
        else if (Type == TypeWrite::Write)
        {
            this->File = new std::ofstream(Name, std::ios_base::app);
        }
    }
    FileWriter::~FileWriter()
    {
        this->File->flush();
        this->File->close();
        delete this->File;
    }
    int FileWriter::Write(std::string Text)
    {
        if (File && File->is_open())
        {
            (*File) << Text;
            return 0;
        }

        return -1;
    }
    int FileWriter::WriteLine(std::string Text)
    {
        if (File && File->is_open())
        {
            (*File) << Text << "\n";
            return 0;
        }
        return -1;
    }

    int FileWriter::CloseFile()
    {
        if (File->is_open())
        {
            File->close();
            return 0;
        }
        return -1;
    }
}