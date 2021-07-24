#pragma once

#include "MyObj.h"
class CMonster final : public MyObj
{
public:
	CMonster();
	~CMonster();

public:
	virtual HRESULT Ready_Object() override;
	virtual int Update_Object() override;
	virtual void Late_Update_Object() override;
	virtual void Render_Object() override;
	virtual void Release_Object() override;
};

