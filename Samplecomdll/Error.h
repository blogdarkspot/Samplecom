#pragma once

typedef int VRESULT;


#define V_OUTOFMEMORY	1
#define V_NOINTERFACE	2
#define V_INTERNALERROR 3
#define V_OK			0

#define V_SUCCEEDED(P1) ((P1) == V_OK)
#define V_FAILED(P1)	((P1) != V_OK)
