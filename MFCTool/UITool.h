#pragma once


// CUITool 대화 상자입니다.

class CUITool : public CDialog
{
	DECLARE_DYNAMIC(CUITool)

public:
	CUITool(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CUITool();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_UITOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
