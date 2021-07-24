#pragma once


// CRoolTool 대화 상자입니다.

class CMFCToolView;
class CRoom;
class CRoomTool : public CDialog
{
	DECLARE_DYNAMIC(CRoomTool)

public:
	CRoomTool(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRoomTool();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ROOMTOOL};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
