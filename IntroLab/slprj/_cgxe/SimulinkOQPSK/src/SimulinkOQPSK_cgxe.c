/* Include files */

#include "SimulinkOQPSK_cgxe.h"
#include "m_gGTZD1AOI6gyn0Qm1fcnkF.h"
#include "m_eC2Xob0X8jcaxCPPVjmL2C.h"
#include "m_pb35Ooc2hRKBKZ3sq0fzFC.h"

unsigned int cgxe_SimulinkOQPSK_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 2754105863 &&
      ssGetChecksum1(S) == 2525495159 &&
      ssGetChecksum2(S) == 1194542851 &&
      ssGetChecksum3(S) == 85972626) {
    method_dispatcher_gGTZD1AOI6gyn0Qm1fcnkF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3205486227 &&
      ssGetChecksum1(S) == 1560149294 &&
      ssGetChecksum2(S) == 3642794214 &&
      ssGetChecksum3(S) == 2949997041) {
    method_dispatcher_eC2Xob0X8jcaxCPPVjmL2C(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3955591081 &&
      ssGetChecksum1(S) == 2342232153 &&
      ssGetChecksum2(S) == 2946236679 &&
      ssGetChecksum3(S) == 775919646) {
    method_dispatcher_pb35Ooc2hRKBKZ3sq0fzFC(S, method, data);
    return 1;
  }

  return 0;
}
