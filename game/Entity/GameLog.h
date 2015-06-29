#pragma once
#include "../GameTool/GameHeadConfig.h"
#include "Timer.h"
#include "../GameTool/GamePlatform.h"
class Log
{
protected:
	std::ofstream	m_File;
	bool			m_AddTimestamp;	// ʹ��ʱ���
	bool			m_DebugPrint;	// debugģʽ,print
	bool			m_HasCache;
	TickCounter		m_UpdateTimer;
public:
	Log(const string& fileName, int openMode = ios::out, bool addTimestamp = true, bool debugPrint = true);
	~Log();

	void Write(const char* msg);

	void Update(uint delta);
};

class LogMgr
{
protected:
	typedef map<string, Log*>	LogMap;
	LogMap	m_Logs;
	Log*	m_DefaultLog;

	static bool s_UseCache;					// �Ƿ�ʹ�û���
	static const int s_MaxLogLen = 16 * 1024;	// ������־��󳤶�
public:
	LogMgr();
	~LogMgr();

	SINGLETON_MODE(LogMgr);

	static bool IsUseCache() { return s_UseCache; }
	static void SetUseCache(bool useCache) { s_UseCache = useCache; }

	void AddLog(const string& fileName, int openMode = ios::out, bool addTimestamp = true, bool debugPrint = true);

	void LogFile(const string& fileName, const char* format, ...);

	void LogMsg(const char* format, ...);

	void SetDefaultLog(const string& fileName);

	void Update(uint delta);

	// ֱ��д��־
	static void LogCFile(const string& fileName, const string& buf);
	static void LogCFileEx(const string& fileName, const char* format, ...);
};

#ifdef _DEBUG
#define DbgLog( ... ) LogMgr::GetInstance().LogMsg( __VA_ARGS__ )
#else
#define DbgLog( ... )
#endif

#define GameLog( ... ) LogMgr::GetInstance().LogMsg( __VA_ARGS__ )