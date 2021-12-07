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
	, ChooseDisc(_T(""))
{

}

DecanDlg::~DecanDlg()
{
}

void DecanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON2, LessBut);
	DDX_Control(pDX, IDC_BUTTON1, AllLessBut);
	DDX_Control(pDX, IDC_COMBO1, LessComboList);
	DDX_Text(pDX, IDC_EDIT1, ChooseDisc);
	DDX_Control(pDX, IDC_LIST1, MarksListDec);
}


BEGIN_MESSAGE_MAP(DecanDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DecanDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DecanDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &DecanDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &DecanDlg::OnBnClickedRadio2)
END_MESSAGE_MAP()


// Обработчики сообщений DecanDlg
extern vector<Student> arrStud;
extern vector<lessons> arrLess;
extern vector<marks> arrMarks;

BOOL DecanDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	for each (lessons var in arrLess)
	{
		CString S;
		S = var.name.c_str();
		LessComboList.InsertString(-1, S);
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // Исключение: страница свойств OCX должна возвращать значение FALSE
}


void DecanDlg::OnBnClickedButton1()
{
	int sa = MarksListDec.GetCount();
	for (int i = 0; i < sa; i++)
	{
		MarksListDec.DeleteString(0);
	}
	vector<int> marksByLess;
	for each (Student var in arrStud)
	{
		vector<int> marksByStud;
		CString S(var.fio.c_str());
		MarksListDec.InsertString(-1, S);
		marks curMarks = marksByStudId(arrMarks, var.id);
		string str;
		for (int i = 0; i < curMarks.idLess.size(); i++)
		{
			str = lessByIdStr(arrLess, curMarks.idLess[i]) + " " + (char)('0' + curMarks.mark[i]);
			marksByLess.push_back(curMarks.mark[i]);
			marksByStud.push_back(curMarks.mark[i]);
			CString S(str.c_str());
			MarksListDec.InsertString(-1, S);
		}

	}
	string str = "---------------------------------------------------------------------------------------------------------------------------------------------------";
	CString S(str.c_str());
	MarksListDec.InsertString(-1, S);
	double AvgMark = 0;
	for each (int var in marksByLess)
	{
		AvgMark += var;
	}
	AvgMark /= marksByLess.size();
	str = "Средний балл = " + to_string(AvgMark);
	CString Ss(str.c_str());
	MarksListDec.InsertString(-1, Ss);
}


void DecanDlg::OnBnClickedButton2()
{
	int sa = MarksListDec.GetCount();
	for (int i = 0; i < sa; i++)
	{
		MarksListDec.DeleteString(0);
	}
	int SelectedLess = LessComboList.GetCurSel() + 1;
	if (SelectedLess == 0)
	{
		MessageBox(L"Вы не выбрали дисцплину");
	}
	else {
		lessons ChoosedLess;
		vector<int> marksByLess;
		for each (lessons var in arrLess)
		{
			if (var.nameById(SelectedLess))
			{
				ChoosedLess = var;
			}
		}
		for each (marks var in arrMarks)
		{
			for (int i = 0; i < var.idLess.size(); i++)
			{
				if (var.idLess[i] == ChoosedLess.id) {
					Student curStud = StudById(arrStud, var.Studid);
					marksByLess.push_back(var.mark[i]);
					string str = curStud.fio + " " + (char)('0' + var.mark[i]);
					CString S(str.c_str());
					MarksListDec.InsertString(-1, S);
				}
			}
		}
		string str = "---------------------------------------------------------------------------------------------------------------------------------------------------";
		CString S(str.c_str());
		MarksListDec.InsertString(-1, S);
		double AvgMark = 0;
		for each (int var in marksByLess)
		{
			AvgMark += var;
		}
		AvgMark /= marksByLess.size();
		str = "Средний балл = " + to_string(AvgMark);
		CString Ss(str.c_str());
		MarksListDec.InsertString(-1, Ss);
	}
}


void DecanDlg::OnBnClickedRadio1()
{
	UpdateData(true);
	AllLessBut.ShowWindow(SW_SHOW);
	LessBut.ShowWindow(SW_HIDE);
	LessComboList.ShowWindow(SW_HIDE);
	CString S;
	ChooseDisc = S;
	UpdateData(false);
}


void DecanDlg::OnBnClickedRadio2()
{
	UpdateData(true);
	AllLessBut.ShowWindow(SW_HIDE);
	LessBut.ShowWindow(SW_SHOW);
	LessComboList.ShowWindow(SW_SHOW);
	string str = "Выберите дисциплину";
	CString S(str.c_str());
	ChooseDisc = S;
	UpdateData(false);
}
