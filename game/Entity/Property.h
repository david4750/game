#pragma once

#include "Var.h"
#include "PropertyDesc.h"
#include "../GameTool/GameStream.h"

// ���Լ�
class PropertySet
{
protected:
	Var*				m_Properties;		// ��������
	bool*				m_ChangedFlag;		// �ı�������
	uint				m_PropertyCount;	// ������
	PropertyDesc*		m_PropertyDesc;		// ��Ӧ������ģ��
	bool				m_IsChanged;		// �޸ı��

	static	Var			s_EmptyProperty;	// ��ֵ
public:
	PropertySet();
	~PropertySet();

	// ��ʼ������
	bool Init(uint propertyCount);
	bool Init(const string& descName);
	bool Init(PropertyDesc* desc);
	//������
	uint GetPropertyCount() const { return m_PropertyCount; }

	// ����ģ��
	PropertyDesc* GetDesc() const { return m_PropertyDesc; }

	// ��ȡ��������
	uint GetPropertyIndex(const string& name);
	// ��ȡ������
	const char* GetPropertyName(uint index);

	// �Ƿ��޸Ĺ�
	bool IsChanged() const { return m_IsChanged; }
	bool IsChanged(uint index) const;

	// �����޸ı��
	void ResetChangedFlag();

	// ��ȡ����ֵ
	const Var& GetValue(uint index) const;
	const Var& GetValueByName(const string& name) const;

	bool GetBool(uint index);
	bool GetBoolByName(const string& name) { return GetBool(m_PropertyDesc->GetIndex(name)); }
	int GetInt(uint index);
	int GetIntByName(const string& name) { return GetInt(m_PropertyDesc->GetIndex(name)); }
	uint GetUint(uint index);
	uint GetUintByName(const string& name) { return GetUint(m_PropertyDesc->GetIndex(name)); }
	int64 GetInt64(uint index);
	int64 GetInt64ByName(const string& name) { return GetInt64(m_PropertyDesc->GetIndex(name)); }
	uint64 GetUint64(uint index);
	uint64 GetUint64ByName(const string& name) { return GetUint64(m_PropertyDesc->GetIndex(name)); }
	float GetFloat(uint index);
	float GetFloatByName(const string& name) { return GetFloat(m_PropertyDesc->GetIndex(name)); }
	double GetDouble(uint index);
	double GetDoubleByName(const string& name) { return GetDouble(m_PropertyDesc->GetIndex(name)); }
	const string& GetString(uint index);
	const string& GetStringByName(const string& name) { return GetString(m_PropertyDesc->GetIndex(name)); }

	// ��������ֵ
	bool SetValue(uint index, const Var& value);
	bool SetValueByName(const char* name, const Var& value);

	bool SetBool(uint index, bool value);
	bool SetBoolByName(const char* name, bool value);

	bool SetInt(uint index, int value);
	bool SetIntByName(const char* name, int value);

	bool SetUint(uint index, uint value);
	bool SetUintByName(const char* name, uint value);

	bool SetInt64(uint index, int64 value);
	bool SetInt64ByName(const char* name, int64 value);

	bool SetUint64(uint index, uint64 value);
	bool SetUint64ByName(const char* name, uint64 value);

	bool SetFloat(uint index, float value);
	bool SetFloatByName(const char* name, float value);

	bool SetDouble(uint index, double value);
	bool SetDoubleByName(const char* name, double value);

	bool SetString(uint index, const char* value);
	bool SetStringByName(const char* name, const char* value);

	// ����ֵ
	bool IncInt(uint index, int value)						{ return SetInt(index, value + GetInt(index)); }
	bool IncIntByName(const char* name, int value)			{ return IncInt(GetPropertyIndex(name), value); }

	bool IncUint(uint index, int value);
	bool IncUintByName(const char* name, int value)			{ return IncUint(GetPropertyIndex(name), value); }

	bool IncInt64(uint index, int64 value)					{ return SetInt64(index, value + GetInt64(index)); }
	bool IncInt64ByName(const char* name, int64 value)		{ return IncInt64(GetPropertyIndex(name), value); }

	bool IncUint64(uint index, int64 value);
	bool IncUint64ByName(const char* name, int64 value)		{ return IncUint64(GetPropertyIndex(name), value); }

	bool IncFloat(uint index, float value)					{ return SetFloat(index, value + GetFloat(index)); }
	bool IncFloatByName(const char* name, float value)		{ return IncFloat(GetPropertyIndex(name), value); }

	bool IncDouble(uint index, double value)					{ return SetDouble(index, value + GetDouble(index)); }
	bool IncDoubleByName(const char* name, double value)		{ return IncDouble(GetPropertyIndex(name), value); }

	bool Save(Stream& stream);
	bool Load(Stream& stream);

	// �Ż����ݰ汾�ı���Ͷ�ȡ
	bool SaveMini(Stream& stream);
	bool LoadMini(Stream& stream, const vector<string>& nameList);

	bool SaveNameList(Stream& stream);
};
