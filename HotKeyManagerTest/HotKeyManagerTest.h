
// HotKeyManagerTest.h : PROJECT_NAME アプリケーションのメイン ヘッダー ファイルです
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH に対してこのファイルをインクルードする前に 'pch.h' をインクルードしてください"
#endif

#include "resource.h"		// メイン シンボル


// CHotKeyManagerTestApp:
// このクラスの実装については、HotKeyManagerTest.cpp を参照してください
//

class CHotKeyManagerTestApp : public CWinApp
{
public:
	CHotKeyManagerTestApp();

// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装

	DECLARE_MESSAGE_MAP()
};

extern CHotKeyManagerTestApp theApp;
