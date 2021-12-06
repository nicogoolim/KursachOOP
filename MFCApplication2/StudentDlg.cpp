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

	
	, FIOblank(_T(""))
	, Groupblank(_T(""))
	, Courseblank(_T(""))
{

}

StudentDlg::~StudentDlg()
{
}



void StudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, STUD_LIST, MarksList);
	//DDX_Control(pDX, IDC_StudList, StudList);
	DDX_Control(pDX, IDC_StudList, StudList);
	DDX_Text(pDX, IDC_EDIT1, FIOblank);
	DDX_Text(pDX, IDC_EDIT2, Groupblank);
	DDX_Text(pDX, IDC_EDIT3, Courseblank);
}


BEGIN_MESSAGE_MAP(StudentDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &StudentDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &StudentDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений StudentDlg


void StudentDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}
vector<Student> arrStud;
vector<lessons> arrLess;
vector<marks> arrMarks;
void StudentDlg::OnBnClickedButton1()
{
	Student curStudent;
	UpdateData(true);
	int sa = MarksList.GetCount();
	for (int i = 0; i < sa; i++)
	{
		MarksList.DeleteString(0);
	}
	int selectedStud = StudList.GetCurSel()+1;
	marks marksOfStud;
	vector<string> lessOfStud;
	for each (Student var in arrStud)
	{
		if (var.studBuyId(selectedStud)) {
			curStudent = var;
		}
	}
	for each (marks var in arrMarks)
	{
		if (var.Studid == selectedStud) marksOfStud = var;
	}
	for each (int var in marksOfStud.idLess)
	{
		for (int i = 0; i < arrLess.size(); i++)
		{
			if (arrLess[i].nameById(var))
			{
				lessOfStud.push_back(arrLess[i].name);
			}
			
		}
		
	}
	CString sName(curStudent.fio.c_str());
	CString sGroup;
	sGroup.Format(_T("Группа #%i"), curStudent.group);
	CString sCourse;
	sCourse.Format(_T("Курс #%i"), curStudent.course);
	FIOblank = sName;
	Groupblank = sGroup;
	Courseblank = sCourse;
	int a = 0;
	for (int i = 0; i < marksOfStud.mark.size(); i++)
	{
		string str = lessOfStud[i] + " " + (char)('0' + marksOfStud.mark[i]);
		CString S(str.c_str());
		MarksList.InsertString(-1, S);
	}
	UpdateData(false);
}


BOOL StudentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	for each (Student var in arrStud)
	{
		CString S;
		S = var.fio.c_str();
		StudList.InsertString(-1,S);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}

