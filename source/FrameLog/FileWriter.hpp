//============================================================
// FrameLog - MIT License (c) 2025 Gleb Petrikov
//============================================================

#include "Common.hpp"

namespace FrameLog {
    enum class TypeWrite {
        ReWrite,
        Write,
    };

    class FileWriter {

        std::ofstream *File;
        std::string LastFileName;

    public:
        // --- Constructors -----
        FL_API FileWriter(std::string Name, TypeWrite Type = TypeWrite::Write);
        FL_API FileWriter(const char *Name, TypeWrite Type = TypeWrite::Write);
        FL_API ~FileWriter();

        // --- Writes -----
        FL_API int Write(std::string Text);
        FL_API int WriteLine(std::string Text);

        // --- Tools -----
        FL_API bool IsOpen();
        FL_API int OpenFile(std::string Name, TypeWrite Type = TypeWrite::Write);
        FL_API int CloseFile();
        FL_API int DeleteFile(std::string Name);
        FL_API int DeleteFile(bool DeleteLastFileName = false);
        FL_API int Flush();

        // --- Sizes -----
        FL_API std::string LastFile();
        FL_API std::streamsize SizeFile(const std::string &filename);
    };
}