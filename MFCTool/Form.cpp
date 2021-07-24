// Form.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "Form.h"


// CForm

IMPLEMENT_DYNCREATE(CForm, CFormView)

CForm::CForm()
	: CFormView(IDD_FORM)
{

}

CForm::~CForm()
{
}

void CForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_BUTTON2, m_tObjectTool);
	//DDX_Control(pDX, IDC_BUTTON3, m_tMonsterTool);
	//DDX_Control(pDX, IDC_BUTTON5, m_tUITool);
	//DDX_Control(pDX, IDC_BUTTON4, m_tRoomTool);
}

BEGIN_MESSAGE_MAP(CForm, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CForm::OnBnClickedUnitTool)
	ON_BN_CLICKED(IDC_BUTTON6, &CForm::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &CForm::ObjectTool)
	ON_BN_CLICKED(IDC_BUTTON3, &CForm::MonsterTool)
	ON_BN_CLICKED(IDC_BUTTON4, &CForm::RoomTool)
	ON_BN_CLICKED(IDC_BUTTON5, &CForm::UITool)
END_MESSAGE_MAP()


// CForm �����Դϴ�.

#ifdef _DEBUG
void CForm::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CForm �޽��� ó�����Դϴ�.

//UnitTool 
void CForm::OnBnClickedUnitTool()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	//ERR_MSG(L"������ �� �ű⼭ ������?��������������������������"); 
	if (m_tUnitTool.GetSafeHwnd() == nullptr)
		m_tUnitTool.Create(IDD_UNITTOOL); 

	m_tUnitTool.ShowWindow(SW_SHOW);
}

//MapTool 
void CForm::OnBnClickedButton6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_tMapTool.GetSafeHwnd() == nullptr)
		m_tMapTool.Create(IDD_MAPTOOL);

	m_tMapTool.ShowWindow(SW_SHOW);
}


void CForm::ObjectTool()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_tObjectTool.GetSafeHwnd() == nullptr)
		m_tObjectTool.Create(IDD_OBJECTTOOL);

	m_tObjectTool.ShowWindow(SW_SHOW);
}


void CForm::MonsterTool()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_tMonsterTool.GetSafeHwnd() == nullptr)
		m_tMonsterTool.Create(IDD_MONSTERTOOL);

	m_tMonsterTool.ShowWindow(SW_SHOW);
}


void CForm::RoomTool()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	if (m_tRoomTool.GetSafeHwnd() == nullptr)
		m_tRoomTool.Create(IDD_ROOMTOOL);

	m_tRoomTool.ShowWindow(SW_SHOW);
}


void CForm::UITool()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_tUITool.GetSafeHwnd() == nullptr)
		m_tUITool.Create(IDD_UITOOL);

	m_tUITool.ShowWindow(SW_SHOW);
}