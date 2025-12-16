#include "FrameLog/framelog_c.h"
#include "FrameLog/Logger.h"

extern "C" {

FL_Logger fl_logger_create(const char* name) { return new FrameLog::Logger(name ? name : ""); }

void fl_logger_destroy(FL_Logger logger) { delete static_cast<FrameLog::Logger*>(logger); }

void fl_logger_set_min_level(FL_Logger logger, int level)
{
	if (!logger)
		return;
	static_cast<FrameLog::Logger*>(logger)->SetMinimalLogLevel(static_cast<FrameLog::LogLevel>(level));
}

void fl_logger_set_pattern(FL_Logger logger, const char* pattern)
{
	if (!logger || !pattern)
		return;
	static_cast<FrameLog::Logger*>(logger)->SetPattern(pattern);
}

void fl_log_trace(FL_Logger logger, const char* msg)
{
	if (!logger || !msg)
		return;
	static_cast<FrameLog::Logger*>(logger)->Trace(msg);
}

void fl_log_print(FL_Logger logger, const char* msg)
{
	if (!logger || !msg)
		return;
	static_cast<FrameLog::Logger*>(logger)->Print(msg);
}

void fl_log_info(FL_Logger logger, const char* msg)
{
	if (!logger || !msg)
		return;
	static_cast<FrameLog::Logger*>(logger)->Info(msg);
}

void fl_log_warn(FL_Logger logger, const char* msg)
{
	if (!logger || !msg)
		return;
	static_cast<FrameLog::Logger*>(logger)->Warn(msg);
}

void fl_log_error(FL_Logger logger, const char* msg)
{
	if (!logger || !msg)
		return;
	static_cast<FrameLog::Logger*>(logger)->Error(msg);
}

void fl_log_fatal(FL_Logger logger, const char* msg)
{
	if (!logger || !msg)
		return;
	static_cast<FrameLog::Logger*>(logger)->Fatal(msg);
}

void fl_logger_flush(FL_Logger logger)
{
	if (!logger)
		return;
	static_cast<FrameLog::Logger*>(logger)->Flush();
}

void fl_logger_flush_file(FL_Logger logger)
{
	if (!logger)
		return;
	static_cast<FrameLog::Logger*>(logger)->FlushFile();
}
}
