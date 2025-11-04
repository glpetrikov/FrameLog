#include <FrameLog.hpp>
#include <iostream>

using namespace FrameLog;

int main() {
    Logger logger("Main");
    logger.TraceLine("Hello, World!");
    logger.Custom << "Hello World! " << 7534 << "\n";
    std::string rgb = Colors::RGB(100, 100, 100);
    logger.Custom << rgb << "Custom Color! " << "\n";
    logger.Flush();

    FileHandler File("Test");
    File.Write("Test\n");
}