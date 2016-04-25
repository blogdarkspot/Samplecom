#pragma once

#include "General.h"

extern "C" {
	__declspec(dllexport) VRESULT __stdcall createInstance(const char * pszVrc, IGeneral **ppRetVal);
};
