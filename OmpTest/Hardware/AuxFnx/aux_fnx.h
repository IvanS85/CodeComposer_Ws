/*
 * AuxFnx.h
 *
 *  Created on: 9 џэт. 2017 у.
 *      Author: Ivan.Suslov
 */

#ifndef AUXFNX_AUX_FNX_H_
#define AUXFNX_AUX_FNX_H_

/*
 *  INCLUDE FILES
 */

// System include (for functions like System_printf)
#include <xdc/runtime/System.h>

// Chip Support Library includes
#include <ti/csl/tistdtypes.h>          // type definitions
#include <ti/csl/csl_chipAux.h>         // Auxiliary chip functions (like CSL_chipReadDNUM);

// CSL Power and Sleep Controller includes
#include <ti/csl/csl_psc.h>
#include <ti/csl/csl_pscAux.h>

/*
 *  FUNCTION PROTOTYPES
 */

// Converts a core local L2 address to a global L2 address.
uint32_t AuxFnx_convertCoreLocal2GlobalAddr(uint32_t addr);

// Sets the power for a module and a domain at the same time like it is recommended in the PSC user guide.
void AuxFnx_setDomainAndModulePower(uint32_t module, uint32_t domain, uint32_t state);
// Sets the power for a module.
void AuxFnx_setModulePower(uint32_t module, uint32_t domain, uint32_t state);

#endif /* AUXFNX_AUX_FNX_H_ */
