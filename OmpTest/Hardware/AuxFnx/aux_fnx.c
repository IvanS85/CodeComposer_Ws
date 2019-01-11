/*
 * AuxFnx.c
 *
 *  Created on: 9 џэт. 2017 у.
 *      Author: Ivan.Suslov
 */

#include "aux_fnx.h"

/** ============================================================================
 *   @n@b UTILS_convertCoreLocal2GlobalAddr
 *
 *   @b Description
 *   @n This API converts a core local L2 address to a global L2 address.
 *
 *   @param[in]
 *   @n addr            L2 address to be converted to global.
 *
 *   @return    uint32_t
 *   @n >0              Global L2 address
 * =============================================================================
 */
uint32_t AuxFnx_convertCoreLocal2GlobalAddr(uint32_t addr)
{
	/* Get the core number. */
	uint32_t coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);

	/* Check if the address is a valid Local L2 address to convert */
	if ((addr >= (uint32_t) 0x800000) && (addr < (uint32_t) 0x900000))
	{
		/* Compute the global address. */
		return ((1 << 28) | (coreNum << 24) | (addr & 0x00ffffff));
	}
	else
	{
		return (addr);
	}
}

/** ============================================================================
 *   @n@b setDomainAndModulePower
 *
 *   @b Description
 *   @n This function sets the power for a module and a domain at the same time
 *      like it is recommended in the PSC user guide
 *
 *   @b Arguments
 *   @verbatim
 module          LPSC Module for which the power is being set
 domain          Power Domain for which the power is being set
 state           Next state to which the module and domain will be transitioned.
 @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Module is and domain are moved to the state described by the state parameter
 *
 *   @b  Example
 *   @verbatim
 ...
 // Disable the SRIO's module and power domain
 setDomainAndModulePower(CSL_PSC_LPSC_SRIO, CSL_PSC_PD_SRIO, 0);
 ...
 @endverbatim
 * ============================================================================
 */
void AuxFnx_setDomainAndModulePower(uint32_t module, uint32_t domain, uint32_t state)
{
	while (!CSL_PSC_isStateTransitionDone(domain))
		;

	if (state)
	{
		CSL_PSC_enablePowerDomain(domain);
		CSL_PSC_setModuleNextState(module, PSC_MODSTATE_ENABLE);
	}
	else
	{
		CSL_PSC_disablePowerDomain(domain);
		CSL_PSC_setModuleNextState(module, PSC_MODSTATE_SWRSTDISABLE);
	}

	CSL_PSC_startStateTransition(domain);

	while (!CSL_PSC_isStateTransitionDone(domain))
		;

	return;
}

/** ============================================================================
 *   @n@b setModulePower
 *
 *   @b Description
 *   @n This function sets the power for a module
 *
 *   @b Arguments
 *   @verbatim
 module          Module for which the power is being set
 domain          Domain for which the power is being set
 state           Next state to which the module will be transitioned.
 @endverbatim
 *
 *   <b> Return Value </b>  None
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n  Module is moved to the state described by the state parameter
 *
 *   @b  Example
 *   @verbatim
 ...
 // Disable the SRIO's power module
 setModulePower(CSL_PSC_LPSC_SRIO, 0);
 ...
 @endverbatim
 * ============================================================================
 */
void AuxFnx_setModulePower(uint32_t module, uint32_t domain, uint32_t state)
{
	while (!CSL_PSC_isStateTransitionDone(domain))
		;

	if (state)
		CSL_PSC_setModuleNextState(module, PSC_MODSTATE_ENABLE);
	else
		CSL_PSC_setModuleNextState(module, PSC_MODSTATE_SWRSTDISABLE);

	CSL_PSC_startStateTransition(domain);

	while (!CSL_PSC_isStateTransitionDone(domain))
		;

	return;
}
