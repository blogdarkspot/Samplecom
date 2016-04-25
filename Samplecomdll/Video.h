#pragma once

#include "General.h"

class IVideo : public IGeneral {
public:
	//IGeneral
	virtual VRESULT __stdcall Probe(const char *pszType, IGeneral **ppRetVal) = 0;
	virtual void __stdcall AddRef() = 0;
	virtual void __stdcall Delete() = 0;

	//IVideo
	virtual VRESULT __stdcall GetVideoSignalValue(long &) = 0;

};
