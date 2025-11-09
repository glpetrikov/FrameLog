#include <FrameLog.hpp>
#include <iostream>

using namespace FrameLog;

int main() {
    FileHandler File1("Test.txt");
    File1.Write("Test");
    File1.WriteLine("???");
    File1.CloseFile();

    FileHandler File2("Test2.txt", FileHandler::WriteType::Write);
    File2.Write("Test");
    File2.WriteLine("???");
    File2.CloseFile();

    FileHandler File3("Test2.txt", FileHandler::WriteType::ReWrite);
    File3.Write("Rewrited!");
    File3.CloseFile();

    File3.SetFile("Test.txt", FileHandler::WriteType::ReWrite);

    for (int i = 0; i < 12; i++) {
        File3.WriteLine("NewLine");
    }

    File3.WriteLine("Request Data");

    for (int i = 0; i < 12; i++) {
        File3.WriteLine("NewLine");
    }
    File3.CloseFile();

    std::string dataFile = File3.FindLine(13);
    Logger logger("Main");
    logger.Custom << dataFile << logger.EndL();
}