
#ifdef THISISDLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif
DLLEXPORT BOOL PASCAL ExportedFunction(CWnd* pParent);