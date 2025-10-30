#include <FrameLog.hpp>
using namespace FrameLog;
#include <iostream>

int main()
{
    Logger logger = NewLogger("Main");
    logger.Tracel("Hello, World!");
    logger.Custom << "Hello World! " << 7534 << "\n";
    std::string rgb = Colors::RGB(100, 100, 100);
    logger.Custom << rgb << "Custom Color! " << "\n";
    logger.Flush();
}