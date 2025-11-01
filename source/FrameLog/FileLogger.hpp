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
        std::string LastFileName;

    public:
        // --- Constructors -----
        FileWriter(std::string Name, TypeWrite Type = TypeWrite::Write);
        FileWriter(const char *Name, TypeWrite Type = TypeWrite::Write);
        ~FileWriter();

        // --- Writes -----
        int Write(std::string Text);
        int WriteLine(std::string Text);

        // --- Tools -----
        bool IsOpen();
        int OpenFile(std::string Name, TypeWrite Type);
        int CloseFile();
        int DeleteFile(std::string Name);
        int DeleteFile(bool DeleteLastFileName = false);
        int Flush();

        // --- Sizes -----
        std::string LastFile();
        std::streamsize SizeFile(const std::string& filename);
    };
    enum class TypeRead
    {
        Read,
    };
    // class FileReader
    // {
    // public:
    //     FileReader(std::string Name, TypeRead = TypeRead::Read);
    //     FileReader(const char *Name, TypeRead = TypeRead::Read);
    //     ~FileReader();
    //
    //     int ReadLine(int Line);
    // };
}