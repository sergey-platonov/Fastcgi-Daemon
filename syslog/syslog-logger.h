#ifndef _FASTCGI_SYSLOG_LOGGER_H_
#define _FASTCGI_SYSLOG_LOGGER_H_

#include "fastcgi2/logger.h"
#include "fastcgi2/component.h"
#include "fastcgi2/handler.h"

#include <string>

namespace fastcgi
{

class SyslogLogger : virtual public Logger, virtual public Component, virtual public Handler
{
public:
	SyslogLogger(ComponentContext *context);
	virtual ~SyslogLogger();

	virtual void onLoad();
	virtual void onUnload();

	virtual void handleRequest(Request *request, HandlerContext *handlerContext);
	
protected:
	virtual void log(const Level level, const char *format, va_list args);
	virtual void setLevelInternal(const Level level);
	virtual void rollOver();

private:
	static int toSyslogPriority(const Level level);

private:
	std::string ident_;
	int priority_;
};

} // namespace fastcgi

#endif // _FASTCGI_SYSLOG_LOGGER_H_
