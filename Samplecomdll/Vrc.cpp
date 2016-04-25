#include "Vrc.h"
#include <string>


CVrc::CVrc() {
	mCountRef = 0;
	mCurValue = 0;
	mCurSValue = 0;
}


CVrc::~CVrc() {
}

VRESULT  CVrc::Probe(const char * pszType, IGeneral **ppRetVal) {
	
	(*ppRetVal) = nullptr;

	if (!strcmp(pszType, "IGeneral") || !strcmp(pszType, "IVideo")) {
		(*ppRetVal) = static_cast<IVideo *> (this);
	}
	if (!strcmp(pszType,"ISVideo")) {
		(*ppRetVal) = static_cast<ISVideo *> (this);
	}
	
	if (*ppRetVal != nullptr) {
		AddRef();
		return V_OK;
	}

	
	return V_NOINTERFACE;
}

void CVrc::AddRef() {
	mCountRef++;
}

void CVrc::Delete() {
	
	if (mCountRef == 0) {
		delete this;
	}
	mCountRef--;
}

VRESULT CVrc::GetVideoSignalValue(long &value) {
	mCurValue += 5;
	if (mCurValue == 40) {
		mCurValue = 5;
	}
	value = mCurValue;
	return V_OK;
}

VRESULT CVrc::GetSVideoSinalValue(long &value) {
	mCurSValue += 6;
	if (mCurSValue == 42) {
		mCurSValue = 6;
	}
	value = mCurSValue;
	return V_OK;
}
