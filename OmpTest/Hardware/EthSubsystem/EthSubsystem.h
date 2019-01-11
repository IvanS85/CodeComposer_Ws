/*
 * EthSubsystem.h
 *
 *  Created on: 19 сент. 2018 г.
 *      Author: Ivan.Suslov
 */

#ifndef NETWORK_ETHSUBSYSTEM_H_
#define NETWORK_ETHSUBSYSTEM_H_

#include <ostream>


namespace dsp
{

/// Конфигуратор .
class EthSubsystem
{
public:

	/// Результат инициализации сетевой подсистемы.
	enum InitializeResult
	{
		INITIALIZE_SUCCESS	= 0,	///< Инициализация прошла успешно.
		INITIALIZE_FAIL		= -1	///< Инициализация прошла неуспешно.
	};

	/// Настраивает сеть в соответствии с заданными настройками.
	static InitializeResult initialize();

private:

	/// Результат конфигурирования Qmss.
	enum InitializeQmssResult
	{
		INITIALIZE_QMSS_SUCCESS	= 0,		///< Инициализация прошла успешно.
		INITIALIZE_QMSS_FAIL	= -1		///< Инициализация прошла неуспешно.
	};

	/// Результат конфигурирования Cppi.
	enum InitializeCppiResult
	{
		INITIALIZE_CPPI_SUCCESS	= 0,		///< Инициализация прошла успешно.
		INITIALIZE_CPPI_FAIL	= -1		///< Инициализация прошла неуспешно.
	};

	/// Результат конфигурирования Packet Accelerator.
	enum InitializePaResult
	{
		INITIALIZE_PA_SUCCESS	= 0,		///< Инициализация прошла успешно.
		INITIALIZE_PA_FAIL		= -1		///< Инициализация прошла неуспешно.
	};

	// TODO: вынести QMSS в отдельную сущность.
	/// Инициализирует подсистему управления очередями (QMSS).
	/// @return Результат конфигурации.
	static InitializeQmssResult initializeQmss();

	// TODO: вынести CPPI в отдельную сущность.
	/// Инициализирует общий интерфейс программирования периферии (CPPI).
	/// @return Результат конфигурации.
	static InitializeCppiResult initializeCppi();

	// TODO: вынести PacketAccelerator в отдельную сущность.
	/// Инициализирует акселератор пакетов (PA).
	/// @return Результат инициализации.
	static InitializePaResult initializePacketAccelerator();
};

}


#endif /* NETWORK_ETHSUBSYSTEM_H_ */
