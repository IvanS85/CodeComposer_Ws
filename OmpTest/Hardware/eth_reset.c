/*
 * Eth_reset.c
 *
 *  Created on: 9 џэт. 2017 у.
 *      Author: Ivan.Suslov
 */

// System include (for functions like System_printf)
#include <xdc/runtime/System.h>

// Chip Support Library includes
#include <ti/csl/tistdtypes.h>          // type definitions
#include <ti/csl/csl_chipAux.h>         // Auxiliary chip functions (like CSL_chipReadDNUM);

// Include Auxiliary Functions
#include "AuxFnx/aux_fnx.h"

/* Addresses used to disable the PASS PDSP's */
#define PASS_PDSP0  0x02001000
#define PASS_PDSP1  0x02001100
#define PASS_PDSP2  0x02001200
#define PASS_PDSP3  0x02001300
#define PASS_PDSP4  0x02001400
#define PASS_PDSP5  0x02001500

 /*
 *  Resets ethernet subsystem so we can successfully reinitialize it in CCS debugger again
 */
void Eth_reset(void)
{
    /* Disabling PA PDSP to prepare for power down */
    volatile uint32_t *passPDSP;
    passPDSP = (uint32_t*)PASS_PDSP0;
    *passPDSP &= 0xFFFFFFFD;

    passPDSP = (uint32_t*)PASS_PDSP1;
    *passPDSP &= 0xFFFFFFFD;

    passPDSP = (uint32_t*)PASS_PDSP2;
    *passPDSP &= 0xFFFFFFFD;

    passPDSP = (uint32_t*)PASS_PDSP3;
    *passPDSP &= 0xFFFFFFFD;

    passPDSP = (uint32_t*)PASS_PDSP4;
    *passPDSP &= 0xFFFFFFFD;

    passPDSP = (uint32_t*)PASS_PDSP5;
    *passPDSP &= 0xFFFFFFFD;

    /* Turning off the NetCP modules and domain */
    AuxFnx_setModulePower(CSL_PSC_LPSC_CPGMAC, CSL_PSC_PD_PASS, 0);
    AuxFnx_setModulePower(CSL_PSC_LPSC_Crypto, CSL_PSC_PD_PASS, 0);
    AuxFnx_setDomainAndModulePower(CSL_PSC_LPSC_PKTPROC, CSL_PSC_PD_PASS, 0);
}
