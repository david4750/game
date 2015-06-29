#pragma once

#include "Var.h"
#include "../GameTool/GameStream.h"
#include "XmlWrapper.h"
#include "StringUtil.h"

// ���Ա��
enum EPropertyFlag
{
	EPropertyFlag_SaveDb = 0x0001,	// �������ݿ�
	EPropertyFlag_Server = 0x0002,	// ������������
	EPropertyFlag_Client = 0x0004,	// �ͻ��˵�����
	EPropertyFlag_SyncSelf = 0x0008,	// ֻͬ�����Լ�
	EPropertyFlag_SyncScene = 0x0010,	// ͬ������Χ�����
};

// �������Ե�����
class Desc
{
public:
	string	m_Name;				// ������
	Var		m_DefaultValue;		// Ĭ��ֵ
	uint	m_Flag;				// ���
	//string	m_Comment;			// ע��

	Desc()
	{
		m_Flag = 0;
	}

	bool HasFlag(uint propertyFlag)
	{
		return ((m_Flag & propertyFlag) != 0);
	}
};

// ��������
class PropertyDesc
{
public:
	typedef vector<Desc>			DescList;
	typedef UNORDERED_MAP<string, uint>	NameIndexMap;
protected:
	string			m_Name;				// ����
	DescList		m_Descs;			// �����б�
	NameIndexMap	m_NameIndexMap;		// ������������������ӳ��
	vector<uint>	m_SyncSelfIndexs;	// ͬ�����Լ������������б�
	vector<uint>	m_SyncSceneIndexs;	// ͬ������Χ��ҵ����������б�
public:
	PropertyDesc(const string& name);

	// ����
	const string& GetName() { return m_Name; }

	// ���һ������
	void Add(Desc& desc);

	// ��ȡ����
	Desc* GetDesc(uint index);
	Desc* GetDescByName(const string& name);
	DescList& GetDescs() { return m_Descs; }

	// ��ȡ��������
	uint GetIndex(const string& name);

	// �Ƿ���ĳ������
	bool Has(const string& name);

	// ��ȡͬ�������������б�
	const vector<uint>& GetSyncSelfIndexs() const { return m_SyncSelfIndexs; }
	const vector<uint>& GetSyncSceneIndexs() const { return m_SyncSceneIndexs; }

	bool SaveNameList(Stream& stream);
	void GetNameList(vector<string>& nameList);
	static bool LoadNameList(Stream& stream, vector<string>& nameList);
};

// ������������
class PropertyDescMgr
{
public:
	typedef UNORDERED_MAP<string, PropertyDesc*>	PropertyDescMap;
protected:
	PropertyDescMap m_PropertyDescs;	// ���Ա�
public:
	PropertyDescMgr();
	~PropertyDescMgr();

	//SINGLETON_MODE(PropertyDescMgr);
	static PropertyDescMgr *getInstance();

	// ���һ����������
	void Add(PropertyDesc* desc);
	// ��ȡ��������
	PropertyDesc* Get(const string& name);

	// ���Ա�
	const PropertyDescMgr::PropertyDescMap& GetDescs() const { return m_PropertyDescs; }

	// ������������
	bool Init(const string& fileList, bool isServer);

	// �������������ļ�
	bool LoadPropertyDescFile(const string& fileName, bool isServer);

	// �ͷ�
	void Shutdown();
};
