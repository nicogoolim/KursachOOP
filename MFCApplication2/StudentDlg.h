#pragma once


// Диалоговое окно StudentDlg

class StudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StudentDlg)

public:
	StudentDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~StudentDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = StudDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
