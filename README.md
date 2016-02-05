# cpuid
CPUID in C++ template, supporting output and input of cpuid data in human friendly text format

## The header file

[cpuid.h](https://github.com/jrmwng/cpuid/blob/master/cpuid.h)

## Sample output

               0   0        d 756e6547 6c65746e 49656e69 GenuineIntel
               1   0    306a9  6100800 7fbae3bf bfebfbff +SSE3 +PCLMULQDQ +MONITOR +VMX -SMX +EIST +TM2 +SSSE3 -FMA +CMPXCHG16B +PDCM +SSE4.1 +SSE4.2 +x2APIC -MOVBE +POPCNT +TSC-Deadline +AES +XSAVE +OSXSAVE +AVX +F16C +RDRAND +FPU +VME +DE +PSE +TSC +MSR +PAE +MCE +CX8 +APIC +SEP +MTRR +PGE +MCA +CMOV +PAT +PSE36 -PSN +CLFSH +DS +ACPI +MMX +FXSR +SSE +SSE2 +SS +HTT +TM +PBE 
               2   0 76035a01   f0b0ff        0   ca0000 
               3   0        0        0        0        0 
               4   0 1c004121  1c0003f       3f        0 D-Cache L1  2processors 8cores  8ways * 1partitions * 64B *   64sets 
               4   1 1c004122  1c0003f       3f        0 I-Cache L1  2processors 8cores  8ways * 1partitions * 64B *   64sets 
               4   2 1c004143  1c0003f      1ff        0 U-Cache L2  2processors 8cores  8ways * 1partitions * 64B *  512sets 
               4   3 1c03c163  2c0003f     1fff        6 U-Cache L3 16processors 8cores 12ways * 1partitions * 64B * 8192sets 
               5   0       40       40        3     1120 [64B,64B] +MWAIT +InterruptsAsBreakEvent C0/0 C1/2 C2/1 C3/1 C4/0 C5/0 C6/0 C7/0 
               6   0       77        2        9        0 +ThermalSensor +TurboBoost +ARAT +PLN +ECMD +PTM -HWP -HDC +SETBH 
               7   0        0      281        0        0 +FSGSBASE -SGX -BMI1 -HLE -AVX2 +SMEP -BMI2 +Fast-String -INVPCID -RTM -PQM -MPX -PQE -AVX512F -AVX512DQ -RDSEED -ADX -SMAP -AVX512IFMA -PCOMMIT -CLFLUSHOPT -CLWB -PT -AVX512PF -AVX512ER -AVX512CD -SHA -AVX512BW -AVX512VL -PREFTEHCHWT1 -AVX512VBMI -PKU -OSPKE 
               8   0        0        0        0        0 
               9   0        0        0        0        0 
               a   0  7300803        0        0      603 8*48b 3*48b 
               b   0        1        1      100        6 SMT 
               b   1        4        4      201        6 Core 
               c   0        0        0        0        0 
               d   0        7      340      340        0 +x87 +SSE +AVX -BNDREGS -BNDCSR -PT -PKRU 832B 832B 
               d   1        1        0        0        0 +XSAVEOPT -Compaction-Extensions -XGETBV -XSAVES-IA32_XSS 0B 
               d   2      100      240        0        0 AVX
        80000000   0 80000008        0        0        0 
        80000001   0        0        0        1 28100800 -LZCNT -PREFTEHCHW -1GBytePages +RDTSCP +x64 
        80000002   0 20202020 20202020 65746e49 2952286c         Intel(R)
        80000003   0 726f4320 4d542865 35692029 3333332d  Core(TM) i5-333
        80000004   0 50432030 20402055 30302e33   7a4847 0 CPU @ 3.00GHz 
        80000005   0        0        0        0        0 
        80000006   0        0        0  1006040        0 64B 8-way 256KB 
        80000007   0        0        0        0      100 +InvariantTSC 
        80000008   0     3024        0        0        0 36b 48b 

## How to output?

        jrmwng::cpuid_tree_t<0x17> CPUID;
        jrmwng::cpuid_tree_t<0x80000008> ExtendedCPUID;
        
        std::ofstream ofs("cpuid.txt");
        ofs << CPUID << ExtendedCPUID;

## How to input?

        jrmwng::cpuid_tree_t<0x17> CPUID(ifs);
        jrmwng::cpuid_tree_t<0x80000008> ExtendedCPUID(ifs);
        
        std::ifstream ifs("cpuid.txt");
        ifs >> CPUID >> ExtendedCPUID;
