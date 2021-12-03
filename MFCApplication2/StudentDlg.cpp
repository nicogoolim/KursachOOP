// StudentDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "StudentDlg.h"
#include "afxdialogex.h"


// Диалоговое окно StudentDlg

IMPLEMENT_DYNAMIC(StudentDlg, CDialogEx)

StudentDlg::StudentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(StudDlg, pParent)
{

}

StudentDlg::~StudentDlg()
{
}

void StudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(StudentDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &StudentDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Обработчики сообщений StudentDlg


void StudentDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}
