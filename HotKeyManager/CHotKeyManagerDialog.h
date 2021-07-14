#pragma once


#include "framework.h"
#include <afxdialogex.h>

#include "exported.h"

class CHotKeyManagerDialog : public CDialogEx
{
private:
	constexpr static char SECTION_HOLDER[] = "Holder";
	constexpr static char SECTION_HOTKEY[] = "HotKey";
	constexpr static char KEY_ID[] = "ID";
	
	std::vector<std::pair<std::string, int>> m_idToHK;

	DECLARE_DYNAMIC(CHotKeyManagerDialog)
	FnGetNameFromID m_fnGetNameFromID = nullptr;

public:
	CHotKeyManagerDialog(CWnd* pParent, FnGetNameFromID fnGetNameFromID);
	virtual ~CHotKeyManagerDialog();

	BOOL LoadFromIni(LPCWSTR pIniFile);
	BOOL SaveToIni(LPCWSTR pIniFile);
	
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
