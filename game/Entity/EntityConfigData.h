#pragma once 
#include "Var.h"
#include "XmlWrapper.h"
#include "EntityMrg.h"
class  EntityConfigData
{
protected:
	Entity*		m_Entity;			// ʵ��,����������Լ�
public:
	EntityConfigData(const char* propertyDescName);
	virtual ~EntityConfigData();

	// ��ȡʵ��
	Entity* GetEntity() const { return m_Entity; }

	// ��������
	virtual bool Load(XmlElement* entityNode);
};