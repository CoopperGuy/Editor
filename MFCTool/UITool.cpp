// UITool.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "UITool.h"
#include "afxdialogex.h"


// CUITool 대화 상자입니다.

IMPLEMENT_DYNAMIC(CUITool, CDialog)

CUITool::CUITool(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_UITOOL, pParent)
{

}

CUITool::~CUITool()
{
}

void CUITool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUITool, CDialog)
END_MESSAGE_MAP()


// CUITool 메시지 처리기입니다.
