#include <FrameLog/FrameLog.h>
#include <iostream>

int main() {

    FrameLog::Logger logger("Main");

    std::string test = "";
    for (int i = 0; i < 15; i++) {
        test += "Test Test";
    }
    int formattest = 42;

    logger.TraceLine(logger.Format("Test Format, Int = {}", formattest));

    // --- Logger -----
    logger.Print("Test\n");
    logger.Trace("Test\n");
    logger.Info("Test\n");
    logger.Warn("Test\n");
    logger.Error("Test\n");
    logger.Fatal("Test\n");
    logger.custom << "Test" << logger.EndL();

    logger.custom << "==============================" << logger.EndL();

    logger.PrintLine("Test");
    logger.TraceLine("Test");
    logger.InfoLine("Test");
    logger.WarnLine("Test");
    logger.ErrorLine("Test");
    logger.FatalLine("Test");

    logger.Add("Test");
    logger.Add('?');
    logger.Add("\n");
    logger.Flush();
    logger.FlushFile();

    
    std::string testInput = logger.Read();
    logger.custom << "Input: " << testInput << logger.EndL();
    logger.Flush();

    // --- FileHandler -----
    FrameLog::FileHandler File("log.txt", FrameLog::FileHandler::WriteType::ReWrite, FrameLog::FileHandler::ReadType::Read);

    // --- Writes -----
    File.Write("Test");

    File.WriteLine("TestLine");
    File.WriteLine("TestLine");

    // --- Opens -----
    File.CloseFile();
    File.SetFile("loopTest.txt", FrameLog::FileHandler::WriteType::ReWrite);

    for (int i = 0; i <= 99; i++) {
        File.WriteLine(std::string("Test in loop is 100 Messages"));
    }
    File.WriteLine("End");

    // --- Read -----
    std::string line100 = File.FindLine(100);
    std::cout << line100 << '\n';

    // ---Delete -----
    File.CloseFile();
    File.SetFile("deletedFile.txt");
    File.DeleteFile();

    File.SetFile("deletedFile2.txt");
    File.CloseFile();
    File.SetFile("log.txt");
    File.DeleteFile("deletedFile2.txt");

    // ---Tools -----
    std::cout << File.IsOpen() << '\n';

    std::cout << "LastFile: " << File.LastFile() << '\n';

    File.Flush();
    //--- Crash Tests -----
    File.SetFile("CrashTest.txt");
    File.DeleteFile("CrashTest.txt");
    File.DeleteFile("CrashTest.txt");
    File.DeleteFile("CrashTest.txt");

    File.SetFile("CrashTest.txt");
    File.CloseFile();
    File.CloseFile();
}