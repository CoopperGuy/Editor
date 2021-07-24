#pragma once



// CForm 폼 뷰입니다.
#include "UnitTool.h"
#include "MapTool.h"
#include "UITool.h"
#include "MonsterTool.h"
#include "ObjectTool.h"
#include "RooMTool.h"
class CForm : public CFormView
{
	DECLARE_DYNCREATE(CForm)

protected:
	CForm();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CForm();
public:
	CUnitTool m_tUnitTool;
	CObjectTool m_tObjectTool;
	CMonsterTool m_tMonsterTool;
	CMapTool m_tMapTool; 
	CUITool m_tUITool;
	CRoomTool m_tRoomTool;

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORM };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedUnitTool();
	afx_msg void OnBnClickedButton6();
	afx_msg void ObjectTool();
	afx_msg void MonsterTool();
	afx_msg void RoomTool();
	afx_msg void UITool();


};


