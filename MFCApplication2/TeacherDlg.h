#pragma once


// Диалоговое окно TeacherDlg

class TeacherDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TeacherDlg)

public:
	TeacherDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~TeacherDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = TeachDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CComboBox LessListBox;
	CListBox StudListBox;
	afx_msg void OnBnClickedButton2();
};
