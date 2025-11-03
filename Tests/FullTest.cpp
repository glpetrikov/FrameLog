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

    logger.Printl("Test");
    logger.Tracel("Test");
    logger.Infol("Test");
    logger.Warnl("Test");
    logger.Errorl("Test");
    logger.Fatall("Test");

    logger.Add("Test");
    logger.Add('?');
    logger.Add("\n");
    logger.Flush();
    std::string testInput = logger.Read();
    logger.Custom << "Input: " << testInput << logger.EndL();

    // --- FileWriter -----
}