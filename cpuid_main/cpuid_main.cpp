#include "..\cpuid.h"

/* Author: jrmwng @ 2016 */

#include <fstream>

int main()
{
	// execution CPUID instructions
	jrmwng::cpuid_tree_t<0x17> CPUID;
	jrmwng::cpuid_tree_t<0x80000008> ExtendedCPUID;

	// output CPUID data to the file "cpuid.txt"
	std::ofstream ofs("cpuid.txt");
	{
		ofs << CPUID << ExtendedCPUID;
		ofs.close();
	}

	// zero data structures
	memset(&CPUID, 0, sizeof(CPUID));
	memset(&ExtendedCPUID, 0, sizeof(ExtendedCPUID));

	// input CPUID data from the file "cpuid.txt"
	std::ifstream ifs("cpuid.txt");
	{
		ifs >> CPUID >> ExtendedCPUID;
		ifs.close();
	}

	// print CPUID data
	std::cout << CPUID << ExtendedCPUID;
	return 0;
}