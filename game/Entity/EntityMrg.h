#pragma once
#include "../GameTool/GameHeadConfig.h"
#include "Entity.h"
#include "SafeTraverseSet.h"
#include "EntityConfig.h"
//ʵ��������
// ���󴴽��ӿ�ԭ��
typedef Entity* (*EntityCreator)(uint entityId, const string& entityName, EntityCreateOpt* createOpt);
// ����ɾ���ӿ�
typedef void(*EntityDeleter)(Entity* entity);

// ����Ĵ������ͷŽӿ�
struct SEntityAlloc
{
	EntityCreator	m_EntityCreator;	// ���󴴽��ӿ�
	EntityDeleter	m_EntityDeleter;	// ����ɾ���ӿ�,�ÿձ�ʾʹ��delete

	SEntityAlloc()
	{
		m_EntityCreator = NULL;
		m_EntityDeleter = NULL;
	}
};

// ������� 
class EntityMgr
{
public:
	typedef UNORDERED_MAP<uint, Entity*>		EntityMap;
	typedef map<uint8, SEntityAlloc>				EntityAllocMap;
	typedef set<Entity*>						EntitySet;
protected:
	EntityAllocMap				m_EntityAllocs;		// �������
	EntityMap					m_Entitys;			// �����
	SafeTraverseSet<Entity*>	m_DeleteEntitys;	// ׼��ɾ���Ķ���
	map<uint8, uint>			m_SerialIds;
public:
	EntityMgr();
	virtual ~EntityMgr();

	SINGLETON_MODE(EntityMgr);

	// ���ɶ���Ψһid,id�а����˶�������
	// ((uint64)EntityType<<56) | (((uint64)serverId)<<40)) | (++SerialId)
	// EntityType:[0,255] serverId:[1,65535] SerialId:[1,2^40]
	uint GetNextEntityId(uint8 entityType);
	uint8 GetEntityType(uint entityId);

	// ��entityId�л�����к�
	static uint GetSerialIdFromEntityId(uint entityId);

	// ��ʼ�����к�
	void InitSerialId(uint8 entityType, uint serialId);
	uint GetSerialId(uint8 entityType);

	// ���Ҷ���
	Entity* GetEntityById(uint entityId);
	Entity* GetEntityByIdStr(const char* strEntityId);

	// ���Ҷ���
	template<class T>
	T* GetEntity(uint entityId)
	{
		return dynamic_cast<T*>(GetEntityById(entityId));
	}

	// ���Ҷ���
	template<class T>
	T* GetEntity(uint entityId, uint8 entityType)
	{
		Entity* object = GetEntityById(entityId);
		if (object && object->GetEntityType() == entityType)
			return (T*)object;
		return NULL;
	}

	// ��������
	Entity* CreateEntity(uint8 entityType, const string& objectName, EntityCreateOpt* createOpt);

	// �Ƴ�����
	void RemoveEntity(Entity* entity);
	void RemoveEntity(uint entityId);

	// ע����󴴽��ӿ�
	void RegisterEntityAlloc(uint8 entityType, SEntityAlloc entityAlloc);
	SEntityAlloc* GetEntityAlloc(uint8 entityType);

	// ����:ɾ����Ҫɾ����ʵ�����
	void Update(uint delta);

	// �ͷ�
	void Shutdown();

	// ʵ������
	uint GetEntityCount() { return (uint)m_Entitys.size(); }
	// ��ȡÿ��ʵ���������Ϣ key:EntityType value:count
	void GetEntityInfo(std::map<uint, uint>& info);
	// ʵ���б�
	const EntityMgr::EntityMap& GetEntityMap() const { return m_Entitys; }
};