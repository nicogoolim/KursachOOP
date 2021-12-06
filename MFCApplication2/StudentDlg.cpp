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
	DDX_Control(pDX, STUD_LIST, MarksList);
	//DDX_Control(pDX, IDC_StudList, StudList);
	DDX_Control(pDX, IDC_StudList, StudList);
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
	UpdateData(true);
	int sa = MarksList.GetCount();
	for (int i = 0; i < sa; i++)
	{
		MarksList.DeleteString(0);
	}
	int selectedStud = StudList.GetCurSel()+1;
	marks marksOfStud;
	vector<string> lessOfStud;
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

	string pathStud = "Students.txt";
	string pathMarks = "marks.txt";
	string pathLess = "lesson.txt";

	FileReader<Student> fwStud(pathStud);
	FileReader<marks> fwMarks(pathMarks);
	FileReader<lessons> fwLess(pathLess);
	arrStud = fwStud.read();
	arrMarks = fwMarks.read();
	arrLess = fwLess.read();
	for each (Student var in arrStud)
	{
		CString S;
		S = var.fio.c_str();
		StudList.InsertString(-1,S);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}

