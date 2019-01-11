/*
 * EthSubsystem.cpp
 *
 *  Created on: 19 сент. 2018 г.
 *      Author: Ivan.Suslov
 */

#include <Hardware/system/nimu_cppi_qmss_iface.h>

#include "EthSubsystem.h"

namespace dsp
{

EthSubsystem::InitializeResult EthSubsystem::initialize()
{
	if (initializeQmss() != INITIALIZE_QMSS_SUCCESS) {
		return INITIALIZE_FAIL;
	}

	if (initializeCppi() != INITIALIZE_CPPI_SUCCESS) {
		return INITIALIZE_FAIL;
	}

	if (initializePacketAccelerator() != INITIALIZE_PA_SUCCESS) {
		return INITIALIZE_FAIL;
	}

	return INITIALIZE_SUCCESS;
}

EthSubsystem::InitializeQmssResult EthSubsystem::initializeQmss()
{
	NIMU_QMSS_CFG_T qmss_cfg;

	qmss_cfg.master_core	= 1;
	qmss_cfg.max_num_desc	= MAX_NUM_DESC;
	qmss_cfg.desc_size		= MAX_DESC_SIZE;
	qmss_cfg.mem_region		= Qmss_MemRegion_MEMORY_REGION0;

	if (NIMU_initQmss(&qmss_cfg) != 0) {
		return INITIALIZE_QMSS_FAIL;
	}

	return INITIALIZE_QMSS_SUCCESS;
}

EthSubsystem::InitializeCppiResult EthSubsystem::initializeCppi()
{
	NIMU_CPPI_CFG_T cppi_cfg;

	cppi_cfg.master_core		= 1;
	cppi_cfg.dma_num			= Cppi_CpDma_PASS_CPDMA;
	cppi_cfg.num_tx_queues		= NUM_PA_TX_QUEUES;
	cppi_cfg.num_rx_channels	= NUM_PA_RX_CHANNELS;

	if (NIMU_initCppi(&cppi_cfg) != 0) {
		return INITIALIZE_CPPI_FAIL;
	}

	return INITIALIZE_CPPI_SUCCESS;
}

EthSubsystem::InitializePaResult EthSubsystem::initializePacketAccelerator()
{
	if (NIMU_initPass() != 0) {
		return INITIALIZE_PA_FAIL;
	}

	return INITIALIZE_PA_SUCCESS;
}

} // namespace dsp

