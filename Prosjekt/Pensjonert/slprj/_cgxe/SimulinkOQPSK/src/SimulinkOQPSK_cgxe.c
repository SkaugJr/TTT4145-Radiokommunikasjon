/* Include files */

#include "SimulinkOQPSK_cgxe.h"
#include "m_J5U9gPuT2CQnwmU8Ez0v3C.h"
#include "m_lamyqSSSqadK9mN04KqnJD.h"
#include "m_9IHy330kmTdgLxpFbUGEK.h"

unsigned int cgxe_SimulinkOQPSK_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 1966919731 &&
      ssGetChecksum1(S) == 1058901174 &&
      ssGetChecksum2(S) == 1900572815 &&
      ssGetChecksum3(S) == 512038229) {
    method_dispatcher_J5U9gPuT2CQnwmU8Ez0v3C(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3124014839 &&
      ssGetChecksum1(S) == 3802580223 &&
      ssGetChecksum2(S) == 707536183 &&
      ssGetChecksum3(S) == 1167038927) {
    method_dispatcher_lamyqSSSqadK9mN04KqnJD(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3130969676 &&
      ssGetChecksum1(S) == 229233115 &&
      ssGetChecksum2(S) == 1685858504 &&
      ssGetChecksum3(S) == 4155375124) {
    method_dispatcher_9IHy330kmTdgLxpFbUGEK(S, method, data);
    return 1;
  }

  return 0;
}
