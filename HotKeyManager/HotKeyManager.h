// HotKeyManager.h : HotKeyManager DLL のメイン ヘッダー ファイル
//

#pragma once
#include "framework.h"
#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"


// CHotKeyManagerApp
// このクラスの実装に関しては HotKeyManager.cpp をご覧ください
//

class CHotKeyManagerApp : public CWinApp
{
public:
	CHotKeyManagerApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
