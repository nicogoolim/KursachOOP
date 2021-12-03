// TeacherDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "TeacherDlg.h"
#include "afxdialogex.h"


// Диалоговое окно TeacherDlg

IMPLEMENT_DYNAMIC(TeacherDlg, CDialogEx)

TeacherDlg::TeacherDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(TeachDlg, pParent)
{

}

TeacherDlg::~TeacherDlg()
{
}

void TeacherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TeacherDlg, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений TeacherDlg
