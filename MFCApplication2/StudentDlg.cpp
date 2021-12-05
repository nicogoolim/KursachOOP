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

void StudentDlg::OnBnClickedButton1()
{
	UpdateData(true);
	
	
	

	UpdateData(false);
}


BOOL StudentDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	string pathStud = "Students.txt";
	string pathMarks = "marks.txt";
	string pathLess = "lesson.txt";

	FileWorker<Student> fwstud(pathStud);
	arrStud = fwstud.read();
	FileWorker<marks> marks(pathMarks);
	for each (Student var in arrStud)
	{
		CString S;
		S = var.fio.c_str();
		StudList.AddString(S);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}

