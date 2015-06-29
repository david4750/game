#pragma once
#include "GameHeadConfig.h"
#include "CCLuaEngine.h"
extern "C" {
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
};
class ScriptSys
{
public:
	static ScriptSys *getInstance();
public:
	ScriptSys();
	~ScriptSys();
public:
	//------------  c++ -> lua ------------//

	/*
	getLuaVarString : ����luaȫ��string

	luaFileName  = lua�ļ���
	varName = ��ҪȡLua�еı�����
	*/
	const char* getLuaVarString(const char* luaFileName, const char* varName);

	/*
	getLuaVarOneOfTable : ����luaȫ��table�е�һ��Ԫ��

	luaFileName  = lua�ļ���
	varName = ��ҪȡLua�е�table������
	keyName = ��ҪȡLua�е�table��ĳһ��Ԫ�ص�Key
	*/
	const char* getLuaVarOneOfTable(const char* luaFileName, const char* varName, const char* keyName);

	/*
	getLuaVarTable : ����luaȫ��table

	luaFileName  = lua�ļ���
	varName = ��Ҫȡ��table������

	��ע�����ص������е����ݣ�ͯЬ�ǿ����Լ�ʹ��Map�ȴ���
	*/
	const char* getLuaVarTable(const char* luaFileName, const char* varName);

	/*
	   ��ȡlua ȫ��table �����table��ʽ��
	   g_table = ����

	*/
	void getLuaVarTable(const char *luaFileName, const char* varName, vector<string>& luatable);
	/*
	callLuaFunction : ����lua����

	luaFileName  = lua�ļ���
	functionName = ��Ҫ����Lua�еĵĺ�����
	*/
	const char* callLuaFunction(const char* luaFileName, const char* functionName);
protected:
	const char* getFileFullPath(const char* fileName);
};