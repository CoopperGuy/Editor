#pragma once


// CRoolTool ��ȭ �����Դϴ�.

class CMFCToolView;
class CRoom;
class CRoomTool : public CDialog
{
	DECLARE_DYNAMIC(CRoomTool)

public:
	CRoomTool(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRoomTool();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROOMTOOL};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:

	CMFCToolView* View;
	int TileSizeX;
	int TileSizeY;
	int TileNumX;
	int TileNumY;
	afx_msg void OnBnClickedRoomCreate();
	afx_msg void OnBnClickedRoomSave();
	afx_msg void OnBnClickedRoomload();
};
