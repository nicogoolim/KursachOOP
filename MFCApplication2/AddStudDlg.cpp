// AddStudDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "AddStudDlg.h"
#include "afxdialogex.h"


// Диалоговое окно AddStudDlg

IMPLEMENT_DYNAMIC(AddStudDlg, CDialogEx)

AddStudDlg::AddStudDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AddStud, pParent)
	, AddFio(_T(""))
	, AddGroup(0)
	, AddCourse(0)
{

}

AddStudDlg::~AddStudDlg()
{
}

void AddStudDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, AddFio);
	DDX_Text(pDX, IDC_EDIT2, AddGroup);
	DDX_Text(pDX, IDC_EDIT3, AddCourse);
}


BEGIN_MESSAGE_MAP(AddStudDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AddStudDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений AddStudDlg


void AddStudDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
}
