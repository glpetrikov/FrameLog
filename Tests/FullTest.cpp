#include <FrameLog.hpp>

int main() {

    FrameLog::Logger logger("Main");

    std::string test = "";
    for (int i = 0; i < 15; i++) {
        test += "Test Test";
    }

    // --- Logger -----
    logger.Print("Test");
    logger.Trace("Test");
    logger.Info("Test");
    logger.Warn("Test");
    logger.Error("Test");
    logger.Fatal("Test");
    logger.Custom << "Test" << logger.EndL();

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
    std::string testInput = logger.Read();
    logger.Custom << "Input: " << testInput << logger.EndL();

    // --- FileWriter -----
}