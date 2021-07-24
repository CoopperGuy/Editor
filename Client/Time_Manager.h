#pragma once
class CTime_Manager
{
	DECLARE_SINGLETON(CTime_Manager)
private:
	CTime_Manager();
	~CTime_Manager();
public:
	float Get_DeltaTime() { return m_fDeltaTime; }
public:
	void Ready_TimeManager(); 
	void Update_TimeManager(); 
private:
	LARGE_INTEGER m_tBegin;
	LARGE_INTEGER m_tEnd; 
	LARGE_INTEGER m_tCputick; 
	float m_fDeltaTime; 

};

