# cpuid
CPUID in C++ template, supporting output and input of cpuid data in human friendly text format

## C++ header file

\#include "[cpuid.h](https://github.com/jrmwng/cpuid/blob/master/cpuid.h)"

## How to output the CPUID trees?

      jrmwng::cpuid_tree_t<0x17> CPUID;
      jrmwng::cpuid_tree_t<0x80000008> ExtendedCPUID;
      
      std::cout << CPUID << ExtendedCPUID;

### Sample Output (trees)

           0   0       16 756e6547 6c65746e 49656e69 GenuineIntel
           1   0    406e3  3100800 7ffafbff bfebfbff +SSE3 +PCLMULQDQ +MONITOR +VMX +SMX +EIST +TM2 +SSSE3 +FMA +CMPXCHG16B +PDCM +SSE4.1 +SSE4.2 +x2APIC +MOVBE +POPCNT +TSC-Deadline +AES +XSAVE +OSXSAVE +AVX +F16C +RDRAND +FPU +VME +DE +PSE +TSC +MSR +PAE +MCE +CX8 +APIC +SEP +MTRR +PGE +MCA +CMOV +PAT +PSE36 -PSN +CLFSH +DS +ACPI +MMX +FXSR +SSE +SSE2 +SS +HTT +TM +PBE
           2   0 76036301   f0b5ff        0   c30000
           3   0        0        0        0        0
           4   0 1c004121  1c0003f       3f        0 D-Cache L1  2processor(s) 8core(s)  8way(s) * 1partition(s) * 64B *   64set(s)
           4   1 1c004122  1c0003f       3f        0 I-Cache L1  2processor(s) 8core(s)  8way(s) * 1partition(s) * 64B *   64set(s)
           4   2 1c004143   c0003f      3ff        0 U-Cache L2  2processor(s) 8core(s)  4way(s) * 1partition(s) * 64B * 1024set(s)
           4   3 1c03c163  2c0003f      fff        6 U-Cache L3 16processor(s) 8core(s) 12way(s) * 1partition(s) * 64B * 4096set(s)
           5   0       40       40        3 11142120 [64B,64B] +MWAIT +InterruptsAsBreakEvent C0/0 C1/2 C2/1 C3/2 C4/4 C5/1 C6/1 C7/1
           6   0     27f7        2        9        0 +ThermalSensor +TurboBoost +ARAT +PLN +ECMD +PTM +HWP +HDC +SETBH
           7   0        0  29c6fbf        0        0 +FSGSBASE +SGX +BMI1 +HLE +AVX2 +SMEP +BMI2 +Fast-String +INVPCID +RTM -PQM +MPX -PQE -AVX512F -AVX512DQ +RDSEED +ADX +SMAP -AVX512IFMA -PCOMMIT +CLFLUSHOPT -CLWB +PT -AVX512PF -AVX512ER -AVX512CD -SHA -AVX512BW -AVX512VL -PREFTEHCHWT1 -AVX512VBMI -PKU -OSPKE
           8   0        0        0        0        0
           9   0        0        0        0        0
           a   0  7300404        0        0      603 4*48b 3*48b
           b   0        1        2      100        3      SMT x2APIC-ID=3 Topology-ID=1 Logical-Processor=2
           b   1        4        4      201        3     Core x2APIC-ID=3 Topology-ID=0 Logical-Processor=4
           c   0        0        0        0        0
           d   0       1f      440      440        0 +x87 +SSE +AVX +BNDREGS +BNDCSR -PT -PKRU 1088B 1088B
           d   1        f      3c0      100        0 +XSAVEOPT +Compaction-Extensions +XGETBV +XSAVES-IA32_XSS 960B
           d   2      100      240        0        0 AVX      256B @  576B
           d   3       40      3c0        0        0 BNGREG    64B @  960B
           d   4       40      400        0        0 BNGCSR    64B @ 1024B
           e   0        0        0        0        0
           f   0        0        0        0        0
           f   1        0        0        0        0
           f   2        0        0        0        0
          10   0        0        0        0        0
          10   1        0        0        0        0
          11   0        0        0        0        0
          12   0        0        0        0        0 -SGX1 -SGX2
          13   0        0        0        0        0
          14   0        1        f        7        0
          14   1  2490002   3f3fff        0        0
          15   0        2       d0        0        0 208/2
          16   0      9c4      bb8       64        0 2500MHz 3000MHz 100MHz
    80000000   0 80000008        0        0        0
    80000001   0        0        0      121 2c100000 +LZCNT +PREFTEHCHW +1GBytePages +RDTSCP +x64
    80000002   0 65746e49 2952286c 726f4320 4d542865 Intel(R) Core(TM
    80000003   0 35692029 3033362d 43205530 40205550 ) i5-6300U CPU @
    80000004   0 342e3220 7a484730        0        0  2.40GHz
    80000005   0        0        0        0        0
    80000006   0        0        0  1006040        0 64B 8-way 256KB
    80000007   0        0        0        0      100 +InvariantTSC
    80000008   0     3027        0        0        0 39b 48b

## How to output a CPUID leaf?

      jrmwng::cpuid_leaf_t<0x04> CPUID04;
      
      std::cout << CPUID04;

### Sample Output (leaf 0x04)

     4   0      121  1c0003f       3f        0 D-Cache L1  1processor(s) 1core(s)  8way(s) * 1partition(s) * 64B *   64set(s) 
     4   1      122  1c0003f       3f        0 I-Cache L1  1processor(s) 1core(s)  8way(s) * 1partition(s) * 64B *   64set(s) 
     4   2      143  1c0003f      1ff        0 U-Cache L2  1processor(s) 1core(s)  8way(s) * 1partition(s) * 64B *  512set(s) 
     4   3      163  4c0003f     3fff        2 U-Cache L3  1processor(s) 1core(s) 20way(s) * 1partition(s) * 64B * 16384set(s) 

## How to save CPUID data to a file?

      jrmwng::cpuid_tree_t<0x17> CPUID;
      jrmwng::cpuid_tree_t<0x80000008> ExtendedCPUID;
      
      std::ofstream ofs("cpuid.txt");
      ofs << CPUID << ExtendedCPUID;

## How to load CPUID data from a file?

      jrmwng::cpuid_tree_t<0x17> CPUID;
      jrmwng::cpuid_tree_t<0x80000008> ExtendedCPUID;
      
      std::ifstream ifs("cpuid.txt");
      ifs >> CPUID >> ExtendedCPUID;

## How to check features?

      jrmwng::cpuid_tree_t<0x17> CPUID;
      
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
      	
      if (CPUID.uHLE && CPUID.uRTM)
      	std::cout << "Intel TSX is available (all)" << std::endl;
      else if (CPUID.uHLE || CPUID.uRTM)
      	std::cout << "Intel TSX is available (some)" << std::endl;
      
      if (CPUID.uIntelMPX)
      	std::cout << "Intel MPX is available" << std::endl;
      
      if (CPUID.uIntelSGX)
      	std::cout << "Intel SGX is available" << std::endl;
