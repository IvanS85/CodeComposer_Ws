/*
 * Hardware.c
 *
 *  Created on: 6 џэт. 2017 у.
 *      Author: IvanS
 */

/*
 *  INCLUDE FILES
 */

/* Platform utilities include */
#include <ti/platform/platform.h>
#include <ti/platform/resource_mgr.h>

// System include (for functions like System_printf)
#include <xdc/runtime/System.h>

// Chip Support Library includes
#include <ti/csl/tistdtypes.h>          // type definitions
#include <ti/csl/csl_chipAux.h>         // Auxiliary chip functions (like CSL_chipReadDNUM);

#define USE_IBL     0

#define TEST_LOG System_printf

/* Platform Information - we will read it form the Platform Library */
platform_info  gPlatformInfo;

/*
 *  FUNCTION PROTOTYPES
 */
void EVM_init(void);

// from ../Eth/Eth_reset.c
extern void Eth_reset(void);


/*
 * Does hardware initialization of the platform.
 */
int Hardware_init(void)
{
    // do hardware initialization only by Core0
    if(CSL_chipReadDNUM() == 0)
    {
        // reset ethernet subsystem. !!! PERHAPS NOT WORKING AS INTENDED !!! LOOK AT IT LATER!
        Eth_reset();

        // initialize hardware platform (C6678EVM).
        EVM_init();
    }

    return 0;
}

/*************************************************************************
 *  @b EVM_init()
 *
 *  @n
 *
 *  Initializes the platform hardware. This routine is configured to start in
 *  the evm.cfg configuration file. It is the first routine that BIOS
 *  calls and is executed before Main is called. If you are debugging within
 *  CCS the default option in your target configuration file may be to execute
 *  all code up until Main as the image loads. To debug this you should disable
 *  that option.
 *
 *  @param[in]  None
 *
 *  @retval
 *      None
 ************************************************************************/
void EVM_init(void)
{
    platform_init_flags     sFlags;
    platform_init_config    sConfig;
    /* Status of the call to initialize the platform */
    int32_t pform_status;

    /*
     * You can choose what to initialize on the platform by setting the following
     * flags. Things like the DDR, PLL, etc should have been set by the boot loader.
    */
    memset( (void *) &sFlags,  0, sizeof(platform_init_flags));
    memset( (void *) &sConfig, 0, sizeof(platform_init_config));

#if USE_IBL == 0
    sFlags.pll  = 1;    /* PLLs for clocking    */ // PLL must be initialized in Intermediate Bootloader.
    sFlags.ddr  = 1;    /* External memory      */ // DDR must be initialized before program is loaded from flash memory.
#else
    sFlags.pll  = 0;
    sFlags.ddr  = 0;
#endif /*USE_IBL*/

    sFlags.tcsl = 1;    /* Time stamp counter   */
    sFlags.phy  = 1;    /* Ethernet             */
    sFlags.ecc  = 1;    /* Memory ECC           */

    sConfig.pllm = 0;   /* Use libraries default clock divisor */
    sConfig.plld = 0;

    pform_status = platform_init(&sFlags, &sConfig);

    /* If we initialized the platform okay */
    if (pform_status != Platform_EOK) {
        /* Initialization of the platform failed... die */
        while (1)
        {
        }
    }
}

/*
 * Callback function which is called by Clock module set in .cfg file
 */
void    Hardware_ledClk(void)
{
#if USE_IBL == 0
	static uint32_t         led_id      = 0;
	static uint32_t         led_idxes[] = { 0, 1, 2, 3 };

	platform_led(led_idxes[led_id], PLATFORM_LED_OFF, PLATFORM_USER_LED_CLASS);

	led_id = (led_id + 1) % (sizeof(led_idxes) / sizeof(uint32_t));

	platform_led(led_idxes[led_id], PLATFORM_LED_ON, PLATFORM_USER_LED_CLASS);
#endif
}
