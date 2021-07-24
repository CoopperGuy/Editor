#include "stdafx.h"
#include "Time_Manager.h"

IMPLEMENT_SINGLETON(CTime_Manager)
CTime_Manager::CTime_Manager()
	:m_fDeltaTime(0.f)
{
}


CTime_Manager::~CTime_Manager()
{
}

void CTime_Manager::Ready_TimeManager()
{
	QueryPerformanceFrequency(&m_tCputick); 
	QueryPerformanceCounter(&m_tBegin); 
	QueryPerformanceCounter(&m_tEnd); 
}

void CTime_Manager::Update_TimeManager()
{
	QueryPerformanceFrequency(&m_tCputick);
	QueryPerformanceCounter(&m_tEnd);
	m_fDeltaTime = float(m_tEnd.QuadPart - m_tBegin.QuadPart) / m_tCputick.QuadPart;
	m_tBegin.QuadPart = m_tEnd.QuadPart ;
}
