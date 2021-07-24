// MonsterTool.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "MonsterTool.h"
#include "afxdialogex.h"


// CMonsterTool 대화 상자입니다.

IMPLEMENT_DYNAMIC(CMonsterTool, CDialog)

CMonsterTool::CMonsterTool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_MONSTERTOOL, pParent)
	,m_MonsterNameBox(_T(""))
	,m_MonsterList(_T(""))
	, PosX(0)
	, PosY(0)
	, SIZEX(0)
	, SIZEY(0)
	, SPEEDX(0)
	, SPEEDY(0)
	, RECTX(0)
	, RECTY(0)
	, DETECTX(0)
	, DETECTY(0)
{

}

CMonsterTool::~CMonsterTool()
{
}

void CMonsterTool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MONSTERNAMEBOX, m_MonsterNameBox);
	DDX_Text(pDX, IDC_MONSTERLIST, m_MonsterList);
	DDX_Text(pDX, IDC_POSX, PosX);
	DDX_Text(pDX, IDC_POSY, PosY);
	DDX_Text(pDX, IDC_SIZEX, SIZEX);
	DDX_Text(pDX, IDC_SIZEY, SIZEY);
	DDX_Text(pDX, IDC_SPEEDX, SPEEDX);
	DDX_Text(pDX, IDC_SPEEDY, SPEEDY);
	DDX_Text(pDX, IDC_RECTX, RECTX);
	DDX_Text(pDX, IDC_RECTY, RECTY);
	DDX_Text(pDX, IDC_DETECTX, DETECTX);
	DDX_Text(pDX, IDC_DETECTY, DETECTY);
}


BEGIN_MESSAGE_MAP(CMonsterTool, CDialog)
	ON_BN_CLICKED(IDC_MONSTERADD, &CMonsterTool::OnBnClickedMonsteradd)
	ON_BN_CLICKED(IDC_MONSTERDELETE, &CMonsterTool::OnBnClickedMonsterdelete)
	ON_BN_CLICKED(IDC_MONSTERCHANGE, &CMonsterTool::OnBnClickedMonsterchange)
	ON_BN_CLICKED(IDC_CHANGE, &CMonsterTool::OnBnClickedChange)
	ON_BN_CLICKED(IDC_SAVE, &CMonsterTool::OnBnClickedSave)
	ON_BN_CLICKED(IDC_LOAD, &CMonsterTool::OnBnClickedLoad)
	ON_LBN_SELCHANGE(IDC_MONSTERLIST, &CMonsterTool::OnLbnSelchangeMonsterlist)
END_MESSAGE_MAP()


// CMonsterTool 메시지 처리기입니다.



void CMonsterTool::OnBnClickedMonsteradd()
{

}


void CMonsterTool::OnBnClickedMonsterdelete()
{

}


void CMonsterTool::OnBnClickedMonsterchange()
{

}



void CMonsterTool::OnBnClickedChange()
{

}



void CMonsterTool::OnBnClickedSave()
{

}


void CMonsterTool::OnBnClickedLoad()
{
	
}


void CMonsterTool::OnLbnSelchangeMonsterlist()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
