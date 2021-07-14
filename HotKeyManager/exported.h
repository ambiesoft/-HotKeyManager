
#pragma once
#ifdef THISISDLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

typedef LPCWSTR (CALLBACK* FnGetNameFromID)(LPCWSTR pID);

class CHotKeyManagerDialog;
class CWnd;
class DLLEXPORT CHotKeyManagerManipulator
{
	CHotKeyManagerDialog* m_pDialog = nullptr;
	CWnd* m_pParent = nullptr;
	
public:
	CHotKeyManagerManipulator(HWND hParent, FnGetNameFromID fnGetNameFromID);
	~CHotKeyManagerManipulator();
	BOOL LoadDataFromIni(LPCWSTR pIniFile);
	BOOL SaveDataToIni(LPCWSTR pIniFile);

	BOOL ShowDialog();
};