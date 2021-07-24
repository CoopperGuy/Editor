#pragma once


// CMonsterTool ��ȭ �����Դϴ�.

class CMonsterTool : public CDialog
{
	DECLARE_DYNAMIC(CMonsterTool)

public:
	CMonsterTool(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CMonsterTool();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MONSTERTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
