#include "..\cpuid.h"

/* Author: jrmwng @ 2016 */

#include <fstream>
#include <Windows.h>

int main()
{
	// execution stCPUID instructions

	jrmwng::cpuid_forest_t stCPUID;
	jrmwng::cpuid_standard_tree_t const & stStandardCPUID = stCPUID;

	// print stCPUID data

	std::cout << stCPUID;

	// output stCPUID data to the file "cpuid.txt"

	std::ofstream ofs("cpuid.txt");
	{
		ofs << stCPUID;
		ofs.close();
	}

	// zero data structures

	memset(&stCPUID, 0, sizeof(stCPUID));

	// input stCPUID data from the file "cpuid.txt"

	std::ifstream ifs("cpuid.txt");
	{
		ifs >> stCPUID;
		ifs.close();
	}

	// print features

	if (stStandardCPUID.uFPU)
		std::cout << "FPU is available" << std::endl;
	if (stCPUID.uMMX)
		std::cout << "MMX is available" << std::endl;

	if (stCPUID.uSSE && stCPUID.uSSE2 && stCPUID.uSSE3 && stCPUID.uSSSE3 && stCPUID.uSSE4_1 && stCPUID.uSSE4_2)
		std::cout << "SSE is available (all)" << std::endl;
	else if (stCPUID.uSSE || stCPUID.uSSE2 || stCPUID.uSSE3 || stCPUID.uSSSE3 || stCPUID.uSSE4_1 || stCPUID.uSSE4_2)
		std::cout << "SSE is available (some)" << std::endl;

	if (stCPUID.uAVX && stCPUID.uAVX2)
		std::cout << "AVX is available (all)" << std::endl;
	else if (stCPUID.uAVX || stCPUID.uAVX2)
		std::cout << "AVX is available (some)" << std::endl;

	if (stCPUID.uBMI1 && stCPUID.uBMI2)
		std::cout << "BMI is available (all)" << std::endl;
	else if (stCPUID.uBMI1 || stCPUID.uBMI2)
		std::cout << "BMI is available (some)" << std::endl;

	if (stCPUID.uHLE)
		std::cout << "HLE is available" << std::endl;
	if (stCPUID.uRTM)
		std::cout << "RTM is available" << std::endl;

	if (stCPUID.uIntelMPX)
		std::cout << "Intel MPX is available" << std::endl;

	if (stCPUID.uIntelSGX)
		std::cout << "Intel SGX is available" << std::endl;

	// print leaf 0x0B

	DWORD_PTR dwProcessAffinityMask = 0;
	DWORD_PTR dwSystemAffinityMask = 0;
	if (GetProcessAffinityMask(GetCurrentProcess(), &dwProcessAffinityMask, &dwSystemAffinityMask))
	{
		for (DWORD_PTR dwThreadAffinityMask = 1; dwThreadAffinityMask <= dwProcessAffinityMask; dwThreadAffinityMask <<= 1)
		{
			if (dwThreadAffinityMask & dwProcessAffinityMask)
			{
				dwThreadAffinityMask = SetThreadAffinityMask(GetCurrentThread(), dwThreadAffinityMask);
				{
					jrmwng::cpuid_leaf_t<0x01> CPUID01;
					jrmwng::cpuid_leaf_t<0x0B> CPUID0B;

					std::cout
						<< "Initial APIC-ID: " << CPUID01.uInitialAPIC_ID << std::endl
						<< CPUID0B << std::endl;
				}
				dwThreadAffinityMask = SetThreadAffinityMask(GetCurrentThread(), dwThreadAffinityMask);
			}
		}
	}

	return 0;
}