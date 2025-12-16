#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void* FL_Logger;

/* lifetime */
FL_Logger fl_logger_create(const char* name);
void fl_logger_destroy(FL_Logger logger);

/* config */
void fl_logger_set_min_level(FL_Logger logger, int level);
void fl_logger_set_pattern(FL_Logger logger, const char* pattern);

/* logging */
void fl_log_trace(FL_Logger logger, const char* msg);
void fl_log_print(FL_Logger logger, const char* msg);
void fl_log_info(FL_Logger logger, const char* msg);
void fl_log_warn(FL_Logger logger, const char* msg);
void fl_log_error(FL_Logger logger, const char* msg);
void fl_log_fatal(FL_Logger logger, const char* msg);

/* flush */
void fl_logger_flush(FL_Logger logger);
void fl_logger_flush_file(FL_Logger logger);

#ifdef __cplusplus
}
#endif
