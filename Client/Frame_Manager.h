#pragma once
class CFrame_Manager
{
public:
	CFrame_Manager();
	~CFrame_Manager();
public:
	void Ready_Frame_Manager(float fFPS); 
	bool FrameLock(); 
private:
	LARGE_INTEGER m_tBegin; 
	LARGE_INTEGER m_tEnd; 
	LARGE_INTEGER m_tCpuTick; 
	float		m_fDeltaTime; 
	float		m_fSPF; // 1 / FPS

};

