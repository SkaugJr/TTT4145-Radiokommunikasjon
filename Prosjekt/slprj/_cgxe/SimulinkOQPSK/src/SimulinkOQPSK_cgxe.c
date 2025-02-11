/* Include files */

#include "SimulinkOQPSK_cgxe.h"
#include "m_vyk94dRgB2zcdSb8CoDOo.h"
#include "m_zrIE4lRjxJ68ofdsvR86sF.h"
#include "m_IsGNysfWLj549u5AgrrhmC.h"

unsigned int cgxe_SimulinkOQPSK_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 1755053347 &&
      ssGetChecksum1(S) == 4023396241 &&
      ssGetChecksum2(S) == 3780827915 &&
      ssGetChecksum3(S) == 4045880910) {
    method_dispatcher_vyk94dRgB2zcdSb8CoDOo(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2254596246 &&
      ssGetChecksum1(S) == 1793280048 &&
      ssGetChecksum2(S) == 269458341 &&
      ssGetChecksum3(S) == 2822816266) {
    method_dispatcher_zrIE4lRjxJ68ofdsvR86sF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 3460108888 &&
      ssGetChecksum1(S) == 2375910034 &&
      ssGetChecksum2(S) == 1235347780 &&
      ssGetChecksum3(S) == 1318528273) {
    method_dispatcher_IsGNysfWLj549u5AgrrhmC(S, method, data);
    return 1;
  }

  return 0;
}
