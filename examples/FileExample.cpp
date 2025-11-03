#include <FrameLog.hpp>
#include <iostream>

using namespace FrameLog;

int main() {
    FileWriter Writer1("Test.txt");
    Writer1.Write("Test");
    Writer1.WriteLine("???");
    Writer1.CloseFile();

    FileWriter Writer2("Test2.txt", TypeWrite::Write);
    Writer2.Write("Test");
    Writer2.WriteLine("???");
    Writer2.CloseFile();

    FileWriter Writer3("Test2.txt", TypeWrite::ReWrite);
    Writer3.Write("Rewrited!");
    Writer3.CloseFile();

    Writer3.OpenFile("Test.txt", TypeWrite::ReWrite);

    for (int i = 0; i < 12; i++) {
        Writer3.WriteLine("NewLine");
    }

    Writer3.WriteLine("Request Data");

    for (int i = 0; i < 12; i++) {
        Writer3.WriteLine("NewLine");
    }
    Writer3.CloseFile();

    FileReader Reader("Test.txt");
    std::string dataFile = Reader.FindLine(13);
    Logger logger("Main");
    logger.Custom << dataFile << logger.EndL();
}