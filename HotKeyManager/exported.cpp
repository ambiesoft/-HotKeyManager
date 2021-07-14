
#include "pch.h"
#include "CHotKeyManagerDialog.h"
#include "exported.h"
DLLEXPORT BOOL PASCAL ExportedFunction(CWnd* pParent)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	CHotKeyManagerDialog dlg(pParent);
	dlg.DoModal();
	return TRUE;
}
