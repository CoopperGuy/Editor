#pragma once


// CMonsterTool 대화 상자입니다.

class CMonsterTool : public CDialog
{
	DECLARE_DYNAMIC(CMonsterTool)

public:
	CMonsterTool(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CMonsterTool();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MONSTERTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString	m_MonsterNameBox;
	CString m_MonsterList;
	afx_msg void OnBnClickedMonsteradd();
	afx_msg void OnBnClickedMonsterdelete();
	afx_msg void OnBnClickedMonsterchange();
	afx_msg void OnBnClickedChange();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnLbnSelchangeMonsterlist();

	float PosX;
	float PosY;
	float SIZEX;
	float SIZEY;
	float SPEEDX;
	float SPEEDY;
	float RECTX;
	float RECTY;
	float DETECTX;
	float DETECTY;
};
