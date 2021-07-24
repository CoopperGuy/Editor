#pragma once
class MyObj abstract
{
public:
	explicit MyObj();
	virtual ~MyObj();

public:
	virtual HRESULT Ready_Object()PURE;
	virtual int		Update_Object()PURE;
	virtual void	Late_Update_Object()PURE;
	virtual void	Render_Object()PURE;
	virtual void	Release_Object()PURE;

protected:
	INFO		m_tInfo;
	bool		m_bDead;
};

