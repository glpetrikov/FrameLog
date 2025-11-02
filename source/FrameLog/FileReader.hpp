#include "Common.hpp"

namespace FrameLog {
    class FileReader {
        std::string LastFileName;
        std::ifstream *File;

    public:
        FL_API FileReader(std::string Name);
        FL_API FileReader(const char *Name);
        FL_API ~FileReader();

        FL_API std::string LastFile();

        FL_API void OpenFile(std::string Name);
        FL_API void CloseFile();

        FL_API std::string FindLine(int TargetLine);

        FL_API std::string ReadFile();
        FL_API std::string ReadFile(std::string Name);
    };
}