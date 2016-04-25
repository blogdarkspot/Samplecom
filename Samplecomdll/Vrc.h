#pragma once
#include "Video.h"
#include "SVideo.h"
class CVrc : public IVideo, ISVideo {
public:
	CVrc();
	~CVrc();

	//IGeneral
	virtual VRESULT __stdcall Probe(const char *pszType, IGeneral **ppRetVal);
	virtual void __stdcall AddRef();
	virtual void __stdcall Delete();

	//IVideo
	virtual VRESULT __stdcall GetVideoSignalValue(long &);

	//ISvideo
	virtual VRESULT __stdcall GetSVideoSinalValue(long &);

private:
	int mCountRef;
	int mCurValue;
	int mCurSValue;
};

