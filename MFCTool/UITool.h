#pragma once


// CUITool ��ȭ �����Դϴ�.

class CUITool : public CDialog
{
	DECLARE_DYNAMIC(CUITool)

public:
	CUITool(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CUITool();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UITOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
