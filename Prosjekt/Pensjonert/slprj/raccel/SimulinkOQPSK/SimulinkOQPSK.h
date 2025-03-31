#ifndef SimulinkOQPSK_h_
#define SimulinkOQPSK_h_
#ifndef SimulinkOQPSK_COMMON_INCLUDES_
#define SimulinkOQPSK_COMMON_INCLUDES_
#include <stdlib.h>
#include <time.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#include "iHalideFIRInterpolator.hpp"
#include "iHalideFIRDecimator.hpp"
#endif
#include "SimulinkOQPSK_types.h"
#include "rtGetNaN.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME SimulinkOQPSK
#define NSAMPLE_TIMES (5) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (3) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { creal_T moprdribiz ; creal_T junrgsnmb0 ; real_T i5ilelgt54
; } B ; typedef struct { gezsn1ijeo kiqazyiq00 ; d005fqujeu j33qtkq40m ;
creal_T pt5eromfcj ; creal_T gbyowhygxr [ 4 ] ; creal_T kviwuzsm51 ; creal_T
jhjvzmws0f [ 40 ] ; creal_T jkwcjrsbfz ; creal_T mpkdim1qis [ 78 ] ; real_T
ate1uhb4qw ; real_T hax1vszx2y [ 40 ] ; creal_T ikfemt5lt2 [ 4 ] ; creal_T
dd5j4umhh2 [ 16 ] ; creal_T eybefhgiyi [ 4 ] ; real_T fkshk3as53 [ 4 ] ;
real_T kxculzx4lb [ 8 ] ; real_T pbieyixh0q [ 8 ] ; real_T fm0vokcho4 [ 40 ]
; real_T j43xnixtdn [ 80 ] ; real_T krmeuxufvy [ 80 ] ; real_T coksx155ze [
40 ] ; ob3ra4tldg lpy5mzzed1 ; void * i1upjkvbfd ; int32_T mahx1vfrrk ;
int32_T b1k03uckiu ; int32_T fextltf3bq ; int32_T oj03j4ixuy ; int32_T
j4tyz1d51k [ 8 ] ; int32_T kwhxs250ag ; int32_T jseolvrnea ; int32_T
phw3qc5esn ; int32_T on4d5t4ft3 ; uint32_T cxw1tnf414 ; uint32_T krgyhlve5g ;
uint32_T cgcq15tqz2 [ 625 ] ; uint32_T jdlamz5s1g [ 2 ] ; uint32_T bxgvjqvv03
; uint32_T ax22qpdshl ; uint32_T g2xqaw3dz0 ; uint32_T cuu1zsu24f [ 625 ] ;
uint32_T ipb0ry35mu [ 2 ] ; uint32_T d3xzp3vtkg ; uint32_T e3grigdkp0 ;
uint32_T kpo4xu3rlc [ 2 ] ; uint8_T miuqblj25w ; boolean_T bx2b103j3q ;
boolean_T chgjvbcbzb ; boolean_T njjxls55cs ; boolean_T gc3fngkune ;
boolean_T mbdjklko3i ; boolean_T i5fyasx04o ; boolean_T gkfm5uihb0 ;
boolean_T miqhhd2uo2 ; boolean_T m2dn2xnnqj ; boolean_T ksl0kmigx2 ;
boolean_T cnhxmgap22 ; boolean_T mdfzrip4mj ; boolean_T g1hyfm4tj3 ;
boolean_T lmfcjcrcjv ; boolean_T mb0j0kmjar ; boolean_T hg0mobsir0 ;
boolean_T lbsrysvv05 ; } DW ; typedef struct { rtwCAPI_ModelMappingInfo mmi ;
} DataMapInfo ; struct P_ { real_T AWGNChannel_EbNo ; real_T
AWGNChannel_SignalPower ; real_T Symbolmapping_tableData [ 4 ] ; real_T
Symbolmapping_bp01Data [ 4 ] ; real_T Gain_Gain ; real_T
Pulseshaping_FILTER_COEFF [ 4 ] ; real_T Delay_InitialCondition ; real_T
Phaseoffset_Gain ; real_T FIRInterpolation_FILTER_COEFF [ 40 ] ; real_T
FIRDecimation_FILT [ 40 ] ; real_T Constant_Value ; int32_T Gain1_Gain ;
int32_T Bias_Bias ; uint8_T ShiftArithmetic_DiagnosticForOORShift ; } ;
extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW
rtDW ; extern P rtP ; extern mxArray * mr_SimulinkOQPSK_GetDWork ( ) ; extern
void mr_SimulinkOQPSK_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_SimulinkOQPSK_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * SimulinkOQPSK_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ;
extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs (
int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T tid ) ; void
MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
