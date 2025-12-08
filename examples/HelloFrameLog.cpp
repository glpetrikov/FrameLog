#include "FrameLog.hpp"

using namespace FrameLog;

int main() {
    Logger logger("Main");

    logger.custom << "Hello, FrameLog-" << FL_VERSION << "-" << FL_STATUS << logger.EndL();
    logger.custom << "FrameLog Size: " << FL_SIZE << logger.EndL();
}