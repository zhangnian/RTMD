#ifndef LOGGER_H_20140302
#define LOGGER_H_20140302


#include <log4cpp/Category.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>


#define LOG_DEBUG(fmt, args...) Logger::Instance()->log_debug(__FILE__, __LINE__, fmt, ##args)
#define LOG_INFO(fmt, args...) Logger::Instance()->log_info(fmt, ##args)
#define LOG_ERROR(fmt, args...) Logger::Instance()->log_error(fmt, ##args)


/**
 * Log4cpp封装
 */
class Logger
{
private:
	Logger();
	~Logger();

public:
	static Logger* Instance()
	{
		if( NULL == m_ins )
		{
			m_ins = new Logger;
		}

		return m_ins;
	}

public:
	void log_debug(const char* file, int line, const char* fmt, ...);

	void log_info(const char* fmt, ...);

	void log_error(const char* fmt, ...);


private:
	log4cpp::RollingFileAppender* m_appender;
	log4cpp::PatternLayout*   m_layout;
	log4cpp::Category* m_category;

	static Logger* m_ins;
};



#endif

