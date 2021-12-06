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
extern vector<Student> arrStud;
extern vector<lessons> arrLess;
extern vector<marks> arrMarks;

BOOL DecanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}
