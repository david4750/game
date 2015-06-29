#pragma once
#include "../GameTool/GameHeadConfig.h"
//��Ϸ�¼�
class GameEvent
{
protected:
	uint	m_EventId;	// �¼�id
	uint	m_EntityId;	// ����id
public:
	GameEvent(uint eventId, uint entityId)
		: m_EventId(eventId), m_EntityId(entityId)
	{
	}
	uint GetEventId() { return m_EventId; }
	uint GetEntityId() { return m_EntityId; }
};