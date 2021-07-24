#include "stdafx.h"
#include "Monster.h"
#include "Texture_Manager.h"


CMonster::CMonster()
{
}


CMonster::~CMonster()
{
	Release_Object();
}

HRESULT CMonster::Ready_Object()
{

	return S_OK;
}

int CMonster::Update_Object()
{
	if (m_bDead)
		return OBJ_DEAD;
	return OBJ_NOEVENT;
	
}

void CMonster::Late_Update_Object()
{
}

void CMonster::Render_Object()
{
	
}

void CMonster::Release_Object()
{
}
