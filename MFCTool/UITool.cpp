// UITool.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFCTool.h"
#include "UITool.h"
#include "afxdialogex.h"


// CUITool ��ȭ �����Դϴ�.

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


// CUITool �޽��� ó�����Դϴ�.
