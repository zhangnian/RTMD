#include <string.h>


#include "logger.h"


static const int MAX_LOG_FILE_SIZE  = 1024 * 1024 * 10;		 // 滚动日志的最大大小
static const int MAX_LOG_FILE_COUNT = 10;					 // 滚动日志的最大份数


static char g_szLogBuff[512];
static char g_szLogBuffFuncionLine[1024];


Logger* Logger::m_ins = NULL;

Logger::Logger()
{
	m_layout = new log4cpp::PatternLayout();
    m_layout->setConversionPattern("%d: %p : %m%n");

	m_appender = new log4cpp::RollingFileAppender("RollingFileAppender", "./rollwxb.log", 
		MAX_LOG_FILE_SIZE, MAX_LOG_FILE_COUNT);
	m_appender->setLayout(m_layout);
	

	m_category = &log4cpp::Category::getInstance("Category");
	m_category->setAdditivity(false);
	m_category->setAppender(m_appender);
	m_category->setPriority(log4cpp::Priority::DEBUG);
}

Logger::~Logger()
{
	delete m_layout;
	delete m_appender;
	delete m_category;
}


void Logger::log_debug(const char* file, int line, const char* fmt, ...)
{
	memset(g_szLogBuff, 0, sizeof(g_szLogBuff));

    va_list vl;
    va_start(vl, fmt);
    ::vsnprintf(g_szLogBuff, sizeof(g_szLogBuff), fmt, vl);
    va_end(vl);

    memset(g_szLogBuffFuncionLine, 0, sizeof(g_szLogBuffFuncionLine));
    snprintf(g_szLogBuffFuncionLine, sizeof(g_szLogBuffFuncionLine),
        "[%s:%d]%s", file, line, g_szLogBuff);

    m_category->debug(g_szLogBuffFuncionLine);
}


void Logger::log_info(const char* fmt, ...)
{
	memset(g_szLogBuff, 0, sizeof(g_szLogBuff));

    va_list vl;
    va_start(vl, fmt);
    vsnprintf(g_szLogBuff, sizeof(g_szLogBuff), fmt, vl);
    va_end(vl);

    m_category->info(g_szLogBuff);
}


void Logger::log_error(const char* fmt, ...)
{
	memset(g_szLogBuff, 0, sizeof(g_szLogBuff));

    va_list vl;
    va_start(vl, fmt);
    vsnprintf(g_szLogBuff, sizeof(g_szLogBuff), fmt, vl);
    va_end(vl);

    m_category->error(g_szLogBuff);
}
