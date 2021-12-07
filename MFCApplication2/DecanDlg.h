#pragma once


// Диалоговое окно DecanDlg

class DecanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DecanDlg)

public:
	DecanDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~DecanDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = DecDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	CButton LessBut;
	CButton AllLessBut;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	CComboBox LessComboList;
	afx_msg void OnBnClickedRadio2();
	CString ChooseDisc;
	CListBox MarksListDec;
};
