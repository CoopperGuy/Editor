#pragma once


// CRoolTool ��ȭ �����Դϴ�.

class CRoolTool : public CDialog
{
	DECLARE_DYNAMIC(CRoolTool)

public:
	CRoolTool(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoolTool();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROOMTOOL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
