#include "Samplecomdll.h"
#include "Video.h"
#include "Vrc.h"

VRESULT __stdcall createInstance(const char * pszVrc, IGeneral **ppRetVael) {
	VRESULT ret;
	(*ppRetVael) = nullptr;
	CVrc *pCvrc = new CVrc();
	if (pCvrc == nullptr)
		return V_OUTOFMEMORY;
	ret = pCvrc->Probe(pszVrc, ppRetVael);
	if (V_FAILED(ret)) {
		delete pCvrc;
	}
	return ret;
}