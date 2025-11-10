#ifndef __DLL_API_H__
#define __DLL_API_H__

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

#endif // __DLL_API_H__
