
#include <string>
#include <afxdialogex.h>
#include "../../profile/cpp/Profile/include/ambiesoft.profile.h"

#include "HotKeyManager.h"
#include "CHotKeyManagerDialog.h"

#include "../../HotKeyDialog/HotKeyDialog/HotKeyDialog.h"
#include "../../lsMisc/GetHotkeyString.h"
#include "../../lsMisc/UTF16toUTF8.h"

using namespace Ambiesoft;
using namespace std;

IMPLEMENT_DYNAMIC(CHotKeyManagerDialog, CDialogEx)


CHotKeyManagerDialog::CHotKeyManagerDialog(CWnd* pParent, FnGetNameFromID fnGetNameFromID)
	: CDialogEx(IDD_DIALOG_HOTKEYMANAGER, pParent),
	  m_fnGetNameFromID(fnGetNameFromID)
{

}

CHotKeyManagerDialog::~CHotKeyManagerDialog()
{
}

void CHotKeyManagerDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HOTKEYS, m_lstKeys);
}


BEGIN_MESSAGE_MAP(CHotKeyManagerDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CHotKeyManagerDialog::OnBnClickedButtonAdd)
END_MESSAGE_MAP()

BOOL CHotKeyManagerDialog::LoadFromIni(LPCWSTR pIniFile)
{
	try
	{
		Profile::CHashIni ini(Profile::ReadAll(wstring(pIniFile), true));
		int count = 0;
		vector<string> vid;
		Profile::GetStringArray(SECTION_HOLDER, KEY_ID, vid, ini);
		for (auto&& id : vid)
		{
			int hotkey = 0;
			if (Profile::GetInt(SECTION_HOTKEY, id, 0, hotkey, ini))
			{
				m_idToHK.push_back({ id, hotkey });
			}
		}
	}
	catch (file_not_found_error&)
	{

	}
	catch (exception&)
	{
		return FALSE;
	}
	return TRUE;
}
BOOL CHotKeyManagerDialog::SaveToIni(LPCWSTR pIniFile)
{
	// TODO: What is name and id?
	// The code below is random
	try
	{
		Profile::CHashIni ini(Profile::ReadAll(wstring(pIniFile), true));
		int count = 0;
		vector<string> vid;
		for (int i = 0; i < m_lstKeys.GetItemCount(); ++i)
		{
			CString name = m_lstKeys.GetItemText(i, 0);
			vid.push_back(toStdUtf8String((LPCWSTR)name));
		}
		Profile::WriteStringArray(SECTION_HOLDER, KEY_ID, vid, ini);


		Profile::WriteAll(ini, wstring(pIniFile));
	}
	catch (exception&)
	{
		return FALSE;
	}
	return TRUE;

}
BOOL CHotKeyManagerDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_lstKeys.SetExtendedStyle(m_lstKeys.GetExtendedStyle() |
		LVS_EX_FULLROWSELECT);

	m_lstKeys.InsertColumn(0, L"Name", 0, 200);
	m_lstKeys.InsertColumn(0, L"HotKey", 0, 400);
	for (auto&& pair : m_idToHK)
	{
		int inserted = m_lstKeys.InsertItem(m_lstKeys.GetItemCount(),
			m_fnGetNameFromID(toStdWstringFromUtf8(pair.first).c_str()));

		m_lstKeys.SetItemText(inserted, 1, GetHotkeyControlStringW(pair.second).c_str());
	}

	return TRUE;
}


void CHotKeyManagerDialog::OnBnClickedButtonAdd()
{
	WORD key = 0;
	if (!GetHotKeyFromUser(*this, L"TTTTTTTTT", &key))
		return;

	wstring name = L"MyName";
	name += to_wstring(m_lstKeys.GetItemCount());
	int inserted = m_lstKeys.InsertItem(m_lstKeys.GetItemCount(),
		name.c_str());
	m_lstKeys.SetItemText(inserted, 1, GetHotkeyControlStringW(key).c_str());
}
