#pragma once
#include "GameEvent.h"
class Entity;
//ʵ���������
class EntityComponent
{
	friend class Entity;
protected:
	Entity*	m_Entity;		// ������ʵ�����
	bool	m_IsDeleted;	// ɾ�����
public:
	EntityComponent(Entity*	entity);
	virtual ~EntityComponent() {}

	Entity* GetEntity() { return m_Entity; }
	bool IsDeleted() const { return m_IsDeleted; }
	//ʵ������ģ��
	template<class T>
	T* GetEntity()
	{
		return dynamic_cast<T*>(m_Entity);
	}
};

// ע���¼��ص�
#define REGISTER_EVENT( eventId, eventDelegate )\
	GetEntity()->GetEventDispatch()->Register( eventId, this, (EventDelegate)(&eventDelegate) )
