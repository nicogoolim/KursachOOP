#pragma once


// Диалоговое окно AddStud

class AddStud : public CDialogEx
{
	DECLARE_DYNAMIC(AddStud)

public:
	AddStud(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~AddStud();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = AddStudDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
