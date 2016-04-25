#pragma once

#include "Error.h"

/**
* Interface Base para todas as classes Object Model
*/

class IGeneral {
public:
	virtual VRESULT __stdcall Probe(const char *pszType, IGeneral **ppRetVal) = 0;
	virtual void __stdcall AddRef() = 0;
	virtual void __stdcall Delete() = 0;
};
