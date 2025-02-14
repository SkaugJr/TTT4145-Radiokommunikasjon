/* Include files */

#include "SimulinkOQPSK_cgxe.h"
#include "m_hdVr3Ti4tWZVZUU2cDk3EB.h"
#include "m_L4FxDF8PMmLMazYl7DbTvE.h"
#include "m_CS6TL6Ke4rnG7CriLonEOH.h"

unsigned int cgxe_SimulinkOQPSK_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 1227034482 &&
      ssGetChecksum1(S) == 4238852051 &&
      ssGetChecksum2(S) == 589117839 &&
      ssGetChecksum3(S) == 3153846685) {
    method_dispatcher_hdVr3Ti4tWZVZUU2cDk3EB(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1403014131 &&
      ssGetChecksum1(S) == 4200001972 &&
      ssGetChecksum2(S) == 3695138185 &&
      ssGetChecksum3(S) == 2136565080) {
    method_dispatcher_L4FxDF8PMmLMazYl7DbTvE(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3935939526 &&
      ssGetChecksum1(S) == 4085165387 &&
      ssGetChecksum2(S) == 1017655517 &&
      ssGetChecksum3(S) == 3076557423) {
    method_dispatcher_CS6TL6Ke4rnG7CriLonEOH(S, method, data);
    return 1;
  }

  return 0;
}
