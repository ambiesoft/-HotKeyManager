#include "pch.h"
#include "HotKeyManager.h"
#include "CHotKeyDialog.h"
#include "afxdialogex.h"


IMPLEMENT_DYNAMIC(CHotKeyDialog, CDialogEx)

CHotKeyDialog::CHotKeyDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_HOTKEY, pParent)
	, m_bCtrl(FALSE)
	, m_bShift(FALSE)
	, m_bAlt(FALSE)
{

}

CHotKeyDialog::~CHotKeyDialog()
{
}

void CHotKeyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_CTRL, m_bCtrl);
	DDX_Check(pDX, IDC_CHECK_SHIFT, m_bShift);
	DDX_Check(pDX, IDC_CHECK_ALT, m_bAlt);
	DDX_Control(pDX, IDC_COMBO_KEYS, m_cmbKeys);
}


BEGIN_MESSAGE_MAP(CHotKeyDialog, CDialogEx)
END_MESSAGE_MAP()







BOOL CHotKeyDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add keys to combobox
	m_cmbKeys.InsertString(0, L"A");
	return TRUE;
}
