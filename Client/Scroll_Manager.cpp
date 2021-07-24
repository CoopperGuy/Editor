#include "stdafx.h"
#include "Scroll_Manager.h"

D3DXVECTOR3 CScroll_Manager::m_vScroll = {};
CScroll_Manager::CScroll_Manager()
{
}


CScroll_Manager::~CScroll_Manager()
{
}

const float  CScroll_Manager::Get_Scroll(SCROLLID eID)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	switch (eID)
	{
	case CScroll_Manager::HORZ_SCROLL:
		return m_vScroll.x;
	case CScroll_Manager::VERT_SCROLL:
		return m_vScroll.y; 
	}
	return 0.f; 
}

void CScroll_Manager::Set_Scroll(SCROLLID eID, const float & fScroll)
{
	switch (eID)
	{
	case CScroll_Manager::HORZ_SCROLL:
		m_vScroll.x += fScroll;
		break; 
	case CScroll_Manager::VERT_SCROLL:
		m_vScroll.y += fScroll;
		break;
	}
	
}
