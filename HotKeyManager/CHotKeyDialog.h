#pragma once


class CHotKeyDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CHotKeyDialog)

public:
	CHotKeyDialog(CWnd* pParent = nullptr);   // 標準コンストラクター
	virtual ~CHotKeyDialog();

// ダイアログ データ
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HOTKEY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bCtrl;
	BOOL m_bShift;
	BOOL m_bAlt;
	CComboBox m_cmbKeys;
	virtual BOOL OnInitDialog();
};
