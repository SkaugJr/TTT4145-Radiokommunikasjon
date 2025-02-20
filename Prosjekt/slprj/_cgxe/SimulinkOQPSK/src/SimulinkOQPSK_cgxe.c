/* Include files */

#include "SimulinkOQPSK_cgxe.h"
#include "m_hGzJoyBXd4womJwUu82PQG.h"
#include "m_zTViAQ1klSrWSv6K0WhyYG.h"
#include "m_GAdgY9KUhCyNS3WcZY0JdF.h"

unsigned int cgxe_SimulinkOQPSK_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 874034690 &&
      ssGetChecksum1(S) == 1579238725 &&
      ssGetChecksum2(S) == 2072822391 &&
      ssGetChecksum3(S) == 2874639450) {
    method_dispatcher_hGzJoyBXd4womJwUu82PQG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 2434526296 &&
      ssGetChecksum1(S) == 1844100097 &&
      ssGetChecksum2(S) == 2107774427 &&
      ssGetChecksum3(S) == 1926308148) {
    method_dispatcher_zTViAQ1klSrWSv6K0WhyYG(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 4051132408 &&
      ssGetChecksum1(S) == 1220797965 &&
      ssGetChecksum2(S) == 2236733388 &&
      ssGetChecksum3(S) == 987937922) {
    method_dispatcher_GAdgY9KUhCyNS3WcZY0JdF(S, method, data);
    return 1;
  }

  return 0;
}
