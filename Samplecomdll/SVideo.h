#pragma once


#include "General.h"


class ISVideo : public IGeneral {
public:
	//IGeneral
	virtual VRESULT __stdcall Probe(const char *pszType, IGeneral **ppRetVal) = 0;
	virtual void __stdcall AddRef() = 0;
	virtual void __stdcall Delete() = 0;

	//ISvideo
	virtual VRESULT __stdcall GetSVideoSinalValue(long &) = 0;
};
