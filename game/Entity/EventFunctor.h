#pragma once
//��������

#include "GameEvent.h"
#include "EntityComponent.h"
typedef bool (EntityComponent::*EventDelegate)(GameEvent*);
class EventFunctor
{
protected:
	EntityComponent*		m_Component;		// ���
	EventDelegate	m_EventDelegate;	// ����ĳ�Ա����
public:
	EventFunctor(EntityComponent* component, EventDelegate eventDelegate);

	EntityComponent* GetComponent() { return m_Component; }

	bool Invoke(GameEvent* evt);
};