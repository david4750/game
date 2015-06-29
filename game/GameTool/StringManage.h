#pragma once
#include "../Entity/Var.h"
#include "GameHeadConfig.h"
#include "../Entity/XmlWrapper.h"
#include "../Entity/GameLog.h"
#include "../Entity/TypeConvert.h"
#include "comUTF.h"
#include "../Entity/StringUtil.h"
class StringMgr
{
protected:
	typedef UNORDERED_MAP<string, string> StringMap;
	StringMap	m_StringMap;
	std::vector<string> m_FilterList;
public:
	StringMgr();
	virtual ~StringMgr();

	static StringMgr *getInstance();

	// ����������Դ
	bool Init();

	bool LoadString(const char* fileName);

	bool LoadStringWithPath(const char* path, const char* fileName, bool isFilter = false);

	// ��ȡ����
	const char* GetString(const char* key) const;

	// ��ʽ���ַ���
	// <String Key="KeyName" Value="SrtingValue"/>
	string FormatString(const char* key);
	// <String Key="KeyName" Value="SrtingValue{%d1}..."/>
	string FormatString(const char* key, const Var* arg);
	// <String Key="KeyName" Value="SrtingValue{%d1}...{%s2}...{%f3}..."/>
	string FormatString(const char* key, const vector<Var *>& args);
	string FormatStringArgs(const char* key, const vector<Var *>& args) { return FormatString(key, args); }

	bool Parse(const char* key, const string& text, std::vector<int>& indexs, vector<ETypeId>& typeIds, vector<string>& strings);
	string ArgToString(const Var& arg, ETypeId typeId);
	string Format(const char* format, ...);

	// ��ӹ����ַ�
	void LoadFilterString(const char* file);


	// ������ֵĺϷ���(��ֹ���������ַ�)
	static bool IsValidName(const string& str, string* errorStr);
	// ������ֵĳ���
	static bool IsStrLenInRange(const string& str, int minLen, int maxLen);

	//���������
	string ProcessWithFilters(const char* s);
	//�Ƿ��й�����
	bool HasFilterWord(const string& s);

	static void ReplaceString(string& str, const string& findStr, const string& replaceStr);
};