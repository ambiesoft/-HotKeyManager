#pragma once


// CHotKeyManagerDialog ダイアログ

class CHotKeyManagerDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CHotKeyManagerDialog)

public:
	CHotKeyManagerDialog(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CHotKeyManagerDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HOTKEYMANAGER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl m_lstKeys;
	afx_msg void OnBnClickedButtonAdd();
};
