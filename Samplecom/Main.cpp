#include <Windows.h>

#include <iostream>

#include "General.h"
#include "Video.h"


VRESULT CreateInstance(LPCWSTR pszDll, const char* pszType, IGeneral **ppRetVal) {
	//poteiro para função que é exportada na DLL
	typedef VRESULT (__stdcall *CreateInstanceProc) (const char *pszType, IGeneral **ppRetVal);
	
	HINSTANCE hr = LoadLibrary(pszDll);
	if (hr == NULL) {
		return V_INTERNALERROR;
	}

	CreateInstanceProc proc = (CreateInstanceProc)GetProcAddress(hr, "createInstance");

	if (proc == NULL) {
		FreeLibrary(hr);
		return V_INTERNALERROR;
	}

	return (*proc)(pszType, ppRetVal);
}

int main(int argc, char* argv[]) {
	IGeneral *pGeneral;
	VRESULT vr;
	vr  = CreateInstance(L"Samplecomdll", "IGeneral", &pGeneral);
	if (V_FAILED(vr)) {
		return 1;
	}
	IVideo *video;
	vr = pGeneral->Probe("IVideo", (IGeneral **)(&video));
	if (V_FAILED(vr)) {
		return 1;
	}
	long getValue;
	vr = video->GetVideoSignalValue(getValue);
	std::cout << getValue << std::endl;
	std::cin >> getValue;
		
	return 0;
}