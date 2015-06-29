#pragma once 
#include "../GameTool/GameHeadConfig.h"
class TickCounter
{
public:
	uint	m_RunningTick;	// ����ʱ��
	uint	m_ExpiredTick;	// ����ʱ��,Ϊ0ʱ,��ʾ��������

public:
	TickCounter()
	{
		m_RunningTick = m_ExpiredTick = 0;
	}

	// ����
	void Reset(uint expiredTick)
	{
		m_RunningTick = 0;
		m_ExpiredTick = expiredTick;
	}

	// ����ʱ��
	void Update(uint delta)
	{
		m_RunningTick += delta;
	}

	// �Ƿ����
	bool IsExpired()
	{
		if (m_ExpiredTick == 0)
			return false;
		return (m_RunningTick >= m_ExpiredTick);
	}

	// �Ƿ����,�������������ʱ��
	bool IsExpiredAndResetTick()
	{
		if (m_ExpiredTick == 0)
			return false;
		bool isExpire = false;
		if (m_RunningTick >= m_ExpiredTick)
		{
			isExpire = true;
			m_RunningTick -= m_ExpiredTick;
		}
		return isExpire;
	}

	// �Ƿ����,�������������ʱ��Ϊ0
	bool IsExpiredAndResetZero()
	{
		if (m_ExpiredTick == 0)
			return false;
		bool isExpire = false;
		if (m_RunningTick >= m_ExpiredTick)
		{
			isExpire = true;
			m_RunningTick = 0;
		}
		return isExpire;
	}
};