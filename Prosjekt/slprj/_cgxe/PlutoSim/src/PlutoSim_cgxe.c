/* Include files */

#include "PlutoSim_cgxe.h"
#include "m_R5Ox6ru1oFKJKsnxRNrApB.h"

unsigned int cgxe_PlutoSim_method_dispatcher(SimStruct* S, int_T method, void
  * data)
{
  if (ssGetChecksum0(S) == 1953789014 &&
      ssGetChecksum1(S) == 3045781490 &&
      ssGetChecksum2(S) == 2100246846 &&
      ssGetChecksum3(S) == 3070547107) {
    method_dispatcher_R5Ox6ru1oFKJKsnxRNrApB(S, method, data);
    return 1;
  }

  return 0;
}
