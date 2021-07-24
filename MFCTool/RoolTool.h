#pragma once


// CRoolTool 대화 상자입니다.

class CRoolTool : public CDialog
{
	DECLARE_DYNAMIC(CRoolTool)

public:
	CRoolTool(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRoolTool();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROOMTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
