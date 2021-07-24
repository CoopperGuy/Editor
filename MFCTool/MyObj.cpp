#include "stdafx.h"
#include "MyObj.h"


MyObj::MyObj()
	:m_bDead(false)
{
	ZeroMemory(&m_tInfo, sizeof(INFO));
}


MyObj::~MyObj()
{
}
