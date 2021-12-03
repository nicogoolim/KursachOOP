// DecanDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "DecanDlg.h"
#include "afxdialogex.h"


// Диалоговое окно DecanDlg

IMPLEMENT_DYNAMIC(DecanDlg, CDialogEx)

DecanDlg::DecanDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DecDlg, pParent)
{

}

DecanDlg::~DecanDlg()
{
}

void DecanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DecanDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений DecanDlg
