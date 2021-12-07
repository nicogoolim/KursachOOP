#pragma once


// Диалоговое окно EdtMarksDLG

class EdtMarksDLG : public CDialogEx
{
	DECLARE_DYNAMIC(EdtMarksDLG)

public:
	EdtMarksDLG(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~EdtMarksDLG();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = EditMarksStud };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString fioEdit;
	int courseEdit;
	int groupEdit;
	CString discEdit;
	int markEdit;
	afx_msg void OnBnClickedButton1();
};
