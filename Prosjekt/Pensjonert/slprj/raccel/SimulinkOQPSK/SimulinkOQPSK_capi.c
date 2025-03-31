#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "SimulinkOQPSK_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 24
#endif
#ifndef SS_INT64
#define SS_INT64 25
#endif
#else
#include "builtin_typeid_types.h"
#include "SimulinkOQPSK.h"
#include "SimulinkOQPSK_capi.h"
#include "SimulinkOQPSK_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Complex to Real-Imag" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Real-Imag to Complex1" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"SimulinkOQPSK/Raised Cosine Receive Filter/FIR Decimation" ) , TARGET_STRING
( "" ) , 0 , 1 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0
, 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 3
, TARGET_STRING ( "SimulinkOQPSK/AWGN Channel" ) , TARGET_STRING ( "EbNo" ) ,
0 , 0 , 0 } , { 4 , TARGET_STRING ( "SimulinkOQPSK/AWGN Channel" ) ,
TARGET_STRING ( "SignalPower" ) , 0 , 0 , 0 } , { 5 , TARGET_STRING (
"SimulinkOQPSK/Bipolar to Unipolar Converter/Shift Arithmetic" ) ,
TARGET_STRING ( "DiagnosticForOORShift" ) , 2 , 0 , 0 } , { 6 , TARGET_STRING
( "SimulinkOQPSK/Bipolar to Unipolar Converter/Bias" ) , TARGET_STRING (
"Bias" ) , 3 , 0 , 0 } , { 7 , TARGET_STRING (
"SimulinkOQPSK/Bipolar to Unipolar Converter/Gain1" ) , TARGET_STRING (
"Gain" ) , 3 , 0 , 0 } , { 8 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Constant" ) , TARGET_STRING ( "Value"
) , 0 , 0 , 0 } , { 9 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Gain" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 10 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Phase offset" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 11 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Symbol mapping" ) , TARGET_STRING (
"Table" ) , 0 , 1 , 0 } , { 12 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Symbol mapping" ) , TARGET_STRING (
"BreakpointsForDimension1" ) , 0 , 1 , 0 } , { 13 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Delay" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING (
"SimulinkOQPSK/Raised Cosine Receive Filter/FIR Decimation" ) , TARGET_STRING
( "FILT" ) , 0 , 2 , 0 } , { 15 , TARGET_STRING (
"SimulinkOQPSK/Raised Cosine Transmit Filter/FIR Interpolation" ) ,
TARGET_STRING ( "FILTER_COEFF" ) , 0 , 2 , 0 } , { 16 , TARGET_STRING (
"SimulinkOQPSK/OQPSK Modulator Baseband/Pulse shaping/FIR/Pulse shaping" ) ,
TARGET_STRING ( "FILTER_COEFF" ) , 0 , 3 , 0 } , { 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static
const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0
, 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0
, 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . i5ilelgt54 , & rtB . moprdribiz .
re , & rtB . junrgsnmb0 . re , & rtP . AWGNChannel_EbNo , & rtP .
AWGNChannel_SignalPower , & rtP . ShiftArithmetic_DiagnosticForOORShift , &
rtP . Bias_Bias , & rtP . Gain1_Gain , & rtP . Constant_Value , & rtP .
Gain_Gain , & rtP . Phaseoffset_Gain , & rtP . Symbolmapping_tableData [ 0 ]
, & rtP . Symbolmapping_bp01Data [ 0 ] , & rtP . Delay_InitialCondition , &
rtP . FIRDecimation_FILT [ 0 ] , & rtP . FIRInterpolation_FILTER_COEFF [ 0 ]
, & rtP . Pulseshaping_FILTER_COEFF [ 0 ] , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "struct" , "creal_T" , 0 , 0 , sizeof ( creal_T ) , ( uint8_T ) SS_DOUBLE ,
1 , 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , (
uint8_T ) SS_UINT8 , 0 , 0 , 0 } , { "int" , "int32_T" , 0 , 0 , sizeof (
int32_T ) , ( uint8_T ) SS_INT32 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 ,
0 } } ; static const uint_T rtDimensionArray [ ] = { 1 , 1 , 1 , 4 , 5 , 8 ,
2 , 2 } ; static const real_T rtcapiStoredFloats [ ] = { 5.0E-7 , 0.0 ,
1.0E-6 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , (
int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 2 ]
, ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 3 , ( uint8_T ) 0
} } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals ,
3 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 14 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2471231377U , 1996571106U , 1402774140U , 1784209955U } , ( NULL ) , 0 ,
( boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * SimulinkOQPSK_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void SimulinkOQPSK_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void SimulinkOQPSK_host_InitializeDataMapInfo (
SimulinkOQPSK_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
