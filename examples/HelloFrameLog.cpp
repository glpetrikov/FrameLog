#include "FrameLog/FrameLog.h"

using namespace FrameLog;

int main()
{
	Logger logger("Main");

	logger << "Hello, FrameLog-" << FL_VERSION << "-" << FL_STATUS << logger.EndL();
	logger << "FrameLog Size: " << FL_SIZE << logger.EndL();
}
