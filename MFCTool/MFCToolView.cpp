
// MFCToolView.cpp : CMFCToolView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFCTool.h"
#endif

#include "MFCToolDoc.h"
#include "MFCToolView.h"
#include "Room.h"
#include "Terrain.h"
#include "MainFrm.h"
#include "MiniView.h"
#include "Form.h"
#include "MapTool.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
HWND g_hWND; 

// CMFCToolView

IMPLEMENT_DYNCREATE(CMFCToolView, CScrollView)

BEGIN_MESSAGE_MAP(CMFCToolView, CScrollView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CMFCToolView ����/�Ҹ�

CMFCToolView::CMFCToolView()
	:m_pRoom(nullptr)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_fAngle = 0; 
	m_iDrawID = 0; 
	m_iMaxDrawID = 10; 
}

CMFCToolView::~CMFCToolView()
{
	m_pRoom->Release_Room();
	CTexture_Manager::Destroy_Instance();
	CGraphic_Device::Destroy_Instance(); 
	Safe_Delete(m_pRoom);
	m_pRoom = nullptr;
}

BOOL CMFCToolView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CScrollView::PreCreateWindow(cs);
}

// CMFCToolView �׸���

void CMFCToolView::OnDraw(CDC* /*pDC*/)
{
	CMFCToolDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CGraphic_Device::Get_Instance()->Render_Begin();
	m_pRoom->Render_Room();
	CGraphic_Device::Get_Instance()->Render_End();

// 	m_fAngle += 5.f; 
// 	++m_iDrawID;
// 	if (m_iDrawID > m_iMaxDrawID)
// 	{
// 		m_iDrawID = 0; 
// 	}
// 	CGraphic_Device::Get_Instance()->Render_Begin();
// 
// 	const TEXINFO* pTexInfo = CTexture_Manager::Get_Instance()->Get_TexInfo_Texture(L"Player", L"Dash", m_iDrawID);
// 	D3DXMATRIX matScale, matRotZ, matTrans, matWorld; 
// 	// �̹��� ���� ����. 
// 	D3DXMatrixScaling(&matScale, 1.0f, 1.0f, 0.f); 
// 	//D3DXMatrixRotationZ(&matRotZ, D3DXToRadian(m_fAngle));
// 	D3DXMatrixTranslation(&matTrans, 400.f, 300.f, 0.f); 
// 	matWorld = matScale * /*matRotZ * */matTrans; 
// 
// 	float fCenterX = pTexInfo->tImageInfo.Width >> 1; 
// 	float fCenterY = pTexInfo->tImageInfo.Height >> 1; 
// 	RECT rc{ 0, 0, 400, 300 };
// 	CGraphic_Device::Get_Instance()->Get_Sprite()->SetTransform(&matWorld);
// 	CGraphic_Device::Get_Instance()->Get_Sprite()->Draw(pTexInfo->pTexture, nullptr/*&rc*/, &D3DXVECTOR3(fCenterX, fCenterY, 0.f), nullptr, D3DCOLOR_ARGB(255,255,0,0) );
// 	CGraphic_Device::Get_Instance()->Render_End(); 
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
// 	pDC->Rectangle(100, 100, 200, 200); 
// 	pDC->Ellipse(100, 100, 200, 200); 
}


// CMFCToolView �μ�

BOOL CMFCToolView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFCToolView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFCToolView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMFCToolView ����

#ifdef _DEBUG
void CMFCToolView::AssertValid() const
{
	
	CScrollView::AssertValid();
}

void CMFCToolView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCToolDoc* CMFCToolView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCToolDoc)));
	return (CMFCToolDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCToolView �޽��� ó����


void CMFCToolView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	g_hWND = m_hWnd; 
	// �̰� ��ũ�� ���� ����� DC�� �׸��׸��� �͵� ���. 
	SetScrollSizes(MM_TEXT, CSize(TILECX * TILEX, (TILECY >> 1)* TILEY));//���� �ʿ�
	// ������ â ũ�� ������. 
	CMainFrame* pMain = dynamic_cast<CMainFrame*>(::AfxGetApp()->GetMainWnd());
	RECT rcMain{}; 
	pMain->GetWindowRect(&rcMain); 
	rcMain.right = rcMain.right - rcMain.left; //1640 - 100 1540
	rcMain.bottom = rcMain.bottom - rcMain.top; 
	rcMain.left = 0; 
	rcMain.top = 0; 
	//.......................................................................
	RECT rcView{}; 
	GetClientRect(&rcView);

	int iGapX = rcMain.right - rcView.right; 
	int iGapY = rcMain.bottom - rcView.bottom; 

	pMain->SetWindowPos(nullptr, 0, 0, WINCX + iGapX + 1, WINCY + iGapY + 1, SWP_NOMOVE); 

	if (FAILED(CGraphic_Device::Get_Instance()->Ready_Graphic_Device()))
		return; 
	L"../Texture/Stage/Terrain/Tile/Tile%d.png";
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX,L"../Texture/Stage/Terrain/Tile/Tile%d.png", L"Terrain", L"Tile", 36)))
		return; 
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Stage/Player/Attack/AKIHA_AKI01_00%d.png", L"Player", L"Attack", 6)))
		return;
	if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Texture/Stage/Player/Dash/AKIHA_AKI13_00%d.png", L"Player", L"Dash", 11)))
		return;
	//if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::MULTI_TEX, L"../Image/Moster/RED/RED%d.png", L"Monster", L"Walk", 4)))
	//	return;
	//if (FAILED(CTexture_Manager::Get_Instance()->Insert_Texture(CTexture_Manager::SINGLE_TEX, L"../Texture/Stage/Player/Dash/AKIHA_AKI13_00%d.png", L"Player", L"Dash", 11)))
	//	return;

	m_pRoom = CRoom::Create({130,68,20,30});//Ÿ�� ũ��,���� �Ѱ������ ������
	if (nullptr == m_pRoom)
		return; 
	m_pRoom->Set_View(this);

}


void CMFCToolView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
// 	TCHAR szBuf[MAX_PATH]{}; 
// 	// ���ڿ� ��� ����ϴ� �Լ�. 
// 	swprintf_s(szBuf, L"X : %d, Y : %d", point.x, point.y);
// 
// 	ERR_MSG(szBuf); 
	D3DXVECTOR3 vMouse{ float(point.x) + GetScrollPos(SB_HORZ), float(point.y) + GetScrollPos(SB_VERT), 0.f };
	
	CMainFrame* pMainFrame = dynamic_cast<CMainFrame*>(AfxGetApp()->GetMainWnd());
	CForm* pForm = dynamic_cast<CForm*>(pMainFrame->m_tSecondSplitter.GetPane(1, 0)); 
	DWORD dwDrawID = pForm->m_tMapTool.m_dwDrawID;

	m_pRoom->Change_Tile(vMouse, dwDrawID);
	Invalidate(FALSE); 
	
	CMiniView* pMiniView = dynamic_cast<CMiniView*>(pMainFrame->m_tSecondSplitter.GetPane(0, 0));
	pMiniView->Invalidate(FALSE); 
	CScrollView::OnLButtonDown(nFlags, point);
}
