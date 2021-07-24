// RoolTool.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "RoomTool.h"
#include "afxdialogex.h"
#include "Room.h"
#include "MFCToolView.h"
#include "MainFrm.h"
#include "Terrain.h"
#include "Tile.h"
// CRoolTool ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CRoomTool, CDialog)

CRoomTool::CRoomTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_ROOMTOOL, pParent)
	, TileSizeX(0)
	, TileSizeY(0)
	, TileNumX(0)
	, TileNumY(0)
{

}

CRoomTool::~CRoomTool()
{
}

void CRoomTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT1, TileSizeX);
	DDX_Text(pDX, IDC_EDIT2, TileSizeY);
	DDX_Text(pDX, IDC_EDIT2, TileSizeY);
	DDX_Text(pDX, IDC_EDIT3, TileNumX);
	DDX_Text(pDX, IDC_EDIT4, TileNumY);
}


BEGIN_MESSAGE_MAP(CRoomTool, CDialog)

	ON_BN_CLICKED(IDC_BUTTON1, &CRoomTool::OnBnClickedRoomCreate)
	ON_BN_CLICKED(IDC_BUTTON7, &CRoomTool::OnBnClickedRoomSave)
	ON_BN_CLICKED(IDC_BUTTON2, &CRoomTool::OnBnClickedRoomload)
END_MESSAGE_MAP()


// CRoolTool �޽��� ó�����Դϴ�.


void CRoomTool::OnBnClickedRoomCreate()
{
	UpdateData(TRUE);
	CRoom* room = CRoom::Create({ TileSizeX,TileSizeY,TileNumX,TileNumY });
	CMainFrame* pMain = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CMFCToolView* pView = dynamic_cast<CMFCToolView*>(pMain->m_tMainSplitter.GetPane(0, 1));
	Safe_Delete(pView->m_pRoom);
	room->Set_View(pView);
	pView->m_pRoom = room;
	pView->Invalidate(TRUE);
	UpdateData(FALSE);
}


void CRoomTool::OnBnClickedRoomSave()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CFileDialog Dlg(FALSE,// ���� ���(TRUE) Ȥ�� ���� ���(FALSE) ��� �� ������. 
		L"dat",// ����Ʈ Ȯ���� �� 
		L"*.dat",// ����Ʈ ���� �̸� 
		OFN_OVERWRITEPROMPT);// â�� �⺻ ���¸� �������� �� ����. �ִ� �ߺ����� ����� ���޽��� �����.  
	TCHAR szFilePath[MAX_PATH]{};
	//D:\�ں���\119\FrameWork (6) (2)
	GetCurrentDirectory(MAX_PATH, szFilePath);
	PathRemoveFileSpec(szFilePath);
	// D:\�ں���\119\FrameWork (6) (2)\Data
	lstrcat(szFilePath, L"\\Data\\Room");
	Dlg.m_ofn.lpstrInitialDir = szFilePath;
	if (IDOK == Dlg.DoModal())
	{
		CString wstrFilePath = Dlg.GetPathName();
		HANDLE hFile = CreateFile(wstrFilePath.GetString(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);

		if (INVALID_HANDLE_VALUE == hFile)
			return;

		DWORD dwByte = 0;
		CMainFrame* pMain = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
		CMFCToolView* pView = dynamic_cast<CMFCToolView*>(pMain->m_tMainSplitter.GetPane(0, 1));

		TILEINFO _info = pView->m_pRoom->Get_TileInfo();
		WriteFile(hFile, &_info, sizeof(TILEINFO), &dwByte, nullptr);
		vector<CTile*> vecTile = pView->m_pRoom->Get_Terrain()->Get_TileData();
		for (auto& pTile : vecTile) {
			TILE _tile = pTile->Get_Tile();
			WriteFile(hFile, &_tile, sizeof(TILE), &dwByte, nullptr);
		}
		CloseHandle(hFile);
	}
}


void CRoomTool::OnBnClickedRoomload()
{
	CFileDialog Dlg(TRUE,// ���� ���(TRUE) Ȥ�� ���� ���(FALSE) ��� �� ������. 
		L"dat",// ����Ʈ Ȯ���� �� 
		L"*.dat",// ����Ʈ ���� �̸� 
		OFN_OVERWRITEPROMPT);// â�� �⺻ ���¸� �������� �� ����. �ִ� �ߺ����� ����� ���޽��� �����.  
	TCHAR szFilePath[MAX_PATH]{};
	//D:\�ں���\119\FrameWork (6) (2)
	GetCurrentDirectory(MAX_PATH, szFilePath);
	PathRemoveFileSpec(szFilePath);
	// D:\�ں���\119\FrameWork (6) (2)\Data
	lstrcat(szFilePath, L"\\Data");
	Dlg.m_ofn.lpstrInitialDir = szFilePath;
	if (IDOK == Dlg.DoModal())
	{
		CString wstrFilePath = Dlg.GetPathName();
		HANDLE hFile = CreateFile(wstrFilePath.GetString(), GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

		if (INVALID_HANDLE_VALUE == hFile)
			return;


		CMainFrame* pMain = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
		CMFCToolView* pView = dynamic_cast<CMFCToolView*>(pMain->m_tMainSplitter.GetPane(0, 1));
		pView->m_pRoom->Get_Terrain()->Delete_Tile();
		DWORD dwByte = 0;
		CTile* pTile = nullptr;
		TILEINFO _info;
		ReadFile(hFile, &_info, sizeof(TILEINFO), &dwByte, nullptr);
		pView->m_pRoom->Set_TileInfo(_info);
		while (true) {
			TILE _temp;
			ReadFile(hFile, &_temp, sizeof(TILE), &dwByte, nullptr);
			if (0 == dwByte)
				break;
			pTile = CTile::Create(_temp);
			pView->m_pRoom->Get_Terrain()->Add_Tile(pTile);
		}

		pView->Invalidate(TRUE);
		CloseHandle(hFile);
	}
}
