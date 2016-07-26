#include "stdafx.h"
#include "log.h"
#include "Poco/PatternFormatter.h"
#include "Poco/FormattingChannel.h"
#include "Poco/FileChannel.h"
#include "Poco/AutoPtr.h"
#include "Poco/Path.h"

//using Poco::Logger;
//using Poco::FileChannel;
//using Poco::AutoPtr;
//using Poco::PatternFormatter;
//using Poco::FormattingChannel;


namespace Loggering
{

	void Logger_initiation()
	{
		Poco::AutoPtr<Poco::FileChannel> file_channel(new Poco::FileChannel());
		file_channel->setProperty("rotation", "10M");
		file_channel->setProperty("archive", "timestamp");
		std::string strpath = Poco::Path::current();
		strpath.append("log\\Downloader.log");
		file_channel->setProperty("path", strpath);		
		Poco::AutoPtr<Poco::PatternFormatter> pattern_formatter(new Poco::PatternFormatter("%Y-%m-%d %H:%M:%S %s [%p] %U(%u): %t"));
		Poco::AutoPtr<Poco::FormattingChannel> formatter_channle(new Poco::FormattingChannel(pattern_formatter, file_channel));
		Poco::Logger::root().setChannel(formatter_channle);
		///- finish logger initiation
	}

	void Setup_logger()
	{
		static bool b_setup = false;     // only allow run once time 
		if (!b_setup)
		{
			b_setup = true;
			Logger_initiation();
		}
	}

	void log_information(char *format, ...)
	{
		char buffer[1024] = { 0 };
		va_list aptr;
		va_start(aptr, format);
		vsprintf(buffer, format, aptr);
		va_end(aptr);
		poco_information(logger_handle, buffer);
	}

	void log_error(char *format, ...)
	{
		char buffer[1024] = { 0 };
		va_list aptr;
		va_start(aptr, format);
		vsprintf(buffer, format, aptr);
		va_end(aptr);
		poco_error(logger_handle, buffer);
	}
}