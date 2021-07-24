#pragma once
class CScroll_Manager
{
public:
	enum SCROLLID {	HORZ_SCROLL, VERT_SCROLL, END};
public:
	CScroll_Manager();
	~CScroll_Manager();
public:
	static const D3DXVECTOR3& Get_Scroll() { return m_vScroll;  }
	static const float Get_Scroll(SCROLLID eID);
	static void Set_Scroll(const D3DXVECTOR3& vScroll) { m_vScroll += vScroll;  }
	static void Set_Scroll(SCROLLID eID, const float& fScroll);
private:
	static D3DXVECTOR3 m_vScroll; 
};

