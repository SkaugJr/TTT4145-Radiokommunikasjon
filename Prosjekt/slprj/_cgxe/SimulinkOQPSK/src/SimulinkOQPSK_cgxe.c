/* Include files */

#include "SimulinkOQPSK_cgxe.h"
#include "m_ydbrxMPHi55Q7lYdpZ3ik.h"

unsigned int cgxe_SimulinkOQPSK_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 2450335090 &&
      ssGetChecksum1(S) == 2006579380 &&
      ssGetChecksum2(S) == 1904280578 &&
      ssGetChecksum3(S) == 1919855142) {
    method_dispatcher_ydbrxMPHi55Q7lYdpZ3ik(S, method, data);
    return 1;
  }

  return 0;
}
