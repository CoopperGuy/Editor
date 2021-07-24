#include "stdafx.h"
#include "Frame_Manager.h"


CFrame_Manager::CFrame_Manager()
{
}


CFrame_Manager::~CFrame_Manager()
{
}

void CFrame_Manager::Ready_Frame_Manager(float fFPS)
{
	m_fSPF = 1.f / fFPS; 
	QueryPerformanceCounter(&m_tBegin); 
	QueryPerformanceCounter(&m_tEnd);
	QueryPerformanceFrequency(&m_tCpuTick); 
	m_fDeltaTime = 0.f; 
}

bool CFrame_Manager::FrameLock()
{
	QueryPerformanceCounter(&m_tEnd); 
	m_fDeltaTime += float(m_tEnd.QuadPart - m_tBegin.QuadPart) / m_tCpuTick.QuadPart; 
	if (m_fDeltaTime >= m_fSPF)
	{
		QueryPerformanceFrequency(&m_tCpuTick); 
		m_fDeltaTime = 0.f; 
		return true; 
	}
	m_tBegin.QuadPart = m_tEnd.QuadPart; 
	return false;
}
