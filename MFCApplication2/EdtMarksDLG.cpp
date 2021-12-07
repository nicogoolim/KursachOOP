// EdtMarksDLG.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "EdtMarksDLG.h"
#include "afxdialogex.h"


// Диалоговое окно EdtMarksDLG
extern int choosedStudent;
extern int choosedLess;
extern vector<Student> arrStud;
extern vector<lessons> arrLess;
extern vector<marks> arrMarks;
IMPLEMENT_DYNAMIC(EdtMarksDLG, CDialogEx)

EdtMarksDLG::EdtMarksDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(EditMarksStud, pParent)
	, fioEdit(_T(""))
	, courseEdit(0)
	, groupEdit(0)
	, discEdit(_T(""))
	, markEdit()
{

}

EdtMarksDLG::~EdtMarksDLG()
{
}

void EdtMarksDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, fioEdit);
	DDX_Text(pDX, IDC_EDIT2, courseEdit);
	DDX_Text(pDX, IDC_EDIT4, groupEdit);
	DDX_Text(pDX, IDC_EDIT5, discEdit);
	DDX_Text(pDX, IDC_EDIT3, markEdit);
}


BEGIN_MESSAGE_MAP(EdtMarksDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &EdtMarksDLG::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений EdtMarksDLG


BOOL EdtMarksDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	Student curStud = StudById(arrStud, choosedStudent);
	marks curMarks = marksByStudId(arrMarks, curStud.id);
	string curLess = lessByIdStr(arrLess, choosedLess);
	CString FIO(curStud.fio.c_str());
	CString disc(curLess.c_str());
	UpdateData(true);
	fioEdit = FIO;
	groupEdit = curStud.group;
	courseEdit = curStud.course;
	discEdit = disc;
	bool isChecked=false;
	for each (int var in curMarks.idLess)
	{
		if (var == choosedLess) {
			isChecked = true;
		}
	}
	if (isChecked)
	{
		markEdit = curMarks.markByLess(choosedLess);
	}
	else {
		markEdit = 0;
	}
	UpdateData(false);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}


void EdtMarksDLG::OnBnClickedButton1()
{
	FileReader<marks> newMarkAdder("marks.txt");
	UpdateData(true);
	Student curStud = StudById(arrStud, choosedStudent);
	marks curMarks = marksByStudId(arrMarks, curStud.id);
	arrMarks = addMarks(curStud, lessById(arrLess,choosedLess), arrMarks, markEdit);
	int a = 0;
	newMarkAdder.write(arrMarks);
	UpdateData(false);
}
