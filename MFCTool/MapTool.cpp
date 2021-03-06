// MapTool.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "MapTool.h"
#include "afxdialogex.h"
#include "FileInfo.h"
#include "Texture_Manager.h"
#include "MainFrm.h"
#include "MFCToolView.h"
#include "Terrain.h"
#include "Tile.h"
#include "Room.h"
// CMapTool 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMapTool, CDialog)

CMapTool::CMapTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MAPTOOL, pParent)
	, m_dwDrawID(0)
{

}

CMapTool::~CMapTool()
{
}

void CMapTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ListBox);
	DDX_Control(pDX, IDC_PICTURE, m_Picture);
}


BEGIN_MESSAGE_MAP(CMapTool, CDialog)
	ON_WM_DROPFILES()
	ON_LBN_SELCHANGE(IDC_LIST1, &CMapTool::OnLbnSelchangePicture)
	ON_BN_CLICKED(IDC_BUTTON1, &CMapTool::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &CMapTool::OnBnClickedButton6)
END_MESSAGE_MAP()


// CMapTool 메시지 처리기입니다.


void CMapTool::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int iCount = DragQueryFile(hDropInfo, 0xffffffff, nullptr, 0);
	TCHAR szFilePath[MAX_PATH]{}; 

	for (int i = 0 ; i < iCount ; ++i)
	{
		DragQueryFile(hDropInfo, i, szFilePath, MAX_PATH); 
		CString wstrRelativePath = CFileInfo::ConvertRelativePath(szFilePath); 
		CString wstrFileNameAndEx = PathFindFileName(szFilePath); 
		TCHAR szFileName[MAX_PATH]{}; 
		lstrcpy(szFileName, wstrFileNameAndEx.GetString()); 
		PathRemoveExtension(szFileName);
		m_ListBox.AddString(szFileName);
	}
	m_ListBox.SetHorizontalExtent(800);
	UpdateData(FALSE); 
	CDialog::OnDropFiles(hDropInfo);
}


void CMapTool::OnLbnSelchangePicture()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); 
	int iIndex = m_ListBox.GetCurSel(); 

	CString wstrFileName; 
	m_ListBox.GetText(iIndex, wstrFileName); 

	int i = 0; 
	for (; i < wstrFileName.GetLength() ; ++i)
	{
		//isdigit - 0~ 9까지의 숫자인지 판별해주는 함수. 
		if (isdigit(wstrFileName[i]))
			break; 
	}
	// 15 
	wstrFileName.Delete(0, i); // Tile 
	m_dwDrawID = _ttoi(wstrFileName.GetString());

	CGraphic_Device::Get_Instance()->Render_Begin(); 
	D3DXMATRIX matScale, matTrans, matWorld; 
	D3DXMatrixScaling(&matScale, WINCX / float(TILECX), WINCY / float(TILECY), 0.f); 
	D3DXMatrixTranslation(&matTrans, 400.f, 300.f, 0.f); 
	matWorld = matScale * matTrans; 
	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Terrain", L"Tile", m_dwDrawID);
	if (nullptr == pTexInfo)
		return; 
	float fCenterX = float(pTexInfo->tImageInfo.Width >> 1); 
	float fCenterY = float(pTexInfo->tImageInfo.Height >> 1); 

	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld); 
	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255, 255, 255, 255)); 
	CGraphic_Device::Get_Instance()->Render_End(m_Picture.m_hWnd);
	UpdateData(FALSE);
}

//Save
void CMapTool::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog Dlg(FALSE,// 열기 모드(TRUE) 혹은 저장 모드(FALSE) 어떤것 할 것인지. 
		L"dat",// 디폴트 확장자 명 
		L"*.dat",// 디폴트 파일 이름 
		OFN_OVERWRITEPROMPT);// 창에 기본 상태를 설정해줄 수 있음. 애는 중복파일 저장시 경고메시지 띄워줌.  
	TCHAR szFilePath[MAX_PATH]{};
	//D:\박병건\119\FrameWork (6) (2)
	GetCurrentDirectory(MAX_PATH, szFilePath);
	PathRemoveFileSpec(szFilePath);
	// D:\박병건\119\FrameWork (6) (2)\Data
	lstrcat(szFilePath, L"\\Data");
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
		//const vector<CTile*>& vecTileData = pView->m_pRoom->Get_TileData();
		//for (auto& pTile : vecTileData)
		//	WriteFile(hFile, pTile, sizeof(CTile), &dwByte, nullptr);
		const vector<CTile*>& vecTileData = pView->m_pRoom->Get_Terrain()->Get_TileData();
		//const TILEINFO _info = pView->m_pRoom->Get_TileInfo();
		//WriteFile(hFile, &_info, sizeof(TILEINFO), &dwByte, nullptr);
		for (auto& pTile : vecTileData) {
			TILE _tile= pTile->Get_Tile();
			WriteFile(hFile, &_tile, sizeof(TILE), &dwByte, nullptr);
		}
		CloseHandle(hFile); 
	}
}

//Load
void CMapTool::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog Dlg(TRUE,// 열기 모드(TRUE) 혹은 저장 모드(FALSE) 어떤것 할 것인지. 
		L"dat",// 디폴트 확장자 명 
		L"*.dat",// 디폴트 파일 이름 
		OFN_OVERWRITEPROMPT);// 창에 기본 상태를 설정해줄 수 있음. 애는 중복파일 저장시 경고메시지 띄워줌.  
	TCHAR szFilePath[MAX_PATH]{};
	//D:\박병건\119\FrameWork (6) (2)
	GetCurrentDirectory(MAX_PATH, szFilePath);
	PathRemoveFileSpec(szFilePath);
	// D:\박병건\119\FrameWork (6) (2)\Data
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
	//	TILEINFO _info;
		//ReadFile(hFile, &_info, sizeof(TILEINFO), &dwByte, nullptr);
	//	pView->m_pRoom->Set_TileInfo(_info);
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
