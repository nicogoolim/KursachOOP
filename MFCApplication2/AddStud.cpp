// AddStud.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "AddStud.h"
#include "afxdialogex.h"


// Диалоговое окно AddStud

IMPLEMENT_DYNAMIC(AddStud, CDialogEx)

AddStud::AddStud(CWnd* pParent /*=nullptr*/)
	: CDialogEx(AddStudDlg, pParent)
{

}

AddStud::~AddStud()
{
}

void AddStud::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddStud, CDialogEx)
END_MESSAGE_MAP()


// Обработчики сообщений AddStud
