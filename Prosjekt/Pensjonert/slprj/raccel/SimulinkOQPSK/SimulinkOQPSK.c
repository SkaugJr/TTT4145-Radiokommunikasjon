#include "SimulinkOQPSK.h"
#include "SimulinkOQPSK_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "mwmathutil.h"
#include <time.h>
#include <stddef.h>
#include "rt_logging_mmi.h"
#include "SimulinkOQPSK_capi.h"
#include "SimulinkOQPSK_private.h"
#include "SimulinkOQPSK_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 4 , &
stopRequested ) ; } rtExtModeShutdown ( 4 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_engine_exec.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 5 ; const char_T
* gbl_raccel_Version = "24.1 (R2024a) 19-Nov-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 , 1 }
; const char * raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const
char * inportFileName , int * matFileFormat ) { return
rt_RAccelReadInportsMatFile ( S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_engine_exec.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; static real_T k5dykcfgpq ( void ) ; static real_T eimykwy2vh (
real_T x ) ; static void oyxxnyztmb ( ob3ra4tldg * obj ) ; static void
gwxej0ur3b ( gezsn1ijeo * obj , real_T val ) ; static void ciytelebuu (
gezsn1ijeo * obj ) ; static void pqhjomjbya ( uint32_T mt [ 625 ] , uint32_T
seed ) ; static void in0ndyl4sj ( void ) ; static real_T kogkrd0iea ( void )
; static void nyqhoqjzol ( uint32_T mt [ 625 ] , uint32_T u [ 2 ] ) ; static
real_T hlp4ulzvlq ( uint32_T mt [ 625 ] ) ; static real_T opp2d1xb2ua (
uint32_T state [ 625 ] ) ; static creal_T ngizeo0ekg ( void ) ; real_T
look1_binlxpw ( real_T u0 , const real_T bp0 [ ] , const real_T table [ ] ,
uint32_T maxIndex ) { real_T frac ; real_T yL_0d0 ; uint32_T bpIdx ; uint32_T
iLeft ; uint32_T iRght ; if ( u0 <= bp0 [ 0U ] ) { iLeft = 0U ; frac = ( u0 -
bp0 [ 0U ] ) / ( bp0 [ 1U ] - bp0 [ 0U ] ) ; } else if ( u0 < bp0 [ maxIndex
] ) { bpIdx = maxIndex >> 1U ; iLeft = 0U ; iRght = maxIndex ; while ( iRght
- iLeft > 1U ) { if ( u0 < bp0 [ bpIdx ] ) { iRght = bpIdx ; } else { iLeft =
bpIdx ; } bpIdx = ( iRght + iLeft ) >> 1U ; } frac = ( u0 - bp0 [ iLeft ] ) /
( bp0 [ iLeft + 1U ] - bp0 [ iLeft ] ) ; } else { iLeft = maxIndex - 1U ;
frac = ( u0 - bp0 [ maxIndex - 1U ] ) / ( bp0 [ maxIndex ] - bp0 [ maxIndex -
1U ] ) ; } yL_0d0 = table [ iLeft ] ; return ( table [ iLeft + 1U ] - yL_0d0
) * frac + yL_0d0 ; } int32_T div_nde_s32_floor ( int32_T numerator , int32_T
denominator ) { return ( ( ( numerator < 0 ) != ( denominator < 0 ) ) && (
numerator % denominator != 0 ) ? - 1 : 0 ) + numerator / denominator ; }
static real_T k5dykcfgpq ( void ) { time_t rawtime ; struct tm expl_temp ;
real_T dDateNum ; int32_T r ; int16_T cDaysMonthWise [ 12 ] ; boolean_T
guard1 ; cDaysMonthWise [ 0 ] = 0 ; cDaysMonthWise [ 1 ] = 31 ;
cDaysMonthWise [ 2 ] = 59 ; cDaysMonthWise [ 3 ] = 90 ; cDaysMonthWise [ 4 ]
= 120 ; cDaysMonthWise [ 5 ] = 151 ; cDaysMonthWise [ 6 ] = 181 ;
cDaysMonthWise [ 7 ] = 212 ; cDaysMonthWise [ 8 ] = 243 ; cDaysMonthWise [ 9
] = 273 ; cDaysMonthWise [ 10 ] = 304 ; cDaysMonthWise [ 11 ] = 334 ; time (
& rawtime ) ; expl_temp = * localtime ( & rawtime ) ; dDateNum = ( ( ( ( (
real_T ) ( expl_temp . tm_year + 1900 ) * 365.0 + muDoubleScalarCeil ( (
real_T ) ( expl_temp . tm_year + 1900 ) / 4.0 ) ) - muDoubleScalarCeil ( (
real_T ) ( expl_temp . tm_year + 1900 ) / 100.0 ) ) + muDoubleScalarCeil ( (
real_T ) ( expl_temp . tm_year + 1900 ) / 400.0 ) ) + ( real_T )
cDaysMonthWise [ expl_temp . tm_mon ] ) + ( real_T ) expl_temp . tm_mday ; if
( expl_temp . tm_mon + 1 > 2 ) { if ( expl_temp . tm_year + 1900 == 0 ) { r =
0 ; } else { r = ( int32_T ) muDoubleScalarRem ( expl_temp . tm_year + 1900 ,
4.0 ) ; if ( ( r != 0 ) && ( expl_temp . tm_year + 1900 < 0 ) ) { r += 4 ; }
} guard1 = false ; if ( r == 0 ) { if ( expl_temp . tm_year + 1900 != 0 ) { r
= ( int32_T ) muDoubleScalarRem ( expl_temp . tm_year + 1900 , 100.0 ) ; if (
( r != 0 ) && ( expl_temp . tm_year + 1900 < 0 ) ) { r += 100 ; } } if ( r !=
0 ) { dDateNum ++ ; } else { guard1 = true ; } } else { guard1 = true ; } if
( guard1 ) { if ( expl_temp . tm_year + 1900 == 0 ) { r = 0 ; } else { r = (
int32_T ) muDoubleScalarRem ( expl_temp . tm_year + 1900 , 400.0 ) ; if ( ( r
!= 0 ) && ( expl_temp . tm_year + 1900 < 0 ) ) { r += 400 ; } } if ( r == 0 )
{ dDateNum ++ ; } } } return ( ( ( real_T ) expl_temp . tm_hour * 3600.0 + (
real_T ) expl_temp . tm_min * 60.0 ) + ( real_T ) expl_temp . tm_sec ) /
86400.0 + dDateNum ; } static real_T eimykwy2vh ( real_T x ) { real_T r ; if
( muDoubleScalarIsNaN ( x ) || muDoubleScalarIsInf ( x ) ) { r = ( rtNaN ) ;
} else if ( x == 0.0 ) { r = 0.0 ; } else { r = muDoubleScalarRem ( x ,
2.147483647E+9 ) ; if ( r == 0.0 ) { r = 0.0 ; } else if ( x < 0.0 ) { r +=
2.147483647E+9 ; } } return r ; } static void oyxxnyztmb ( ob3ra4tldg * obj )
{ time_t eTime ; time_t eTime_p ; real_T s ; real_T x ; int32_T exitg1 ;
int32_T t ; uint32_T r ; obj -> isInitialized = 1 ; x = k5dykcfgpq ( ) *
8.64E+6 ; s = eimykwy2vh ( muDoubleScalarFloor ( x ) ) ; eTime = time ( NULL
) ; do { exitg1 = 0 ; eTime_p = time ( NULL ) ; if ( ( int32_T ) eTime_p <= (
int32_T ) eTime + 1 ) { x = k5dykcfgpq ( ) * 8.64E+6 ; if ( s != eimykwy2vh (
muDoubleScalarFloor ( x ) ) ) { exitg1 = 1 ; } } else { exitg1 = 1 ; } }
while ( exitg1 == 0 ) ; x = muDoubleScalarRound ( s ) ; if ( x <
4.294967296E+9 ) { if ( x >= 0.0 ) { rtDW . cxw1tnf414 = ( uint32_T ) x ; }
else { rtDW . cxw1tnf414 = 0U ; } } else if ( x >= 4.294967296E+9 ) { rtDW .
cxw1tnf414 = MAX_uint32_T ; } else { rtDW . cxw1tnf414 = 0U ; } if ( rtDW .
bxgvjqvv03 == 7U ) { r = rtDW . cxw1tnf414 ; rtDW . cgcq15tqz2 [ 0 ] = rtDW .
cxw1tnf414 ; for ( t = 0 ; t < 623 ; t ++ ) { r = ( ( r >> 30U ^ r ) *
1812433253U + ( uint32_T ) t ) + 1U ; rtDW . cgcq15tqz2 [ t + 1 ] = r ; }
rtDW . cgcq15tqz2 [ 624 ] = 624U ; } else if ( rtDW . bxgvjqvv03 == 5U ) {
rtDW . jdlamz5s1g [ 0 ] = 362436069U ; rtDW . jdlamz5s1g [ 1 ] = rtDW .
cxw1tnf414 ; if ( rtDW . jdlamz5s1g [ 1 ] == 0U ) { rtDW . jdlamz5s1g [ 1 ] =
521288629U ; } } else if ( rtDW . bxgvjqvv03 == 4U ) { r = rtDW . cxw1tnf414
>> 16U ; t = ( int32_T ) ( rtDW . cxw1tnf414 & 32768U ) ; r += ( ( ( rtDW .
cxw1tnf414 - ( r << 16U ) ) - ( uint32_T ) t ) << 16U ) + ( uint32_T ) t ; if
( r < 1U ) { r = 1144108930U ; } else if ( r > 2147483646U ) { r =
2147483646U ; } rtDW . krgyhlve5g = r ; } obj -> TunablePropsChanged = false
; } static void gwxej0ur3b ( gezsn1ijeo * obj , real_T val ) { obj ->
SignalPower = val ; } static void ciytelebuu ( gezsn1ijeo * obj ) { obj ->
pNumChanFromProp = 1.0 ; obj -> pStd = muDoubleScalarSqrt ( obj ->
SignalPower / ( muDoubleScalarPower ( 10.0 , obj -> EbNo / 10.0 ) * 2.0 ) ) ;
obj -> pFirstInputNumChan = 1.0 ; obj -> pIsVarChannel = false ; } static
void pqhjomjbya ( uint32_T mt [ 625 ] , uint32_T seed ) { int32_T b_mti ;
uint32_T r ; r = seed ; mt [ 0 ] = seed ; for ( b_mti = 0 ; b_mti < 623 ;
b_mti ++ ) { r = ( ( r >> 30U ^ r ) * 1812433253U + ( uint32_T ) b_mti ) + 1U
; mt [ b_mti + 1 ] = r ; } mt [ 624 ] = 624U ; } static void in0ndyl4sj (
void ) { time_t eTime ; time_t eTime_p ; real_T s ; real_T x ; int32_T exitg1
; x = k5dykcfgpq ( ) * 8.64E+6 ; s = eimykwy2vh ( muDoubleScalarFloor ( x ) )
; eTime = time ( NULL ) ; do { exitg1 = 0 ; eTime_p = time ( NULL ) ; if ( (
int32_T ) eTime_p <= ( int32_T ) eTime + 1 ) { x = k5dykcfgpq ( ) * 8.64E+6 ;
if ( s != eimykwy2vh ( muDoubleScalarFloor ( x ) ) ) { exitg1 = 1 ; } } else
{ exitg1 = 1 ; } } while ( exitg1 == 0 ) ; x = muDoubleScalarRound ( s ) ; if
( x < 4.294967296E+9 ) { if ( x >= 0.0 ) { rtDW . ax22qpdshl = ( uint32_T ) x
; } else { rtDW . ax22qpdshl = 0U ; } } else if ( x >= 4.294967296E+9 ) {
rtDW . ax22qpdshl = MAX_uint32_T ; } else { rtDW . ax22qpdshl = 0U ; }
pqhjomjbya ( rtDW . cuu1zsu24f , rtDW . ax22qpdshl ) ; } static real_T
kogkrd0iea ( void ) { real_T r ; int32_T b_j ; int32_T b_kk ; uint32_T b_u [
2 ] ; uint32_T mti ; uint32_T y ; if ( rtDW . bxgvjqvv03 == 4U ) { y = rtDW .
krgyhlve5g / 127773U ; mti = ( rtDW . krgyhlve5g - y * 127773U ) * 16807U ; y
*= 2836U ; if ( mti < y ) { mti = ~ ( y - mti ) & 2147483647U ; } else { mti
-= y ; } r = ( real_T ) mti * 4.6566128752457969E-10 ; rtDW . krgyhlve5g =
mti ; } else if ( rtDW . bxgvjqvv03 == 5U ) { mti = 69069U * rtDW .
jdlamz5s1g [ 0 ] + 1234567U ; y = rtDW . jdlamz5s1g [ 1 ] << 13 ^ rtDW .
jdlamz5s1g [ 1 ] ; y ^= y >> 17 ; y ^= y << 5 ; rtDW . jdlamz5s1g [ 0 ] = mti
; rtDW . jdlamz5s1g [ 1 ] = y ; r = ( real_T ) ( mti + y ) *
2.328306436538696E-10 ; } else { do { for ( b_j = 0 ; b_j < 2 ; b_j ++ ) {
mti = rtDW . cgcq15tqz2 [ 624 ] + 1U ; if ( rtDW . cgcq15tqz2 [ 624 ] + 1U >=
625U ) { for ( b_kk = 0 ; b_kk < 227 ; b_kk ++ ) { y = ( rtDW . cgcq15tqz2 [
b_kk + 1 ] & 2147483647U ) | ( rtDW . cgcq15tqz2 [ b_kk ] & 2147483648U ) ;
if ( ( y & 1U ) == 0U ) { mti = y >> 1U ; } else { mti = y >> 1U ^
2567483615U ; } rtDW . cgcq15tqz2 [ b_kk ] = rtDW . cgcq15tqz2 [ b_kk + 397 ]
^ mti ; } for ( b_kk = 0 ; b_kk < 396 ; b_kk ++ ) { y = ( rtDW . cgcq15tqz2 [
b_kk + 227 ] & 2147483648U ) | ( rtDW . cgcq15tqz2 [ b_kk + 228 ] &
2147483647U ) ; if ( ( y & 1U ) == 0U ) { mti = y >> 1U ; } else { mti = y >>
1U ^ 2567483615U ; } rtDW . cgcq15tqz2 [ b_kk + 227 ] = rtDW . cgcq15tqz2 [
b_kk ] ^ mti ; } y = ( rtDW . cgcq15tqz2 [ 623 ] & 2147483648U ) | ( rtDW .
cgcq15tqz2 [ 0 ] & 2147483647U ) ; if ( ( y & 1U ) == 0U ) { mti = y >> 1U ;
} else { mti = y >> 1U ^ 2567483615U ; } rtDW . cgcq15tqz2 [ 623 ] = rtDW .
cgcq15tqz2 [ 396 ] ^ mti ; mti = 1U ; } y = rtDW . cgcq15tqz2 [ ( int32_T )
mti - 1 ] ; rtDW . cgcq15tqz2 [ 624 ] = mti ; y ^= y >> 11U ; y ^= y << 7U &
2636928640U ; y ^= y << 15U & 4022730752U ; b_u [ b_j ] = y >> 18U ^ y ; } r
= ( ( real_T ) ( b_u [ 0 ] >> 5U ) * 6.7108864E+7 + ( real_T ) ( b_u [ 1 ] >>
6U ) ) * 1.1102230246251565E-16 ; } while ( r == 0.0 ) ; } return r ; }
static void nyqhoqjzol ( uint32_T mt [ 625 ] , uint32_T u [ 2 ] ) { int32_T
b_j ; int32_T b_kk ; uint32_T mti ; uint32_T y ; for ( b_j = 0 ; b_j < 2 ;
b_j ++ ) { mti = mt [ 624 ] + 1U ; if ( mt [ 624 ] + 1U >= 625U ) { for (
b_kk = 0 ; b_kk < 227 ; b_kk ++ ) { y = ( mt [ b_kk + 1 ] & 2147483647U ) | (
mt [ b_kk ] & 2147483648U ) ; if ( ( y & 1U ) == 0U ) { mti = y >> 1U ; }
else { mti = y >> 1U ^ 2567483615U ; } mt [ b_kk ] = mt [ b_kk + 397 ] ^ mti
; } for ( b_kk = 0 ; b_kk < 396 ; b_kk ++ ) { y = ( mt [ b_kk + 227 ] &
2147483648U ) | ( mt [ b_kk + 228 ] & 2147483647U ) ; if ( ( y & 1U ) == 0U )
{ mti = y >> 1U ; } else { mti = y >> 1U ^ 2567483615U ; } mt [ b_kk + 227 ]
= mt [ b_kk ] ^ mti ; } y = ( mt [ 623 ] & 2147483648U ) | ( mt [ 0 ] &
2147483647U ) ; if ( ( y & 1U ) == 0U ) { mti = y >> 1U ; } else { mti = y >>
1U ^ 2567483615U ; } mt [ 623 ] = mt [ 396 ] ^ mti ; mti = 1U ; } y = mt [ (
int32_T ) mti - 1 ] ; mt [ 624 ] = mti ; y ^= y >> 11U ; y ^= y << 7U &
2636928640U ; y ^= y << 15U & 4022730752U ; u [ b_j ] = y >> 18U ^ y ; } }
static real_T hlp4ulzvlq ( uint32_T mt [ 625 ] ) { real_T r ; uint32_T b_u [
2 ] ; do { nyqhoqjzol ( mt , b_u ) ; r = ( ( real_T ) ( b_u [ 0 ] >> 5U ) *
6.7108864E+7 + ( real_T ) ( b_u [ 1 ] >> 6U ) ) * 1.1102230246251565E-16 ; }
while ( r == 0.0 ) ; return r ; } static real_T opp2d1xb2ua ( uint32_T state
[ 625 ] ) { real_T d_u ; real_T r ; real_T x ; int32_T i ; uint32_T u32 [ 2 ]
; static const real_T tmp [ 257 ] = { 0.0 , 0.215241895984875 ,
0.286174591792068 , 0.335737519214422 , 0.375121332878378 , 0.408389134611989
, 0.43751840220787 , 0.46363433679088 , 0.487443966139235 , 0.50942332960209
, 0.529909720661557 , 0.549151702327164 , 0.567338257053817 ,
0.584616766106378 , 0.601104617755991 , 0.61689699000775 , 0.63207223638606 ,
0.646695714894993 , 0.660822574244419 , 0.674499822837293 , 0.687767892795788
, 0.700661841106814 , 0.713212285190975 , 0.725446140909999 ,
0.737387211434295 , 0.749056662017815 , 0.760473406430107 , 0.771654424224568
, 0.782615023307232 , 0.793369058840623 , 0.80392911698997 ,
0.814306670135215 , 0.824512208752291 , 0.834555354086381 , 0.844444954909153
, 0.854189171008163 , 0.863795545553308 , 0.87327106808886 ,
0.882622229585165 , 0.891855070732941 , 0.900975224461221 , 0.909987953496718
, 0.91889818364959 , 0.927710533401999 , 0.936429340286575 ,
0.945058684468165 , 0.953602409881086 , 0.96206414322304 , 0.970447311064224
, 0.978755155294224 , 0.986990747099062 , 0.99515699963509 , 1.00325667954467
, 1.01129241744 , 1.01926671746548 , 1.02718196603564 , 1.03504043983344 ,
1.04284431314415 , 1.05059566459093 , 1.05829648333067 , 1.06594867476212 ,
1.07355406579244 , 1.0811144097034 , 1.08863139065398 , 1.09610662785202 ,
1.10354167942464 , 1.11093804601357 , 1.11829717411934 , 1.12562045921553 ,
1.13290924865253 , 1.14016484436815 , 1.14738850542085 , 1.15458145035993 ,
1.16174485944561 , 1.16887987673083 , 1.17598761201545 , 1.18306914268269 ,
1.19012551542669 , 1.19715774787944 , 1.20416683014438 , 1.2111537262437 ,
1.21811937548548 , 1.22506469375653 , 1.23199057474614 , 1.23889789110569 ,
1.24578749554863 , 1.2526602218949 , 1.25951688606371 , 1.26635828701823 ,
1.27318520766536 , 1.27999841571382 , 1.28679866449324 , 1.29358669373695 ,
1.30036323033084 , 1.30712898903073 , 1.31388467315022 , 1.32063097522106 ,
1.32736857762793 , 1.33409815321936 , 1.3408203658964 , 1.34753587118059 ,
1.35424531676263 , 1.36094934303328 , 1.36764858359748 , 1.37434366577317 ,
1.38103521107586 , 1.38772383568998 , 1.39441015092814 , 1.40109476367925 ,
1.4077782768464 , 1.41446128977547 , 1.42114439867531 , 1.42782819703026 ,
1.43451327600589 , 1.44120022484872 , 1.44788963128058 , 1.45458208188841 ,
1.46127816251028 , 1.46797845861808 , 1.47468355569786 , 1.48139403962819 ,
1.48811049705745 , 1.49483351578049 , 1.50156368511546 , 1.50830159628131 ,
1.51504784277671 , 1.521803020761 , 1.52856772943771 , 1.53534257144151 ,
1.542128153229 , 1.54892508547417 , 1.55573398346918 , 1.56255546753104 ,
1.56939016341512 , 1.57623870273591 , 1.58310172339603 , 1.58997987002419 ,
1.59687379442279 , 1.60378415602609 , 1.61071162236983 , 1.61765686957301 ,
1.62462058283303 , 1.63160345693487 , 1.63860619677555 , 1.64562951790478 ,
1.65267414708306 , 1.65974082285818 , 1.66683029616166 , 1.67394333092612 ,
1.68108070472517 , 1.68824320943719 , 1.69543165193456 , 1.70264685479992 ,
1.7098896570713 , 1.71716091501782 , 1.72446150294804 , 1.73179231405296 ,
1.73915426128591 , 1.74654827828172 , 1.75397532031767 , 1.76143636531891 ,
1.76893241491127 , 1.77646449552452 , 1.78403365954944 , 1.79164098655216 ,
1.79928758454972 , 1.80697459135082 , 1.81470317596628 , 1.82247454009388 ,
1.83028991968276 , 1.83815058658281 , 1.84605785028518 , 1.8540130597602 ,
1.86201760539967 , 1.87007292107127 , 1.878180486293 , 1.88634182853678 ,
1.8945585256707 , 1.90283220855043 , 1.91116456377125 , 1.91955733659319 ,
1.92801233405266 , 1.93653142827569 , 1.94511656000868 , 1.95376974238465 ,
1.96249306494436 , 1.97128869793366 , 1.98015889690048 , 1.98910600761744 ,
1.99813247135842 , 2.00724083056053 , 2.0164337349062 , 2.02571394786385 ,
2.03508435372962 , 2.04454796521753 , 2.05410793165065 , 2.06376754781173 ,
2.07353026351874 , 2.0833996939983 , 2.09337963113879 , 2.10347405571488 ,
2.11368715068665 , 2.12402331568952 , 2.13448718284602 , 2.14508363404789 ,
2.15581781987674 , 2.16669518035431 , 2.17772146774029 , 2.18890277162636 ,
2.20024554661128 , 2.21175664288416 , 2.22344334009251 , 2.23531338492992 ,
2.24737503294739 , 2.25963709517379 , 2.27210899022838 , 2.28480080272449 ,
2.29772334890286 , 2.31088825060137 , 2.32430801887113 , 2.33799614879653 ,
2.35196722737914 , 2.36623705671729 , 2.38082279517208 , 2.39574311978193 ,
2.41101841390112 , 2.42667098493715 , 2.44272531820036 , 2.4592083743347 ,
2.47614993967052 , 2.49358304127105 , 2.51154444162669 , 2.53007523215985 ,
2.54922155032478 , 2.56903545268184 , 2.58957598670829 , 2.61091051848882 ,
2.63311639363158 , 2.65628303757674 , 2.68051464328574 , 2.70593365612306 ,
2.73268535904401 , 2.76094400527999 , 2.79092117400193 , 2.82287739682644 ,
2.85713873087322 , 2.89412105361341 , 2.93436686720889 , 2.97860327988184 ,
3.02783779176959 , 3.08352613200214 , 3.147889289518 , 3.2245750520478 ,
3.32024473383983 , 3.44927829856143 , 3.65415288536101 , 3.91075795952492 } ;
static const real_T tmp_p [ 257 ] = { 1.0 , 0.977101701267673 ,
0.959879091800108 , 0.9451989534423 , 0.932060075959231 , 0.919991505039348 ,
0.908726440052131 , 0.898095921898344 , 0.887984660755834 , 0.878309655808918
, 0.869008688036857 , 0.860033621196332 , 0.851346258458678 ,
0.842915653112205 , 0.834716292986884 , 0.826726833946222 , 0.818929191603703
, 0.811307874312656 , 0.803849483170964 , 0.796542330422959 ,
0.789376143566025 , 0.782341832654803 , 0.775431304981187 , 0.768637315798486
, 0.761953346836795 , 0.755373506507096 , 0.748892447219157 ,
0.742505296340151 , 0.736207598126863 , 0.729995264561476 , 0.72386453346863
, 0.717811932630722 , 0.711834248878248 , 0.705928501332754 ,
0.700091918136512 , 0.694321916126117 , 0.688616083004672 , 0.682972161644995
, 0.677388036218774 , 0.671861719897082 , 0.66639134390875 ,
0.660975147776663 , 0.655611470579697 , 0.650298743110817 , 0.645035480820822
, 0.639820277453057 , 0.634651799287624 , 0.629528779924837 ,
0.624450015547027 , 0.619414360605834 , 0.614420723888914 , 0.609468064925773
, 0.604555390697468 , 0.599681752619125 , 0.594846243767987 ,
0.590047996332826 , 0.585286179263371 , 0.580559996100791 , 0.575868682972354
, 0.571211506735253 , 0.566587763256165 , 0.561996775814525 ,
0.557437893618766 , 0.552910490425833 , 0.548413963255266 , 0.543947731190026
, 0.539511234256952 , 0.535103932380458 , 0.530725304403662 ,
0.526374847171684 , 0.522052074672322 , 0.517756517229756 , 0.513487720747327
, 0.509245245995748 , 0.505028667943468 , 0.500837575126149 ,
0.49667156905249 , 0.492530263643869 , 0.488413284705458 , 0.484320269426683
, 0.480250865909047 , 0.476204732719506 , 0.47218153846773 ,
0.468180961405694 , 0.464202689048174 , 0.460246417812843 , 0.456311852678716
, 0.452398706861849 , 0.448506701507203 , 0.444635565395739 ,
0.440785034665804 , 0.436954852547985 , 0.433144769112652 , 0.429354541029442
, 0.425583931338022 , 0.421832709229496 , 0.418100649837848 ,
0.414387534040891 , 0.410693148270188 , 0.407017284329473 , 0.403359739221114
, 0.399720314980197 , 0.396098818515832 , 0.392495061459315 ,
0.388908860018789 , 0.385340034840077 , 0.381788410873393 , 0.378253817245619
, 0.374736087137891 , 0.371235057668239 , 0.367750569779032 ,
0.364282468129004 , 0.360830600989648 , 0.357394820145781 , 0.353974980800077
, 0.350570941481406 , 0.347182563956794 , 0.343809713146851 ,
0.340452257044522 , 0.337110066637006 , 0.333783015830718 , 0.330470981379163
, 0.327173842813601 , 0.323891482376391 , 0.320623784956905 ,
0.317370638029914 , 0.314131931596337 , 0.310907558126286 , 0.307697412504292
, 0.30450139197665 , 0.301319396100803 , 0.298151326696685 ,
0.294997087799962 , 0.291856585617095 , 0.288729728482183 , 0.285616426815502
, 0.282516593083708 , 0.279430141761638 , 0.276356989295668 ,
0.273297054068577 , 0.270250256365875 , 0.267216518343561 , 0.264195763997261
, 0.261187919132721 , 0.258192911337619 , 0.255210669954662 ,
0.252241126055942 , 0.249284212418529 , 0.246339863501264 , 0.24340801542275
, 0.240488605940501 , 0.237581574431238 , 0.23468686187233 ,
0.231804410824339 , 0.228934165414681 , 0.226076071322381 , 0.223230075763918
, 0.220396127480152 , 0.217574176724331 , 0.214764175251174 ,
0.211966076307031 , 0.209179834621125 , 0.206405406397881 , 0.203642749310335
, 0.200891822494657 , 0.198152586545776 , 0.195425003514135 ,
0.192709036903589 , 0.190004651670465 , 0.187311814223801 , 0.1846304924268 ,
0.181960655599523 , 0.179302274522848 , 0.176655321443735 , 0.174019770081839
, 0.171395595637506 , 0.168782774801212 , 0.166181285764482 ,
0.163591108232366 , 0.161012223437511 , 0.158444614155925 , 0.15588826472448
, 0.153343161060263 , 0.150809290681846 , 0.148286642732575 ,
0.145775208005994 , 0.143274978973514 , 0.140785949814445 , 0.138308116448551
, 0.135841476571254 , 0.133386029691669 , 0.130941777173644 , 0.12850872228 ,
0.126086870220186 , 0.123676228201597 , 0.12127680548479 , 0.11888861344291 ,
0.116511665625611 , 0.114145977827839 , 0.111791568163838 , 0.109448457146812
, 0.107116667774684 , 0.104796225622487 , 0.102487158941935 ,
0.10018949876881 , 0.0979032790388625 , 0.095628536713009 , 0.093365311912691
, 0.0911136480663738 , 0.0888735920682759 , 0.0866451944505581 ,
0.0844285095703535 , 0.082223595813203 , 0.0800305158146631 ,
0.0778493367020961 , 0.0756801303589272 , 0.0735229737139814 ,
0.0713779490588905 , 0.0692451443970068 , 0.0671246538277886 ,
0.065016577971243 , 0.0629210244377582 , 0.06083810834954 ,
0.0587679529209339 , 0.0567106901062031 , 0.0546664613248891 ,
0.0526354182767924 , 0.0506177238609479 , 0.0486135532158687 ,
0.0466230949019305 , 0.0446465522512946 , 0.0426841449164746 ,
0.0407361106559411 , 0.0388027074045262 , 0.0368842156885674 ,
0.0349809414617162 , 0.0330932194585786 , 0.0312214171919203 ,
0.0293659397581334 , 0.0275272356696031 , 0.0257058040085489 ,
0.0239022033057959 , 0.0221170627073089 , 0.0203510962300445 ,
0.0186051212757247 , 0.0168800831525432 , 0.0151770883079353 ,
0.0134974506017399 , 0.0118427578579079 , 0.0102149714397015 ,
0.00861658276939875 , 0.00705087547137324 , 0.00552240329925101 ,
0.00403797259336304 , 0.00260907274610216 , 0.0012602859304986 ,
0.000477467764609386 } ; int32_T exitg1 ; do { exitg1 = 0 ; nyqhoqjzol (
state , u32 ) ; i = ( int32_T ) ( ( u32 [ 1 ] >> 24U ) + 1U ) ; r = ( ( (
real_T ) ( u32 [ 0 ] >> 3U ) * 1.6777216E+7 + ( real_T ) ( ( int32_T ) u32 [
1 ] & 16777215 ) ) * 2.2204460492503131E-16 - 1.0 ) * tmp [ i ] ; if (
muDoubleScalarAbs ( r ) <= tmp [ i - 1 ] ) { exitg1 = 1 ; } else if ( i < 256
) { x = hlp4ulzvlq ( state ) ; if ( ( tmp_p [ i - 1 ] - tmp_p [ i ] ) * x +
tmp_p [ i ] < muDoubleScalarExp ( - 0.5 * r * r ) ) { exitg1 = 1 ; } } else {
do { x = hlp4ulzvlq ( state ) ; x = muDoubleScalarLog ( x ) *
0.273661237329758 ; d_u = hlp4ulzvlq ( state ) ; } while ( ! ( - 2.0 *
muDoubleScalarLog ( d_u ) > x * x ) ) ; if ( r < 0.0 ) { r = x -
3.65415288536101 ; } else { r = 3.65415288536101 - x ; } exitg1 = 1 ; } }
while ( exitg1 == 0 ) ; return r ; } static creal_T ngizeo0ekg ( void ) {
creal_T r ; real_T im ; real_T re ; re = opp2d1xb2ua ( rtDW . cuu1zsu24f ) ;
im = opp2d1xb2ua ( rtDW . cuu1zsu24f ) ; if ( im == 0.0 ) { r . re = re /
1.4142135623730951 ; r . im = 0.0 ; } else if ( re == 0.0 ) { r . re = 0.0 ;
r . im = im / 1.4142135623730951 ; } else { r . re = re / 1.4142135623730951
; r . im = im / 1.4142135623730951 ; } return r ; } void MdlInitialize ( void
) { int32_T i ; int32_T polyIdxVal ; rtDW . pt5eromfcj . re = 0.0 ; rtDW .
pt5eromfcj . im = 0.0 ; rtDW . bx2b103j3q = false ; rtDW . jseolvrnea = 0 ;
rtDW . ate1uhb4qw = rtP . Delay_InitialCondition ; memset ( & rtDW .
ikfemt5lt2 [ 0 ] , 0 , sizeof ( creal_T ) << 2U ) ; memset ( & rtDW .
gbyowhygxr [ 0 ] , 0 , sizeof ( creal_T ) << 2U ) ; rtDW . chgjvbcbzb = false
; memset ( & rtDW . dd5j4umhh2 [ 0 ] , 0 , sizeof ( creal_T ) << 4U ) ; rtDW
. phw3qc5esn = 0 ; rtDW . b1k03uckiu = 35 ; rtDW . mahx1vfrrk = 7 ; rtDW .
fextltf3bq = 35 ; rtDW . oj03j4ixuy = 0 ; rtDW . jkwcjrsbfz . re = 0.0 ; rtDW
. jkwcjrsbfz . im = 0.0 ; rtDW . kviwuzsm51 . re = 0.0 ; rtDW . kviwuzsm51 .
im = 0.0 ; memset ( & rtDW . jhjvzmws0f [ 0 ] , 0 , 40U * sizeof ( creal_T )
) ; memset ( & rtDW . mpkdim1qis [ 0 ] , 0 , 78U * sizeof ( creal_T ) ) ;
rtDW . j4tyz1d51k [ 7U ] = 7 ; polyIdxVal = 8 ; for ( i = 0 ; i < 7 ; i ++ )
{ rtDW . j4tyz1d51k [ i ] = polyIdxVal % 8 ; polyIdxVal ++ ; } if ( rtDW .
j33qtkq40m . isInitialized == 1 ) { rtDW . j33qtkq40m . pDataIndex = 0.0 ; }
} void MdlStart ( void ) { int32_T i ; static const uint32_T tmp [ 625 ] = {
5489U , 1301868182U , 2938499221U , 2950281878U , 1875628136U , 751856242U ,
944701696U , 2243192071U , 694061057U , 219885934U , 2066767472U ,
3182869408U , 485472502U , 2336857883U , 1071588843U , 3418470598U ,
951210697U , 3693558366U , 2923482051U , 1793174584U , 2982310801U ,
1586906132U , 1951078751U , 1808158765U , 1733897588U , 431328322U ,
4202539044U , 530658942U , 1714810322U , 3025256284U , 3342585396U ,
1937033938U , 2640572511U , 1654299090U , 3692403553U , 4233871309U ,
3497650794U , 862629010U , 2943236032U , 2426458545U , 1603307207U ,
1133453895U , 3099196360U , 2208657629U , 2747653927U , 931059398U ,
761573964U , 3157853227U , 785880413U , 730313442U , 124945756U , 2937117055U
, 3295982469U , 1724353043U , 3021675344U , 3884886417U , 4010150098U ,
4056961966U , 699635835U , 2681338818U , 1339167484U , 720757518U ,
2800161476U , 2376097373U , 1532957371U , 3902664099U , 1238982754U ,
3725394514U , 3449176889U , 3570962471U , 4287636090U , 4087307012U ,
3603343627U , 202242161U , 2995682783U , 1620962684U , 3704723357U ,
371613603U , 2814834333U , 2111005706U , 624778151U , 2094172212U ,
4284947003U , 1211977835U , 991917094U , 1570449747U , 2962370480U ,
1259410321U , 170182696U , 146300961U , 2836829791U , 619452428U ,
2723670296U , 1881399711U , 1161269684U , 1675188680U , 4132175277U ,
780088327U , 3409462821U , 1036518241U , 1834958505U , 3048448173U ,
161811569U , 618488316U , 44795092U , 3918322701U , 1924681712U , 3239478144U
, 383254043U , 4042306580U , 2146983041U , 3992780527U , 3518029708U ,
3545545436U , 3901231469U , 1896136409U , 2028528556U , 2339662006U ,
501326714U , 2060962201U , 2502746480U , 561575027U , 581893337U ,
3393774360U , 1778912547U , 3626131687U , 2175155826U , 319853231U ,
986875531U , 819755096U , 2915734330U , 2688355739U , 3482074849U , 2736559U
, 2296975761U , 1029741190U , 2876812646U , 690154749U , 579200347U ,
4027461746U , 1285330465U , 2701024045U , 4117700889U , 759495121U ,
3332270341U , 2313004527U , 2277067795U , 4131855432U , 2722057515U ,
1264804546U , 3848622725U , 2211267957U , 4100593547U , 959123777U ,
2130745407U , 3194437393U , 486673947U , 1377371204U , 17472727U , 352317554U
, 3955548058U , 159652094U , 1232063192U , 3835177280U , 49423123U ,
3083993636U , 733092U , 2120519771U , 2573409834U , 1112952433U , 3239502554U
, 761045320U , 1087580692U , 2540165110U , 641058802U , 1792435497U ,
2261799288U , 1579184083U , 627146892U , 2165744623U , 2200142389U ,
2167590760U , 2381418376U , 1793358889U , 3081659520U , 1663384067U ,
2009658756U , 2689600308U , 739136266U , 2304581039U , 3529067263U ,
591360555U , 525209271U , 3131882996U , 294230224U , 2076220115U ,
3113580446U , 1245621585U , 1386885462U , 3203270426U , 123512128U ,
12350217U , 354956375U , 4282398238U , 3356876605U , 3888857667U , 157639694U
, 2616064085U , 1563068963U , 2762125883U , 4045394511U , 4180452559U ,
3294769488U , 1684529556U , 1002945951U , 3181438866U , 22506664U ,
691783457U , 2685221343U , 171579916U , 3878728600U , 2475806724U ,
2030324028U , 3331164912U , 1708711359U , 1970023127U , 2859691344U ,
2588476477U , 2748146879U , 136111222U , 2967685492U , 909517429U ,
2835297809U , 3206906216U , 3186870716U , 341264097U , 2542035121U ,
3353277068U , 548223577U , 3170936588U , 1678403446U , 297435620U ,
2337555430U , 466603495U , 1132321815U , 1208589219U , 696392160U ,
894244439U , 2562678859U , 470224582U , 3306867480U , 201364898U ,
2075966438U , 1767227936U , 2929737987U , 3674877796U , 2654196643U ,
3692734598U , 3528895099U , 2796780123U , 3048728353U , 842329300U ,
191554730U , 2922459673U , 3489020079U , 3979110629U , 1022523848U ,
2202932467U , 3583655201U , 3565113719U , 587085778U , 4176046313U ,
3013713762U , 950944241U , 396426791U , 3784844662U , 3477431613U ,
3594592395U , 2782043838U , 3392093507U , 3106564952U , 2829419931U ,
1358665591U , 2206918825U , 3170783123U , 31522386U , 2988194168U ,
1782249537U , 1105080928U , 843500134U , 1225290080U , 1521001832U ,
3605886097U , 2802786495U , 2728923319U , 3996284304U , 903417639U ,
1171249804U , 1020374987U , 2824535874U , 423621996U , 1988534473U ,
2493544470U , 1008604435U , 1756003503U , 1488867287U , 1386808992U ,
732088248U , 1780630732U , 2482101014U , 976561178U , 1543448953U ,
2602866064U , 2021139923U , 1952599828U , 2360242564U , 2117959962U ,
2753061860U , 2388623612U , 4138193781U , 2962920654U , 2284970429U ,
766920861U , 3457264692U , 2879611383U , 815055854U , 2332929068U ,
1254853997U , 3740375268U , 3799380844U , 4091048725U , 2006331129U ,
1982546212U , 686850534U , 1907447564U , 2682801776U , 2780821066U ,
998290361U , 1342433871U , 4195430425U , 607905174U , 3902331779U ,
2454067926U , 1708133115U , 1170874362U , 2008609376U , 3260320415U ,
2211196135U , 433538229U , 2728786374U , 2189520818U , 262554063U ,
1182318347U , 3710237267U , 1221022450U , 715966018U , 2417068910U ,
2591870721U , 2870691989U , 3418190842U , 4238214053U , 1540704231U ,
1575580968U , 2095917976U , 4078310857U , 2313532447U , 2110690783U ,
4056346629U , 4061784526U , 1123218514U , 551538993U , 597148360U ,
4120175196U , 3581618160U , 3181170517U , 422862282U , 3227524138U ,
1713114790U , 662317149U , 1230418732U , 928171837U , 1324564878U ,
1928816105U , 1786535431U , 2878099422U , 3290185549U , 539474248U ,
1657512683U , 552370646U , 1671741683U , 3655312128U , 1552739510U ,
2605208763U , 1441755014U , 181878989U , 3124053868U , 1447103986U ,
3183906156U , 1728556020U , 3502241336U , 3055466967U , 1013272474U ,
818402132U , 1715099063U , 2900113506U , 397254517U , 4194863039U ,
1009068739U , 232864647U , 2540223708U , 2608288560U , 2415367765U ,
478404847U , 3455100648U , 3182600021U , 2115988978U , 434269567U ,
4117179324U , 3461774077U , 887256537U , 3545801025U , 286388911U ,
3451742129U , 1981164769U , 786667016U , 3310123729U , 3097811076U ,
2224235657U , 2959658883U , 3370969234U , 2514770915U , 3345656436U ,
2677010851U , 2206236470U , 271648054U , 2342188545U , 4292848611U ,
3646533909U , 3754009956U , 3803931226U , 4160647125U , 1477814055U ,
4043852216U , 1876372354U , 3133294443U , 3871104810U , 3177020907U ,
2074304428U , 3479393793U , 759562891U , 164128153U , 1839069216U ,
2114162633U , 3989947309U , 3611054956U , 1333547922U , 835429831U ,
494987340U , 171987910U , 1252001001U , 370809172U , 3508925425U ,
2535703112U , 1276855041U , 1922855120U , 835673414U , 3030664304U ,
613287117U , 171219893U , 3423096126U , 3376881639U , 2287770315U ,
1658692645U , 1262815245U , 3957234326U , 1168096164U , 2968737525U ,
2655813712U , 2132313144U , 3976047964U , 326516571U , 353088456U ,
3679188938U , 3205649712U , 2654036126U , 1249024881U , 880166166U ,
691800469U , 2229503665U , 1673458056U , 4032208375U , 1851778863U ,
2563757330U , 376742205U , 1794655231U , 340247333U , 1505873033U ,
396524441U , 879666767U , 3335579166U , 3260764261U , 3335999539U ,
506221798U , 4214658741U , 975887814U , 2080536343U , 3360539560U ,
571586418U , 138896374U , 4234352651U , 2737620262U , 3928362291U ,
1516365296U , 38056726U , 3599462320U , 3585007266U , 3850961033U ,
471667319U , 1536883193U , 2310166751U , 1861637689U , 2530999841U ,
4139843801U , 2710569485U , 827578615U , 2012334720U , 2907369459U ,
3029312804U , 2820112398U , 1965028045U , 35518606U , 2478379033U ,
643747771U , 1924139484U , 4123405127U , 3811735531U , 3429660832U ,
3285177704U , 1948416081U , 1311525291U , 1183517742U , 1739192232U ,
3979815115U , 2567840007U , 4116821529U , 213304419U , 4125718577U ,
1473064925U , 2442436592U , 1893310111U , 4195361916U , 3747569474U ,
828465101U , 2991227658U , 750582866U , 1205170309U , 1409813056U ,
678418130U , 1171531016U , 3821236156U , 354504587U , 4202874632U ,
3882511497U , 1893248677U , 1903078632U , 26340130U , 2069166240U ,
3657122492U , 3725758099U , 831344905U , 811453383U , 3447711422U ,
2434543565U , 4166886888U , 3358210805U , 4142984013U , 2988152326U ,
3527824853U , 982082992U , 2809155763U , 190157081U , 3340214818U ,
2365432395U , 2548636180U , 2894533366U , 3474657421U , 2372634704U ,
2845748389U , 43024175U , 2774226648U , 1987702864U , 3186502468U ,
453610222U , 4204736567U , 1392892630U , 2471323686U , 2470534280U ,
3541393095U , 4269885866U , 3909911300U , 759132955U , 1482612480U ,
667715263U , 1795580598U , 2337923983U , 3390586366U , 581426223U ,
1515718634U , 476374295U , 705213300U , 363062054U , 2084697697U ,
2407503428U , 2292957699U , 2426213835U , 2199989172U , 1987356470U ,
4026755612U , 2147252133U , 270400031U , 1367820199U , 2369854699U ,
2844269403U , 79981964U , 624U } ; { bool externalInputIsInDatasetFormat =
false ; void * pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} rtDW . m2dn2xnnqj = true ; rtDW . j33qtkq40m . isInitialized = 1 ; rtDW .
miuqblj25w = 0U ; rtDW . gc3fngkune = true ; rtDW . bxgvjqvv03 = 7U ; rtDW .
miqhhd2uo2 = true ; memcpy ( & rtDW . cgcq15tqz2 [ 0 ] , & tmp [ 0 ] , 625U *
sizeof ( uint32_T ) ) ; rtDW . gkfm5uihb0 = true ; rtDW . jdlamz5s1g [ 0 ] =
362436069U ; rtDW . jdlamz5s1g [ 1 ] = 521288629U ; rtDW . i5fyasx04o = true
; rtDW . krgyhlve5g = 1144108930U ; rtDW . mbdjklko3i = true ; rtDW .
lpy5mzzed1 . isInitialized = 0 ; rtDW . njjxls55cs = true ; oyxxnyztmb ( &
rtDW . lpy5mzzed1 ) ; halideTBBInit ( & rtDW . on4d5t4ft3 , 1 , false ) ;
rtDW . cnhxmgap22 = true ; rtDW . e3grigdkp0 = 7U ; rtDW . lbsrysvv05 = true
; memcpy ( & rtDW . cuu1zsu24f [ 0 ] , & tmp [ 0 ] , 625U * sizeof ( uint32_T
) ) ; rtDW . hg0mobsir0 = true ; rtDW . mb0j0kmjar = true ; rtDW . d3xzp3vtkg
= 1144108930U ; rtDW . lmfcjcrcjv = true ; rtDW . g2xqaw3dz0 = 0U ; rtDW .
g1hyfm4tj3 = true ; rtDW . ipb0ry35mu [ 0 ] = 362436069U ; rtDW . kpo4xu3rlc
[ 0 ] = 362436069U ; rtDW . ipb0ry35mu [ 1 ] = 521288629U ; rtDW . kpo4xu3rlc
[ 1 ] = 521288629U ; rtDW . mdfzrip4mj = true ; rtDW . kiqazyiq00 . Seed =
67.0 ; rtDW . kiqazyiq00 . isInitialized = 0 ; rtDW . ksl0kmigx2 = true ;
rtDW . kiqazyiq00 . EbNo = rtP . AWGNChannel_EbNo ; gwxej0ur3b ( & rtDW .
kiqazyiq00 , rtP . AWGNChannel_SignalPower ) ; rtDW . kiqazyiq00 .
isInitialized = 1 ; for ( i = 0 ; i < 8 ; i ++ ) { rtDW . kiqazyiq00 .
inputVarSize . f1 [ i ] = 1U ; } ciytelebuu ( & rtDW . kiqazyiq00 ) ;
in0ndyl4sj ( ) ; rtDW . kiqazyiq00 . TunablePropsChanged = false ;
halideTBBInit ( & rtDW . kwhxs250ag , 1 , false ) ; MdlInitialize ( ) ; }
void MdlOutputs ( int_T tid ) { creal_T oymnjhnzqz ; creal_T randData ;
real_T csj53zpyth ; int32_T j ; int32_T orhlfsfopt_idx_0 ; int32_T
orhlfsfopt_idx_1 ; uint32_T outBufIdx ; static const int8_T tmp [ 13 ] = { -
1 , - 1 , - 1 , - 1 , - 1 , 1 , 1 , - 1 , - 1 , 1 , - 1 , 1 , - 1 } ;
boolean_T exitg1 ; if ( ssIsSampleHit ( rtS , 3 , 0 ) ) { if (
muDoubleScalarIsNaN ( rtDW . j33qtkq40m . pDataIndex ) || muDoubleScalarIsInf
( rtDW . j33qtkq40m . pDataIndex ) ) { csj53zpyth = ( rtNaN ) ; } else if (
rtDW . j33qtkq40m . pDataIndex == 0.0 ) { csj53zpyth = 0.0 ; } else {
csj53zpyth = muDoubleScalarRem ( rtDW . j33qtkq40m . pDataIndex , 13.0 ) ; if
( csj53zpyth == 0.0 ) { csj53zpyth = 0.0 ; } else if ( rtDW . j33qtkq40m .
pDataIndex < 0.0 ) { csj53zpyth += 13.0 ; } } rtDW . j33qtkq40m . pDataIndex
= csj53zpyth + 1.0 ; orhlfsfopt_idx_1 = ( int32_T ) muDoubleScalarRem ( tmp [
( int32_T ) ( csj53zpyth + 1.0 ) - 1 ] , 4.294967296E+9 ) ; if ( rtDW .
lpy5mzzed1 . TunablePropsChanged ) { rtDW . lpy5mzzed1 . TunablePropsChanged
= false ; } csj53zpyth = kogkrd0iea ( ) ; outBufIdx = 0U ; outBufIdx <<= 1U ;
if ( orhlfsfopt_idx_1 < 0 ) { orhlfsfopt_idx_1 = - ( int32_T ) ( uint32_T ) -
( real_T ) orhlfsfopt_idx_1 ; } outBufIdx |= ( uint8_T ) ( ( orhlfsfopt_idx_1
* rtP . Gain1_Gain + rtP . Bias_Bias ) >> 1 ) ; outBufIdx <<= 1U ; outBufIdx
|= ( uint32_T ) ( csj53zpyth > 0.5 ) ; csj53zpyth = outBufIdx ; csj53zpyth =
look1_binlxpw ( csj53zpyth , rtP . Symbolmapping_bp01Data , rtP .
Symbolmapping_tableData , 3U ) ; outBufIdx = ( uint32_T ) csj53zpyth ;
orhlfsfopt_idx_1 = ( int32_T ) outBufIdx & 1 ; outBufIdx >>= 1U ;
orhlfsfopt_idx_0 = ( int32_T ) outBufIdx & 1 ; outBufIdx >>= 1U ; rtB .
moprdribiz . re = rtP . Gain_Gain * ( real_T ) orhlfsfopt_idx_0 - rtP .
Constant_Value ; rtB . moprdribiz . im = rtP . Gain_Gain * ( real_T )
orhlfsfopt_idx_1 - rtP . Constant_Value ; if ( rtDW . bx2b103j3q ) {
orhlfsfopt_idx_1 = 2 ; } else { orhlfsfopt_idx_1 = 0 ; } rtDW . ikfemt5lt2 [
orhlfsfopt_idx_1 ] . re = rtB . moprdribiz . re * rtP .
Pulseshaping_FILTER_COEFF [ 0 ] + rtDW . pt5eromfcj . re * rtP .
Pulseshaping_FILTER_COEFF [ 1 ] ; rtDW . ikfemt5lt2 [ orhlfsfopt_idx_1 ] . im
= rtB . moprdribiz . im * rtP . Pulseshaping_FILTER_COEFF [ 0 ] + rtDW .
pt5eromfcj . im * rtP . Pulseshaping_FILTER_COEFF [ 1 ] ; rtDW . ikfemt5lt2 [
orhlfsfopt_idx_1 + 1 ] . re = rtB . moprdribiz . re * rtP .
Pulseshaping_FILTER_COEFF [ 2 ] + rtDW . pt5eromfcj . re * rtP .
Pulseshaping_FILTER_COEFF [ 3 ] ; rtDW . ikfemt5lt2 [ orhlfsfopt_idx_1 + 1 ]
. im = rtB . moprdribiz . im * rtP . Pulseshaping_FILTER_COEFF [ 2 ] + rtDW .
pt5eromfcj . im * rtP . Pulseshaping_FILTER_COEFF [ 3 ] ; rtDW . bx2b103j3q =
! rtDW . bx2b103j3q ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { oymnjhnzqz =
rtDW . ikfemt5lt2 [ rtDW . jseolvrnea ] ; rtDW . jseolvrnea ++ ; if ( rtDW .
jseolvrnea >= 4 ) { rtDW . jseolvrnea = 0 ; } rtB . i5ilelgt54 = oymnjhnzqz .
im ; csj53zpyth = oymnjhnzqz . re ; oymnjhnzqz . re = rtP . Phaseoffset_Gain
* csj53zpyth ; oymnjhnzqz . im = rtP . Phaseoffset_Gain * rtDW . ate1uhb4qw ;
rtDW . eybefhgiyi [ 0 ] = rtDW . gbyowhygxr [ 3 ] ; rtDW . eybefhgiyi [ 1 ] =
rtDW . gbyowhygxr [ 2 ] ; rtDW . eybefhgiyi [ 2 ] = rtDW . gbyowhygxr [ 1 ] ;
rtDW . eybefhgiyi [ 3 ] = rtDW . gbyowhygxr [ 0 ] ; for ( orhlfsfopt_idx_1 =
0 ; orhlfsfopt_idx_1 < 8 ; orhlfsfopt_idx_1 ++ ) { orhlfsfopt_idx_0 =
orhlfsfopt_idx_1 * 5 ; for ( j = 0 ; j < 5 ; j ++ ) { rtDW . coksx155ze [
orhlfsfopt_idx_0 + j ] = rtP . FIRInterpolation_FILTER_COEFF [ (
orhlfsfopt_idx_0 - j ) + 4 ] ; } } if ( rtDW . chgjvbcbzb ) {
orhlfsfopt_idx_1 = 8 ; } else { orhlfsfopt_idx_1 = 0 ; }
processHalide_firInterpolatorCRD ( & oymnjhnzqz , & rtDW . coksx155ze [ 0U ]
, 1 , 5 , 1 , 8 , & rtDW . gbyowhygxr [ 0U ] , & rtDW . dd5j4umhh2 [ 0U ] , &
rtDW . eybefhgiyi [ 0U ] , rtDW . on4d5t4ft3 , orhlfsfopt_idx_1 ) ; rtDW .
gbyowhygxr [ 0 ] = rtDW . eybefhgiyi [ 3 ] ; rtDW . gbyowhygxr [ 1 ] = rtDW .
eybefhgiyi [ 2 ] ; rtDW . gbyowhygxr [ 2 ] = rtDW . eybefhgiyi [ 1 ] ; rtDW .
gbyowhygxr [ 3 ] = rtDW . eybefhgiyi [ 0 ] ; rtDW . chgjvbcbzb = ! rtDW .
chgjvbcbzb ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { oymnjhnzqz = rtDW .
dd5j4umhh2 [ rtDW . phw3qc5esn ] ; rtDW . phw3qc5esn ++ ; if ( rtDW .
phw3qc5esn >= 16 ) { rtDW . phw3qc5esn = 0 ; } if ( rtDW . kiqazyiq00 . EbNo
!= rtP . AWGNChannel_EbNo ) { if ( rtDW . kiqazyiq00 . isInitialized == 1 ) {
rtDW . kiqazyiq00 . TunablePropsChanged = true ; } rtDW . kiqazyiq00 . EbNo =
rtP . AWGNChannel_EbNo ; } if ( rtDW . kiqazyiq00 . SignalPower != rtP .
AWGNChannel_SignalPower ) { if ( rtDW . kiqazyiq00 . isInitialized == 1 ) {
rtDW . kiqazyiq00 . TunablePropsChanged = true ; } gwxej0ur3b ( & rtDW .
kiqazyiq00 , rtP . AWGNChannel_SignalPower ) ; } if ( rtDW . kiqazyiq00 .
TunablePropsChanged ) { rtDW . kiqazyiq00 . TunablePropsChanged = false ;
rtDW . kiqazyiq00 . pNumChanFromProp = 1.0 ; rtDW . kiqazyiq00 . pStd =
muDoubleScalarSqrt ( rtDW . kiqazyiq00 . SignalPower / ( muDoubleScalarPower
( 10.0 , rtDW . kiqazyiq00 . EbNo / 10.0 ) * 2.0 ) ) ; } orhlfsfopt_idx_0 = 0
; exitg1 = false ; while ( ( ! exitg1 ) && ( orhlfsfopt_idx_0 < 8 ) ) { if (
rtDW . kiqazyiq00 . inputVarSize . f1 [ orhlfsfopt_idx_0 ] != 1U ) { for (
orhlfsfopt_idx_1 = 0 ; orhlfsfopt_idx_1 < 8 ; orhlfsfopt_idx_1 ++ ) { rtDW .
kiqazyiq00 . inputVarSize . f1 [ orhlfsfopt_idx_1 ] = 1U ; } exitg1 = true ;
} else { orhlfsfopt_idx_0 ++ ; } } if ( ( rtDW . kiqazyiq00 . pIsVarChannel
|| ( rtDW . kiqazyiq00 . pFirstInputNumChan != 1.0 ) ) && ( ! rtDW .
kiqazyiq00 . pIsVarChannel ) ) { rtDW . kiqazyiq00 . pIsVarChannel = true ; }
randData = ngizeo0ekg ( ) ; oymnjhnzqz . re += rtDW . kiqazyiq00 . pStd *
randData . re ; oymnjhnzqz . im += rtDW . kiqazyiq00 . pStd * randData . im ;
outBufIdx = ( uint32_T ) rtDW . oj03j4ixuy ; for ( orhlfsfopt_idx_1 = 0 ;
orhlfsfopt_idx_1 < 8 ; orhlfsfopt_idx_1 ++ ) { orhlfsfopt_idx_0 =
orhlfsfopt_idx_1 * 5 ; for ( j = 0 ; j < 5 ; j ++ ) { rtDW . hax1vszx2y [
orhlfsfopt_idx_0 + j ] = rtP . FIRDecimation_FILT [ ( orhlfsfopt_idx_0 - j )
+ 4 ] ; } } processHalide_firDecimatorCRD ( & oymnjhnzqz , & rtDW .
hax1vszx2y [ 0U ] , 1U , 5U , 1U , 8U , & rtDW . jhjvzmws0f [ 0U ] , & rtDW .
jkwcjrsbfz , & rtDW . mpkdim1qis [ 0U ] , & rtDW . kviwuzsm51 , & rtDW .
mahx1vfrrk , & rtDW . b1k03uckiu , & rtDW . j4tyz1d51k [ 0U ] , & outBufIdx ,
true , false , rtDW . kwhxs250ag ) ; orhlfsfopt_idx_0 = rtDW . b1k03uckiu ;
orhlfsfopt_idx_1 = div_nde_s32_floor ( orhlfsfopt_idx_0 , 5 ) ; rtDW .
j4tyz1d51k [ 7U ] = orhlfsfopt_idx_1 % 8 ; for ( orhlfsfopt_idx_0 = 0 ;
orhlfsfopt_idx_0 < 7 ; orhlfsfopt_idx_0 ++ ) { rtDW . j4tyz1d51k [
orhlfsfopt_idx_0 ] = ( orhlfsfopt_idx_1 + 1 ) % 8 ; orhlfsfopt_idx_1 ++ ; }
rtDW . oj03j4ixuy = ( int32_T ) outBufIdx ; if ( ssIsSpecialSampleHit ( rtS ,
2 , 1 , 0 ) ) { rtB . junrgsnmb0 = rtDW . jkwcjrsbfz ; rtDW . oj03j4ixuy = 0
; } } UNUSED_PARAMETER ( tid ) ; } void MdlOutputsTID4 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) { if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW . pt5eromfcj = rtB . moprdribiz ; } if
( ssIsSampleHit ( rtS , 2 , 0 ) ) { rtDW . ate1uhb4qw = rtB . i5ilelgt54 ; }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID4 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { } static void
mr_SimulinkOQPSK_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) ; static void
mr_SimulinkOQPSK_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int j
, const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_SimulinkOQPSK_restoreDataFromMxArray ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_SimulinkOQPSK_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_SimulinkOQPSK_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i ,
int j , uint_T bitVal ) ; static void mr_SimulinkOQPSK_cacheBitFieldToMxArray
( mxArray * destArray , mwIndex i , int j , uint_T bitVal ) {
mxSetFieldByNumber ( destArray , i , j , mxCreateDoubleScalar ( ( real_T )
bitVal ) ) ; } static uint_T mr_SimulinkOQPSK_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) ; static
uint_T mr_SimulinkOQPSK_extractBitFieldFromMxArray ( const mxArray * srcArray
, mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_SimulinkOQPSK_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex
i , int j , mwIndex offset , const void * srcData , size_t numBytes ) ;
static void mr_SimulinkOQPSK_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_SimulinkOQPSK_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void mr_SimulinkOQPSK_restoreDataFromMxArrayWithOffset (
void * destData , const mxArray * srcArray , mwIndex i , int j , mwIndex
offset , size_t numBytes ) { const uint8_T * varData = ( const uint8_T * )
mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T *
) destData , ( const uint8_T * ) & varData [ offset * numBytes ] , numBytes )
; } static void mr_SimulinkOQPSK_cacheBitFieldToCellArrayWithOffset ( mxArray
* destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_SimulinkOQPSK_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( real_T ) fieldVal ) ) ; } static uint_T
mr_SimulinkOQPSK_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_SimulinkOQPSK_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_SimulinkOQPSK_GetDWork ( ) { static
const char_T * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ;
mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB
) , sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 60 ] = {
"rtDW.kiqazyiq00" , "rtDW.j33qtkq40m" , "rtDW.pt5eromfcj" , "rtDW.gbyowhygxr"
, "rtDW.kviwuzsm51" , "rtDW.jhjvzmws0f" , "rtDW.jkwcjrsbfz" ,
"rtDW.mpkdim1qis" , "rtDW.ate1uhb4qw" , "rtDW.hax1vszx2y" , "rtDW.ikfemt5lt2"
, "rtDW.dd5j4umhh2" , "rtDW.eybefhgiyi" , "rtDW.fkshk3as53" ,
"rtDW.kxculzx4lb" , "rtDW.pbieyixh0q" , "rtDW.fm0vokcho4" , "rtDW.j43xnixtdn"
, "rtDW.krmeuxufvy" , "rtDW.coksx155ze" , "rtDW.lpy5mzzed1" ,
"rtDW.mahx1vfrrk" , "rtDW.b1k03uckiu" , "rtDW.fextltf3bq" , "rtDW.oj03j4ixuy"
, "rtDW.j4tyz1d51k" , "rtDW.kwhxs250ag" , "rtDW.jseolvrnea" ,
"rtDW.phw3qc5esn" , "rtDW.on4d5t4ft3" , "rtDW.cxw1tnf414" , "rtDW.krgyhlve5g"
, "rtDW.cgcq15tqz2" , "rtDW.jdlamz5s1g" , "rtDW.bxgvjqvv03" ,
"rtDW.ax22qpdshl" , "rtDW.g2xqaw3dz0" , "rtDW.cuu1zsu24f" , "rtDW.ipb0ry35mu"
, "rtDW.d3xzp3vtkg" , "rtDW.e3grigdkp0" , "rtDW.kpo4xu3rlc" ,
"rtDW.miuqblj25w" , "rtDW.bx2b103j3q" , "rtDW.chgjvbcbzb" , "rtDW.njjxls55cs"
, "rtDW.gc3fngkune" , "rtDW.mbdjklko3i" , "rtDW.i5fyasx04o" ,
"rtDW.gkfm5uihb0" , "rtDW.miqhhd2uo2" , "rtDW.m2dn2xnnqj" , "rtDW.ksl0kmigx2"
, "rtDW.cnhxmgap22" , "rtDW.mdfzrip4mj" , "rtDW.g1hyfm4tj3" ,
"rtDW.lmfcjcrcjv" , "rtDW.mb0j0kmjar" , "rtDW.hg0mobsir0" , "rtDW.lbsrysvv05"
, } ; mxArray * rtdwData = mxCreateStructMatrix ( 1 , 1 , 60 ,
rtdwDataFieldNames ) ; mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 0
, ( const void * ) & ( rtDW . kiqazyiq00 ) , sizeof ( rtDW . kiqazyiq00 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * ) & (
rtDW . j33qtkq40m ) , sizeof ( rtDW . j33qtkq40m ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * ) & (
rtDW . pt5eromfcj ) , sizeof ( rtDW . pt5eromfcj ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * ) & (
rtDW . gbyowhygxr ) , sizeof ( rtDW . gbyowhygxr ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * ) & (
rtDW . kviwuzsm51 ) , sizeof ( rtDW . kviwuzsm51 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * ) & (
rtDW . jhjvzmws0f ) , sizeof ( rtDW . jhjvzmws0f ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * ) & (
rtDW . jkwcjrsbfz ) , sizeof ( rtDW . jkwcjrsbfz ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * ) & (
rtDW . mpkdim1qis ) , sizeof ( rtDW . mpkdim1qis ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * ) & (
rtDW . ate1uhb4qw ) , sizeof ( rtDW . ate1uhb4qw ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * ) & (
rtDW . hax1vszx2y ) , sizeof ( rtDW . hax1vszx2y ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void * ) &
( rtDW . ikfemt5lt2 ) , sizeof ( rtDW . ikfemt5lt2 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void * ) &
( rtDW . dd5j4umhh2 ) , sizeof ( rtDW . dd5j4umhh2 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void * ) &
( rtDW . eybefhgiyi ) , sizeof ( rtDW . eybefhgiyi ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void * ) &
( rtDW . fkshk3as53 ) , sizeof ( rtDW . fkshk3as53 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void * ) &
( rtDW . kxculzx4lb ) , sizeof ( rtDW . kxculzx4lb ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void * ) &
( rtDW . pbieyixh0q ) , sizeof ( rtDW . pbieyixh0q ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void * ) &
( rtDW . fm0vokcho4 ) , sizeof ( rtDW . fm0vokcho4 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void * ) &
( rtDW . j43xnixtdn ) , sizeof ( rtDW . j43xnixtdn ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void * ) &
( rtDW . krmeuxufvy ) , sizeof ( rtDW . krmeuxufvy ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void * ) &
( rtDW . coksx155ze ) , sizeof ( rtDW . coksx155ze ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void * ) &
( rtDW . lpy5mzzed1 ) , sizeof ( rtDW . lpy5mzzed1 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void * ) &
( rtDW . mahx1vfrrk ) , sizeof ( rtDW . mahx1vfrrk ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void * ) &
( rtDW . b1k03uckiu ) , sizeof ( rtDW . b1k03uckiu ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void * ) &
( rtDW . fextltf3bq ) , sizeof ( rtDW . fextltf3bq ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void * ) &
( rtDW . oj03j4ixuy ) , sizeof ( rtDW . oj03j4ixuy ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void * ) &
( rtDW . j4tyz1d51k ) , sizeof ( rtDW . j4tyz1d51k ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void * ) &
( rtDW . kwhxs250ag ) , sizeof ( rtDW . kwhxs250ag ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void * ) &
( rtDW . jseolvrnea ) , sizeof ( rtDW . jseolvrnea ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void * ) &
( rtDW . phw3qc5esn ) , sizeof ( rtDW . phw3qc5esn ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void * ) &
( rtDW . on4d5t4ft3 ) , sizeof ( rtDW . on4d5t4ft3 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void * ) &
( rtDW . cxw1tnf414 ) , sizeof ( rtDW . cxw1tnf414 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void * ) &
( rtDW . krgyhlve5g ) , sizeof ( rtDW . krgyhlve5g ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void * ) &
( rtDW . cgcq15tqz2 ) , sizeof ( rtDW . cgcq15tqz2 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void * ) &
( rtDW . jdlamz5s1g ) , sizeof ( rtDW . jdlamz5s1g ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void * ) &
( rtDW . bxgvjqvv03 ) , sizeof ( rtDW . bxgvjqvv03 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void * ) &
( rtDW . ax22qpdshl ) , sizeof ( rtDW . ax22qpdshl ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void * ) &
( rtDW . g2xqaw3dz0 ) , sizeof ( rtDW . g2xqaw3dz0 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void * ) &
( rtDW . cuu1zsu24f ) , sizeof ( rtDW . cuu1zsu24f ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void * ) &
( rtDW . ipb0ry35mu ) , sizeof ( rtDW . ipb0ry35mu ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void * ) &
( rtDW . d3xzp3vtkg ) , sizeof ( rtDW . d3xzp3vtkg ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const void * ) &
( rtDW . e3grigdkp0 ) , sizeof ( rtDW . e3grigdkp0 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void * ) &
( rtDW . kpo4xu3rlc ) , sizeof ( rtDW . kpo4xu3rlc ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 42 , ( const void * ) &
( rtDW . miuqblj25w ) , sizeof ( rtDW . miuqblj25w ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const void * ) &
( rtDW . bx2b103j3q ) , sizeof ( rtDW . bx2b103j3q ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void * ) &
( rtDW . chgjvbcbzb ) , sizeof ( rtDW . chgjvbcbzb ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 45 , ( const void * ) &
( rtDW . njjxls55cs ) , sizeof ( rtDW . njjxls55cs ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const void * ) &
( rtDW . gc3fngkune ) , sizeof ( rtDW . gc3fngkune ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void * ) &
( rtDW . mbdjklko3i ) , sizeof ( rtDW . mbdjklko3i ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 48 , ( const void * ) &
( rtDW . i5fyasx04o ) , sizeof ( rtDW . i5fyasx04o ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 49 , ( const void * ) &
( rtDW . gkfm5uihb0 ) , sizeof ( rtDW . gkfm5uihb0 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 50 , ( const void * ) &
( rtDW . miqhhd2uo2 ) , sizeof ( rtDW . miqhhd2uo2 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 51 , ( const void * ) &
( rtDW . m2dn2xnnqj ) , sizeof ( rtDW . m2dn2xnnqj ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 52 , ( const void * ) &
( rtDW . ksl0kmigx2 ) , sizeof ( rtDW . ksl0kmigx2 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 53 , ( const void * ) &
( rtDW . cnhxmgap22 ) , sizeof ( rtDW . cnhxmgap22 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 54 , ( const void * ) &
( rtDW . mdfzrip4mj ) , sizeof ( rtDW . mdfzrip4mj ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 55 , ( const void * ) &
( rtDW . g1hyfm4tj3 ) , sizeof ( rtDW . g1hyfm4tj3 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 56 , ( const void * ) &
( rtDW . lmfcjcrcjv ) , sizeof ( rtDW . lmfcjcrcjv ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 57 , ( const void * ) &
( rtDW . mb0j0kmjar ) , sizeof ( rtDW . mb0j0kmjar ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 58 , ( const void * ) &
( rtDW . hg0mobsir0 ) , sizeof ( rtDW . hg0mobsir0 ) ) ;
mr_SimulinkOQPSK_cacheDataAsMxArray ( rtdwData , 0 , 59 , ( const void * ) &
( rtDW . lbsrysvv05 ) , sizeof ( rtDW . lbsrysvv05 ) ) ; mxSetFieldByNumber (
ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void mr_SimulinkOQPSK_SetDWork
( const mxArray * ssDW ) { ( void ) ssDW ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0
, sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW ,
0 , 1 ) ; mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW .
kiqazyiq00 ) , rtdwData , 0 , 0 , sizeof ( rtDW . kiqazyiq00 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . j33qtkq40m )
, rtdwData , 0 , 1 , sizeof ( rtDW . j33qtkq40m ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . pt5eromfcj )
, rtdwData , 0 , 2 , sizeof ( rtDW . pt5eromfcj ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . gbyowhygxr )
, rtdwData , 0 , 3 , sizeof ( rtDW . gbyowhygxr ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . kviwuzsm51 )
, rtdwData , 0 , 4 , sizeof ( rtDW . kviwuzsm51 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . jhjvzmws0f )
, rtdwData , 0 , 5 , sizeof ( rtDW . jhjvzmws0f ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . jkwcjrsbfz )
, rtdwData , 0 , 6 , sizeof ( rtDW . jkwcjrsbfz ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . mpkdim1qis )
, rtdwData , 0 , 7 , sizeof ( rtDW . mpkdim1qis ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . ate1uhb4qw )
, rtdwData , 0 , 8 , sizeof ( rtDW . ate1uhb4qw ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . hax1vszx2y )
, rtdwData , 0 , 9 , sizeof ( rtDW . hax1vszx2y ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . ikfemt5lt2 )
, rtdwData , 0 , 10 , sizeof ( rtDW . ikfemt5lt2 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . dd5j4umhh2 )
, rtdwData , 0 , 11 , sizeof ( rtDW . dd5j4umhh2 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . eybefhgiyi )
, rtdwData , 0 , 12 , sizeof ( rtDW . eybefhgiyi ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . fkshk3as53 )
, rtdwData , 0 , 13 , sizeof ( rtDW . fkshk3as53 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . kxculzx4lb )
, rtdwData , 0 , 14 , sizeof ( rtDW . kxculzx4lb ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . pbieyixh0q )
, rtdwData , 0 , 15 , sizeof ( rtDW . pbieyixh0q ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . fm0vokcho4 )
, rtdwData , 0 , 16 , sizeof ( rtDW . fm0vokcho4 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . j43xnixtdn )
, rtdwData , 0 , 17 , sizeof ( rtDW . j43xnixtdn ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . krmeuxufvy )
, rtdwData , 0 , 18 , sizeof ( rtDW . krmeuxufvy ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . coksx155ze )
, rtdwData , 0 , 19 , sizeof ( rtDW . coksx155ze ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . lpy5mzzed1 )
, rtdwData , 0 , 20 , sizeof ( rtDW . lpy5mzzed1 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . mahx1vfrrk )
, rtdwData , 0 , 21 , sizeof ( rtDW . mahx1vfrrk ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . b1k03uckiu )
, rtdwData , 0 , 22 , sizeof ( rtDW . b1k03uckiu ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . fextltf3bq )
, rtdwData , 0 , 23 , sizeof ( rtDW . fextltf3bq ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . oj03j4ixuy )
, rtdwData , 0 , 24 , sizeof ( rtDW . oj03j4ixuy ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . j4tyz1d51k )
, rtdwData , 0 , 25 , sizeof ( rtDW . j4tyz1d51k ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . kwhxs250ag )
, rtdwData , 0 , 26 , sizeof ( rtDW . kwhxs250ag ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . jseolvrnea )
, rtdwData , 0 , 27 , sizeof ( rtDW . jseolvrnea ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . phw3qc5esn )
, rtdwData , 0 , 28 , sizeof ( rtDW . phw3qc5esn ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . on4d5t4ft3 )
, rtdwData , 0 , 29 , sizeof ( rtDW . on4d5t4ft3 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . cxw1tnf414 )
, rtdwData , 0 , 30 , sizeof ( rtDW . cxw1tnf414 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . krgyhlve5g )
, rtdwData , 0 , 31 , sizeof ( rtDW . krgyhlve5g ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . cgcq15tqz2 )
, rtdwData , 0 , 32 , sizeof ( rtDW . cgcq15tqz2 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . jdlamz5s1g )
, rtdwData , 0 , 33 , sizeof ( rtDW . jdlamz5s1g ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . bxgvjqvv03 )
, rtdwData , 0 , 34 , sizeof ( rtDW . bxgvjqvv03 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . ax22qpdshl )
, rtdwData , 0 , 35 , sizeof ( rtDW . ax22qpdshl ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . g2xqaw3dz0 )
, rtdwData , 0 , 36 , sizeof ( rtDW . g2xqaw3dz0 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . cuu1zsu24f )
, rtdwData , 0 , 37 , sizeof ( rtDW . cuu1zsu24f ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . ipb0ry35mu )
, rtdwData , 0 , 38 , sizeof ( rtDW . ipb0ry35mu ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . d3xzp3vtkg )
, rtdwData , 0 , 39 , sizeof ( rtDW . d3xzp3vtkg ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . e3grigdkp0 )
, rtdwData , 0 , 40 , sizeof ( rtDW . e3grigdkp0 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . kpo4xu3rlc )
, rtdwData , 0 , 41 , sizeof ( rtDW . kpo4xu3rlc ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . miuqblj25w )
, rtdwData , 0 , 42 , sizeof ( rtDW . miuqblj25w ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . bx2b103j3q )
, rtdwData , 0 , 43 , sizeof ( rtDW . bx2b103j3q ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . chgjvbcbzb )
, rtdwData , 0 , 44 , sizeof ( rtDW . chgjvbcbzb ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . njjxls55cs )
, rtdwData , 0 , 45 , sizeof ( rtDW . njjxls55cs ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . gc3fngkune )
, rtdwData , 0 , 46 , sizeof ( rtDW . gc3fngkune ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . mbdjklko3i )
, rtdwData , 0 , 47 , sizeof ( rtDW . mbdjklko3i ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . i5fyasx04o )
, rtdwData , 0 , 48 , sizeof ( rtDW . i5fyasx04o ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . gkfm5uihb0 )
, rtdwData , 0 , 49 , sizeof ( rtDW . gkfm5uihb0 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . miqhhd2uo2 )
, rtdwData , 0 , 50 , sizeof ( rtDW . miqhhd2uo2 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . m2dn2xnnqj )
, rtdwData , 0 , 51 , sizeof ( rtDW . m2dn2xnnqj ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . ksl0kmigx2 )
, rtdwData , 0 , 52 , sizeof ( rtDW . ksl0kmigx2 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . cnhxmgap22 )
, rtdwData , 0 , 53 , sizeof ( rtDW . cnhxmgap22 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . mdfzrip4mj )
, rtdwData , 0 , 54 , sizeof ( rtDW . mdfzrip4mj ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . g1hyfm4tj3 )
, rtdwData , 0 , 55 , sizeof ( rtDW . g1hyfm4tj3 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . lmfcjcrcjv )
, rtdwData , 0 , 56 , sizeof ( rtDW . lmfcjcrcjv ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . mb0j0kmjar )
, rtdwData , 0 , 57 , sizeof ( rtDW . mb0j0kmjar ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . hg0mobsir0 )
, rtdwData , 0 , 58 , sizeof ( rtDW . hg0mobsir0 ) ) ;
mr_SimulinkOQPSK_restoreDataFromMxArray ( ( void * ) & ( rtDW . lbsrysvv05 )
, rtdwData , 0 , 59 , sizeof ( rtDW . lbsrysvv05 ) ) ; } } mxArray *
mr_SimulinkOQPSK_GetSimStateDisallowedBlocks ( ) { mxArray * data =
mxCreateCellMatrix ( 4 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const
char_T * blockType [ 4 ] = { "ConstellationDiagram" , "MATLABSystem" ,
"MATLABSystem" , "MATLABSystem" , } ; static const char_T * blockPath [ 4 ] =
{ "SimulinkOQPSK/Constellation Diagram" , "SimulinkOQPSK/AWGN Channel" ,
"SimulinkOQPSK/Barker Code Generator" ,
"SimulinkOQPSK/Bernoulli Binary Generator" , } ; static const int reason [ 4
] = { 0 , 6 , 6 , 6 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 4 ; ++ ( subs [
0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ;
subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ;
mxSetCell ( data , offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs [
0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 4 ) ;
ssSetNumBlocks ( rtS , 30 ) ; ssSetNumBlockIO ( rtS , 3 ) ;
ssSetNumBlockParams ( rtS , 101 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 6.25E-8 ) ;
ssSetSampleTime ( rtS , 2 , 5.0E-7 ) ; ssSetSampleTime ( rtS , 3 , 1.0E-6 ) ;
ssSetOffsetTime ( rtS , 0 , 1.0 ) ; ssSetOffsetTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 2 , 0.0 ) ; ssSetOffsetTime ( rtS , 3 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2471231377U ) ;
ssSetChecksumVal ( rtS , 1 , 1996571106U ) ; ssSetChecksumVal ( rtS , 2 ,
1402774140U ) ; ssSetChecksumVal ( rtS , 3 , 1784209955U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 0 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 30 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; }
SimulinkOQPSK_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS
, true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "SimulinkOQPSK" ) ;
ssSetPath ( rtS , "SimulinkOQPSK" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal
( rtS , 1.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ;
} { { static int_T rt_LoggedStateWidths [ ] = { 1 , 4 , 1 , 40 , 1 , 78 , 1 ,
40 , 1 , 1 , 1 , 1 , 8 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] =
{ 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 4 , 1 , 40 , 1 , 78 , 1 , 40 , 1 , 1 , 1
, 1 , 8 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_INT32 ,
SS_INT32 , SS_INT32 , SS_INT32 , SS_INT32 , SS_INT32 } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "TapDelayBuff" , "TapDelayBuff" , "Sums" ,
"StatesBuff" , "OutBuff" , "ContextBuffer" , "DSTATE" ,
"flippedPolyphaseCoeff" , "PhaseIdx" , "CoeffIdx" , "TapDelayIndex" ,
"OutIdx" , "polyphaseSelector" , "grainSize" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"SimulinkOQPSK/OQPSK\nModulator\nBaseband/Pulse shaping/FIR/Pulse shaping" ,
"SimulinkOQPSK/Raised Cosine\nTransmit Filter/FIR\nInterpolation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/OQPSK\nModulator\nBaseband/Delay" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" ,
"SimulinkOQPSK/Raised Cosine\nReceive Filter/FIR\nDecimation" } ; static
const char_T * rt_LoggedStateNames [ ] = { "TapDelayBuff" , "TapDelayBuff" ,
"Sums" , "StatesBuff" , "OutBuff" , "ContextBuffer" , "DSTATE" ,
"flippedPolyphaseCoeff" , "PhaseIdx" , "CoeffIdx" , "TapDelayIndex" ,
"OutIdx" , "polyphaseSelector" , "grainSize" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { {
0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0
} , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32
, SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0
} , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 2 , 3 , 22 , 4 , 23 , 5 , 8 , 24 , 25 , 6 , 7 ,
9 , 26 , 27 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 14 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 14 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtDW . pt5eromfcj ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) rtDW . gbyowhygxr ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtDW . kviwuzsm51 ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) rtDW . jhjvzmws0f ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtDW . jkwcjrsbfz ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) rtDW . mpkdim1qis ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtDW . ate1uhb4qw ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) rtDW . hax1vszx2y ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtDW . mahx1vfrrk ;
rt_LoggedStateSignalPtrs [ 9 ] = ( void * ) & rtDW . b1k03uckiu ;
rt_LoggedStateSignalPtrs [ 10 ] = ( void * ) & rtDW . fextltf3bq ;
rt_LoggedStateSignalPtrs [ 11 ] = ( void * ) & rtDW . oj03j4ixuy ;
rt_LoggedStateSignalPtrs [ 12 ] = ( void * ) rtDW . j4tyz1d51k ;
rt_LoggedStateSignalPtrs [ 13 ] = ( void * ) & rtDW . kwhxs250ag ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetStepSize ( rtS , 6.25E-8 ) ; ssSetMinStepSize (
rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError (
rtS , 0 ) ; ssSetMaxStepSize ( rtS , 6.25E-8 ) ; ssSetSolverMaxOrder ( rtS ,
- 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL
) ) ; ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 ,
2471231377U ) ; ssSetChecksumVal ( rtS , 1 , 1996571106U ) ; ssSetChecksumVal
( rtS , 2 , 1402774140U ) ; ssSetChecksumVal ( rtS , 3 , 1784209955U ) ; {
static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static
RTWExtModeInfo rt_ExtModeInfo ; static const sysRanDType * systemRan [ 4 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_SimulinkOQPSK_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP
( rtS , mr_SimulinkOQPSK_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS ,
mr_SimulinkOQPSK_SetDWork ) ; rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if
( ssGetErrorStatus ( rtS ) ) { return rtS ; } executionInfo ->
simulationOptions_ . stateSaveName_ = rtliGetLogX ( ssGetRTWLogInfo ( rtS ) )
; executionInfo -> simulationOptions_ . finalStateName_ = rtliGetLogXFinal (
ssGetRTWLogInfo ( rtS ) ) ; executionInfo -> simulationOptions_ .
outputSaveName_ = rtliGetLogY ( ssGetRTWLogInfo ( rtS ) ) ; return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID4 ( tid ) ; }
