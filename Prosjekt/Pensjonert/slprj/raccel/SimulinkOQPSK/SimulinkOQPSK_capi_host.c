#include "SimulinkOQPSK_capi_host.h"
static SimulinkOQPSK_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        SimulinkOQPSK_host_InitializeDataMapInfo(&(root), "SimulinkOQPSK");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction(){return(getRootMappingInfo());}
