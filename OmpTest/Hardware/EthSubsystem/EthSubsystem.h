/*
 * EthSubsystem.h
 *
 *  Created on: 19 ����. 2018 �.
 *      Author: Ivan.Suslov
 */

#ifndef NETWORK_ETHSUBSYSTEM_H_
#define NETWORK_ETHSUBSYSTEM_H_

#include <ostream>


namespace dsp
{

/// ������������ .
class EthSubsystem
{
public:

	/// ��������� ������������� ������� ����������.
	enum InitializeResult
	{
		INITIALIZE_SUCCESS	= 0,	///< ������������� ������ �������.
		INITIALIZE_FAIL		= -1	///< ������������� ������ ���������.
	};

	/// ����������� ���� � ������������ � ��������� �����������.
	static InitializeResult initialize();

private:

	/// ��������� ���������������� Qmss.
	enum InitializeQmssResult
	{
		INITIALIZE_QMSS_SUCCESS	= 0,		///< ������������� ������ �������.
		INITIALIZE_QMSS_FAIL	= -1		///< ������������� ������ ���������.
	};

	/// ��������� ���������������� Cppi.
	enum InitializeCppiResult
	{
		INITIALIZE_CPPI_SUCCESS	= 0,		///< ������������� ������ �������.
		INITIALIZE_CPPI_FAIL	= -1		///< ������������� ������ ���������.
	};

	/// ��������� ���������������� Packet Accelerator.
	enum InitializePaResult
	{
		INITIALIZE_PA_SUCCESS	= 0,		///< ������������� ������ �������.
		INITIALIZE_PA_FAIL		= -1		///< ������������� ������ ���������.
	};

	// TODO: ������� QMSS � ��������� ��������.
	/// �������������� ���������� ���������� ��������� (QMSS).
	/// @return ��������� ������������.
	static InitializeQmssResult initializeQmss();

	// TODO: ������� CPPI � ��������� ��������.
	/// �������������� ����� ��������� ���������������� ��������� (CPPI).
	/// @return ��������� ������������.
	static InitializeCppiResult initializeCppi();

	// TODO: ������� PacketAccelerator � ��������� ��������.
	/// �������������� ����������� ������� (PA).
	/// @return ��������� �������������.
	static InitializePaResult initializePacketAccelerator();
};

}


#endif /* NETWORK_ETHSUBSYSTEM_H_ */
