#pragma once


// Диалоговое окно AddStudDlg

class AddStudDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddStudDlg)

public:
	AddStudDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~AddStudDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddStud };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString AddFio;
	int AddGroup;
	int AddCourse;
	afx_msg void OnBnClickedButton1();
};
