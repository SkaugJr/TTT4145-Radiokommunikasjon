#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , {
"struct_D6rIHr2ktZHsXsotAX4nfG" , 17 , 64 } , {
"struct_6vjZE1zVXiMs9MoZnA9ZPB" , 18 , 136 } , {
"struct_v741RdvTmtoZuYoQa1tUcH" , 19 , 368 } , {
"struct_y6ASV87Q7ob9ID8o92onZB" , 20 , 352 } , { "gezsn1ijeo" , 21 , 96 } , {
"d005fqujeu" , 22 , 16 } , { "ob3ra4tldg" , 23 , 8 } , { "uint64_T" , 24 , 8
} , { "int64_T" , 25 , 8 } , { "uint_T" , 26 , 32 } , { "char_T" , 27 , 8 } ,
{ "uchar_T" , 28 , 8 } , { "time_T" , 29 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( int32_T ) , sizeof ( int32_T ) , sizeof ( int32_T ) ,
sizeof ( int32_T ) , sizeof ( gezsn1ijeo ) , sizeof ( d005fqujeu ) , sizeof (
ob3ra4tldg ) , sizeof ( uint64_T ) , sizeof ( int64_T ) , sizeof ( uint_T ) ,
sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof ( time_T ) } ; static const
char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T"
, "int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" ,
"fcn_call_T" , "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"physical_connection" , "int64_T" , "uint64_T" ,
"struct_D6rIHr2ktZHsXsotAX4nfG" , "struct_6vjZE1zVXiMs9MoZnA9ZPB" ,
"struct_v741RdvTmtoZuYoQa1tUcH" , "struct_y6ASV87Q7ob9ID8o92onZB" ,
"gezsn1ijeo" , "d005fqujeu" , "ob3ra4tldg" , "uint64_T" , "int64_T" ,
"uint_T" , "char_T" , "uchar_T" , "time_T" } ; static DataTypeTransition
rtBTransitions [ ] = { { ( char_T * ) ( & rtB . moprdribiz . re ) , 0 , 1 , 4
} , { ( char_T * ) ( & rtB . i5ilelgt54 ) , 0 , 0 , 1 } , { ( char_T * ) ( &
rtDW . kiqazyiq00 ) , 21 , 0 , 1 } , { ( char_T * ) ( & rtDW . j33qtkq40m ) ,
22 , 0 , 1 } , { ( char_T * ) ( & rtDW . pt5eromfcj . re ) , 0 , 1 , 250 } ,
{ ( char_T * ) ( & rtDW . ate1uhb4qw ) , 0 , 0 , 41 } , { ( char_T * ) ( &
rtDW . ikfemt5lt2 [ 0 ] . re ) , 0 , 1 , 48 } , { ( char_T * ) ( & rtDW .
fkshk3as53 [ 0 ] ) , 0 , 0 , 260 } , { ( char_T * ) ( & rtDW . lpy5mzzed1 ) ,
23 , 0 , 1 } , { ( char_T * ) ( & rtDW . i1upjkvbfd ) , 11 , 0 , 1 } , { (
char_T * ) ( & rtDW . mahx1vfrrk ) , 6 , 0 , 16 } , { ( char_T * ) ( & rtDW .
cxw1tnf414 ) , 7 , 0 , 1263 } , { ( char_T * ) ( & rtDW . miuqblj25w ) , 3 ,
0 , 1 } , { ( char_T * ) ( & rtDW . bx2b103j3q ) , 8 , 0 , 17 } } ; static
DataTypeTransitionTable rtBTransTable = { 14U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
AWGNChannel_EbNo ) , 0 , 0 , 98 } , { ( char_T * ) ( & rtP . Gain1_Gain ) , 6
, 0 , 2 } , { ( char_T * ) ( & rtP . ShiftArithmetic_DiagnosticForOORShift )
, 3 , 0 , 1 } } ; static DataTypeTransitionTable rtPTransTable = { 3U ,
rtPTransitions } ;
