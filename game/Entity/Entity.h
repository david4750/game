#pragma once
#include "../GameTool/GameHeadConfig.h"
#include "Property.h"
#include "ExtraPropertyMap.h"
#include "EventDispatch.h"
#include "EntityComponent.h"

// ���󴴽�ʱ����������
// ���ڲ�ͬ�����ڴ���ʱ�Ĳ��컯
class EntityCreateOpt
{
public:
	uint m_EntityId;	// ����id,Ĭ��Ϊ0,���ɹ������Զ�����

	EntityCreateOpt()
	{
		m_EntityId = 0;
	}
};

class Entity : public ExtraPropertyMap
{
	friend class EntityMgr;
public:
	typedef std::map<uint, EntityComponent*>	ComponentMap;
protected:
	uint8	m_EntityType;				// ��������
	uint	m_EntityId;					// ����id
	string	m_EntityName;				// ������
protected:
	PropertySet		m_PropertySet;		// ���Լ�
	EventDispatch*	m_EventDispatch;	// �¼��ַ�
	ComponentMap*	m_Components;		// ����б�
//	Scheduler*		m_Scheduler;		// ��ʱ�ص�
protected:
	// ֻ����EntityMgr����������,�Ա�ͳһ����
	Entity(uint8 entityType, uint entityId, const string& name);
public:
	virtual ~Entity();

	// �����ӿ�
	static Entity* Create(uint entityId, const string& entityName, EntityCreateOpt* createOpt);

	// ��������
	uint8 GetEntityType() const { return m_EntityType; }
	// ����id
	uint GetEntityId() const { return m_EntityId; }
	// ������
	const string& GetEntityName() const { return m_EntityName; }
	// ����������(���Խṹ��)
	const char* GetPropertyDescName() const;

	// ���Լ�
	PropertySet& GetPropertySet() { return m_PropertySet; }

	// ��ȡ���
	EntityComponent* GetComponentById(uint componentId);

	// ��ȡ���
	template<class T>
	T* GetComponent(uint componentId)
	{
		return dynamic_cast<T*>(GetComponentById(componentId));
	}

	// ���һ�����
	void AddComponent(uint componentId, EntityComponent* component);
	// �Ƴ�һ�����
	void RemoveComponent(uint componentId);
	// ɾ��һ�����
	void DeleteComponent(uint componentId);

	// ��ȡ�¼��ַ���,û�оͷ���(�ز�ΪNULL)
	EventDispatch* GetEventDispatch();
	// ��ȡ�¼��ַ���ָ��(����ΪNULL)
	EventDispatch* GetEventDispatchPointer() { return m_EventDispatch; }
	////��ʱ�ص�,û�оͷ���(�ز�ΪNULL)
	//Scheduler* GetScheduler();
	//// ��ʱ�ص�ָ��(����ΪNULL)
	//Scheduler* GetSchedulerPointer() { return m_Scheduler; }

	// ���½ӿ�
//	virtual void Update(uint delta);

	// ��ȡ����ֵ
	const Var& GetValue(uint index) const					{ return m_PropertySet.GetValue(index); }
	const Var& GetValueByName(const string& name) const	{ return m_PropertySet.GetValueByName(name); }

	bool GetBool(uint index)								{ return m_PropertySet.GetBool(index); }
	bool GetBoolByName(const string& name)				{ return m_PropertySet.GetBoolByName(name); }
	int GetInt(uint index)								{ return m_PropertySet.GetInt(index); }
	int GetIntByName(const string& name)					{ return m_PropertySet.GetIntByName(name); }
	uint GetUint(uint index)								{ return m_PropertySet.GetUint(index); }
	uint GetUintByName(const string& name)				{ return m_PropertySet.GetUintByName(name); }
	int64 GetInt64(uint index)							{ return m_PropertySet.GetInt64(index); }
	int64 GetInt64ByName(const string& name)				{ return m_PropertySet.GetInt64ByName(name); }
	uint64 GetUint64(uint index)							{ return m_PropertySet.GetUint64(index); }
	uint64 GetUint64ByName(const string& name)			{ return m_PropertySet.GetUint64ByName(name); }
	float GetFloat(uint index)							{ return m_PropertySet.GetFloat(index); }
	float GetFloatByName(const string& name)				{ return m_PropertySet.GetFloatByName(name); }
	double GetDouble(uint index)							{ return m_PropertySet.GetDouble(index); }
	double GetDoubleByName(const string& name)			{ return m_PropertySet.GetDoubleByName(name); }
	const string& GetString(uint index)					{ return m_PropertySet.GetString(index); }
	const string& GetStringByName(const string& name)		{ return m_PropertySet.GetStringByName(name); }

	// ��������ֵ
	bool SetValue(uint index, const Var& value)				{ return m_PropertySet.SetValue(index, value); }
	bool SetValueByName(const char* name, const Var& value)	{ return m_PropertySet.SetValueByName(name, value); }

	bool SetBool(uint index, bool value)						{ return m_PropertySet.SetBool(index, value); }
	bool SetBoolByName(const char* name, bool value)			{ return m_PropertySet.SetBoolByName(name, value); }

	bool SetInt(uint index, int value)						{ return m_PropertySet.SetInt(index, value); }
	bool SetIntByName(const char* name, int value)			{ return m_PropertySet.SetIntByName(name, value); }

	bool SetUint(uint index, uint value)						{ return m_PropertySet.SetUint(index, value); }
	bool SetUintByName(const char* name, uint value)			{ return m_PropertySet.SetUintByName(name, value); }

	bool SetInt64(uint index, int64 value)					{ return m_PropertySet.SetInt64(index, value); }
	bool SetInt64ByName(const char* name, int64 value)		{ return m_PropertySet.SetInt64ByName(name, value); }

	bool SetUint64(uint index, uint64 value)					{ return m_PropertySet.SetUint64(index, value); }
	bool SetUint64ByName(const char* name, uint64 value)		{ return m_PropertySet.SetUint64ByName(name, value); }

	bool SetFloat(uint index, float value)					{ return m_PropertySet.SetFloat(index, value); }
	bool SetFloatByName(const char* name, float value)		{ return m_PropertySet.SetFloatByName(name, value); }

	bool SetDouble(uint index, double value)					{ return m_PropertySet.SetDouble(index, value); }
	bool SetDoubleByName(const char* name, double value)		{ return m_PropertySet.SetDoubleByName(name, value); }

	bool SetString(uint index, const char* value)				{ return m_PropertySet.SetString(index, value); }
	bool SetStringByName(const char* name, const char* value)	{ return m_PropertySet.SetStringByName(name, value); }

	// ����ֵ
	bool IncInt(uint index, int value)						{ return m_PropertySet.IncInt(index, value); }
	bool IncIntByName(const char* name, int value)			{ return m_PropertySet.IncIntByName(name, value); }

	bool IncUint(uint index, int value)						{ return m_PropertySet.IncUint(index, value); }
	bool IncUintByName(const char* name, int value)			{ return m_PropertySet.IncUintByName(name, value); }

	bool IncInt64(uint index, int64 value)					{ return m_PropertySet.IncInt64(index, value); }
	bool IncInt64ByName(const char* name, int64 value)		{ return m_PropertySet.IncInt64ByName(name, value); }

	bool IncUint64(uint index, int64 value)					{ return m_PropertySet.IncUint64(index, value); }
	bool IncUint64ByName(const char* name, int64 value)		{ return m_PropertySet.IncUint64ByName(name, value); }

	bool IncFloat(uint index, float value)					{ return m_PropertySet.IncFloat(index, value); }
	bool IncFloatByName(const char* name, float value)		{ return m_PropertySet.IncFloatByName(name, value); }

	bool IncDouble(uint index, double value)					{ return m_PropertySet.IncDouble(index, value); }
	bool IncDoubleByName(const char* name, double value)		{ return m_PropertySet.IncDoubleByName(name, value); }

	// ��xml��������ֵ
	bool LoadPropertyNode(XmlElement* node, bool isLood = true);

	// ����������ʵ������ʼ��
	bool InitPropertySet(Entity* dataEntity);

	// д�����Գ�ʼ����
	bool WritePropertyInit(Stream& stream, EPropertyFlag flag);
	// ��ȡ���Գ�ʼ����
	bool ReadPropertyInit(Stream& stream);
};