//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include "Common.hpp"

namespace FrameLog
{
    enum class TypeWrite
    {
        ReWrite,
        Write,
    };
    class FileWriter
    {

        std::ofstream *File;

    public:
        FileWriter(std::string Name, TypeWrite Type = TypeWrite::Write);
        FileWriter(const char *Name, TypeWrite Type = TypeWrite::Write);
        ~FileWriter();

        int Write(std::string Text);
        int WriteLine(std::string Text);

        // int OpenFIle(std::string Name);
        int CloseFile();
    };
    enum class TypeRead
    {
        Read,
    };
    // class FileReader
    // {
    // public:
    //     FileReader(std::string Name);
    //     FileReader(const char *Name);
    //     ~FileReader();

    //     int Read(int Line);
    //     int ReadLine(int Line);
    // };
}