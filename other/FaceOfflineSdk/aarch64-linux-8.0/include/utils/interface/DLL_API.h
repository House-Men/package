#ifdef _MSC_VER
#define STDCALL __stdcall
#ifdef EXPORT_API
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport) 
#endif   
#else
#define STDCALL
#define DLL_API
#endif