#include "FrameLog.hpp"

using namespace FrameLog;

int main() {
    Logger logger("Main");

    logger.Custom << "Hello, FrameLog-" << FL_VERSION << "-" << FL_STATUS << logger.EndL();
    logger.Custom << "FrameLog Size: " << FL_SIZE << logger.EndL();
}