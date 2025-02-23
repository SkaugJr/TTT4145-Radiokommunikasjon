/* Include files */

#include "SimulinkOQPSK_cgxe.h"
#include "m_lLkCrnFHJH3iMfHCaPYASC.h"
#include "m_gGTZD1AOI6gyn0Qm1fcnkF.h"
#include "m_osgJocTdXxihgGCnbkhkmC.h"

unsigned int cgxe_SimulinkOQPSK_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 1670019031 &&
      ssGetChecksum1(S) == 623842692 &&
      ssGetChecksum2(S) == 4141698355 &&
      ssGetChecksum3(S) == 810426357) {
    method_dispatcher_lLkCrnFHJH3iMfHCaPYASC(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2754105863 &&
      ssGetChecksum1(S) == 2525495159 &&
      ssGetChecksum2(S) == 1194542851 &&
      ssGetChecksum3(S) == 85972626) {
    method_dispatcher_gGTZD1AOI6gyn0Qm1fcnkF(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 4046159009 &&
      ssGetChecksum1(S) == 2329415202 &&
      ssGetChecksum2(S) == 3303204907 &&
      ssGetChecksum3(S) == 3047691079) {
    method_dispatcher_osgJocTdXxihgGCnbkhkmC(S, method, data);
    return 1;
  }

  return 0;
}
