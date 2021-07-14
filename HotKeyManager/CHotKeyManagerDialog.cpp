
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
	KOKOKARA
}
BOOL CHotKeyManagerDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_lstKeys.SetExtendedStyle(m_lstKeys.GetExtendedStyle() |
		LVS_EX_FULLROWSELECT);

	for (auto&& pair : m_idToHK)
	{
		m_lstKeys.InsertColumn(m_lstKeys.GetItemCount(),
			m_fnGetNameFromID(toStdWstringFromUtf8(pair.first).c_str()), 0, 100);
	}

	return TRUE;
}


void CHotKeyManagerDialog::OnBnClickedButtonAdd()
{
	WORD key = 0;
	if (!GetHotKeyFromUser(*this, L"TTTTTTTTT", &key))
		return;

	m_lstKeys.InsertItem(0, GetHotkeyStringW(key).c_str());
}
