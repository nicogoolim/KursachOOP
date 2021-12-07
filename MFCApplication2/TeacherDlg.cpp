// TeacherDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCApplication2.h"
#include "TeacherDlg.h"
#include "afxdialogex.h"
#include "EdtMarksDLG.h"


// Диалоговое окно TeacherDlg
extern vector<Student> arrStud;
extern vector<lessons> arrLess;
extern vector<marks> arrMarks;
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
	DDX_Control(pDX, IDC_COMBO1, LessListBox);
	DDX_Control(pDX, IDC_LIST1, StudListBox);
}
	

BEGIN_MESSAGE_MAP(TeacherDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TeacherDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TeacherDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// Обработчики сообщений TeacherDlg


BOOL TeacherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	for each (lessons var in arrLess)
	{
		CString S;
		S = var.name.c_str();
		LessListBox.InsertString(-1, S);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}


void TeacherDlg::OnBnClickedButton1()
{
	int sa = StudListBox.GetCount();
	for (int i = 0; i < sa; i++)
	{
		StudListBox.DeleteString(0);
	}
	int selectedLess = LessListBox.GetCurSel() + 1;
	for each (Student var in arrStud)
		{
			vector<int> marksByStud;
			string str;
			str = var.fio.c_str();
			marks curMark = marksByStudId(arrMarks, var.id);
			for (int i = 0; i < curMark.idLess.size(); i++)
			{
				if (curMark.idLess[i]==selectedLess)
				{
					str = str +  "   " + (char)('0' + curMark.mark[i]);
					break;
				}
				if ((i  == curMark.idLess.size()-1)) {
					str = str + "  оценка не проставлена";
				}
				

			
			}
			CString S(str.c_str());
			StudListBox.InsertString(-1, S);
			

		}
}

int choosedStudent;
int choosedLess;
void TeacherDlg::OnBnClickedButton2()
{
	 choosedStudent = StudListBox.GetCurSel()+1;
	 choosedLess = LessListBox.GetCurSel() + 1;
	ShowWindow(SW_HIDE);
	EdtMarksDLG win;
	win.DoModal();
	ShowWindow(SW_SHOW);
}
