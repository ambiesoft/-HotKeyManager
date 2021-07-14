#include "pch.h"
#include "HotKeyManager.h"
#include "CHotKeyManagerDialog.h"
#include "CHotKeyDialog.h"
#include "afxdialogex.h"


IMPLEMENT_DYNAMIC(CHotKeyManagerDialog, CDialogEx)

CHotKeyManagerDialog::CHotKeyManagerDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HOTKEYMANAGER, pParent)
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





BOOL CHotKeyManagerDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_lstKeys.InsertColumn(0, L"aaa", 0, 30);
	m_lstKeys.InsertColumn(1, L"bbbbb", 0, 30);

	return TRUE;
}


void CHotKeyManagerDialog::OnBnClickedButtonAdd()
{
	CHotKeyDialog dlg;
	dlg.DoModal();
}
