#ifndef	ICONFIG_H
#define	ICONFIG_H

#include <set>
#include "iniparser.h"

class IConfig
{
protected:
	std::map<std::string, std::map<std::string, std::string> > settings;

	static IConfig* _self;
	IConfig(){}
	virtual ~IConfig(){ IConfig::DeleteInstance(); }

public:
	static IConfig* Instance()
	{
		if(!_self)
		{
			_self = new IConfig();
			IniParser parser((char*)"config.ini");
			_self->settings = parser.getAll();
		}
		return _self;
	}

	std::string get(std::string section, std::string entry)
	{
		return _self->settings[section][entry];
	}

	static bool DeleteInstance()
	{
		if(_self)
		{
			delete _self;
			_self = 0;
			return true;
		}
		return false;
	}
};

IConfig* IConfig::_self = 0;


#endif
