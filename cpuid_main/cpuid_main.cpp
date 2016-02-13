#include "..\cpuid.h"

/* Author: jrmwng @ 2016 */

#include <fstream>
#include <Windows.h>

int main()
{
	// execution CPUID instructions

	jrmwng::cpuid_forest_t CPUID;

	// print CPUID data

	std::cout << CPUID;

	// output CPUID data to the file "cpuid.txt"

	std::ofstream ofs("cpuid.txt");
	{
		ofs << CPUID;
		ofs.close();
	}

	// zero data structures

	memset(&CPUID, 0, sizeof(CPUID));

	// input CPUID data from the file "cpuid.txt"

	std::ifstream ifs("cpuid.txt");
	{
		ifs >> CPUID;
		ifs.close();
	}

	// print features

	if (CPUID.uFPU)
		std::cout << "FPU is available" << std::endl;
	if (CPUID.uMMX)
		std::cout << "MMX is available" << std::endl;

	if (CPUID.uSSE && CPUID.uSSE2 && CPUID.uSSE3 && CPUID.uSSSE3 && CPUID.uSSE4_1 && CPUID.uSSE4_2)
		std::cout << "SSE is available (all)" << std::endl;
	else if (CPUID.uSSE || CPUID.uSSE2 || CPUID.uSSE3 || CPUID.uSSSE3 || CPUID.uSSE4_1 || CPUID.uSSE4_2)
		std::cout << "SSE is available (some)" << std::endl;

	if (CPUID.uAVX && CPUID.uAVX2)
		std::cout << "AVX is available (all)" << std::endl;
	else if (CPUID.uAVX || CPUID.uAVX2)
		std::cout << "AVX is available (some)" << std::endl;

	if (CPUID.uBMI1 && CPUID.uBMI2)
		std::cout << "BMI is available (all)" << std::endl;
	else if (CPUID.uBMI1 || CPUID.uBMI2)
		std::cout << "BMI is available (some)" << std::endl;

	if (CPUID.uHLE)
		std::cout << "HLE is available" << std::endl;
	if (CPUID.uRTM)
		std::cout << "RTM is available" << std::endl;

	if (CPUID.uIntelMPX)
		std::cout << "Intel MPX is available" << std::endl;

	if (CPUID.uIntelSGX)
		std::cout << "Intel SGX is available" << std::endl;

	// print strings

	std::cout << CPUID.vendor_identification_string().m128i_i8 << std::endl;
	std::cout << CPUID.soc_vendor_brand_string() << std::endl;
	std::cout << CPUID.processor_brand_string() << std::endl;

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