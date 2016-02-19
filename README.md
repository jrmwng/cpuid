# cpuid
CPUID in C++ template, supporting output and input of cpuid data in human friendly text format

## C++ header file

\#include "[cpuid.h](https://github.com/jrmwng/cpuid/blob/master/cpuid.h)"

## How to ...

- [How to output the CPUID trees?](#how-to-output-the-cpuid-trees)
- [How to output a CPUID leaf?](#how-to-output-a-cpuid-leaf)
- [How to save CPUID data to a file?](#how-to-save-cpuid-data-to-a-file)
- [How to load CPUID data from a file?](#how-to-load-cpuid-data-from-a-file)
- [How to check features?](#how-to-check-features)

### How to output the CPUID trees?

      jrmwng::cpuid_forest_t CPUID;

      std::cout << CPUID;

#### Sample Output (trees)

                         0   0       15 756e6547 6c65746e 49656e69 GenuineIntel
                         1   0    406e3   100800 fed87383 bfcbfbff 06_4EH +SSE3 +PCLMULQDQ -DTES64 -MONITOR -DS_CPL -VMX -SMX +EIST +TM2 +SSSE3 -CNXT_ID -SDBG +FMA +CMPXCHG16B +xTPR_UpdateControl -PDCM -PCID -DCA +SSE4.1 +SSE4.2 -x2APIC +MOVBE +POPCNT -TSC_Deadline +AES +XSAVE +OSXSAVE +AVX +F16C +RDRAND +FPU +VME +DE +PSE +TSC +MSR +PAE +MCE +CX8 +APIC +SEP +MTRR +PGE +MCA +CMOV +PAT +PSE36 -PSN +CLFSH -DS +ACPI +MMX +FXSR +SSE +SSE2 +SS +HTT +TM +PBE
                         2   0 76036301   F0B5FF        0   C30000
                         4   0 1C004121  1C0003F       3F        0 D-Cache L1  2processor(s)  8core(s)  8way(s) * 1partition(s) * 64B *    64set(s)
                         4   1 1C004122  1C0003F       3F        0 I-Cache L1  2processor(s)  8core(s)  8way(s) * 1partition(s) * 64B *    64set(s)
                         4   2 1C004143   C0003F      3FF        0 U-Cache L2  2processor(s)  8core(s)  4way(s) * 1partition(s) * 64B *  1024set(s)
                         4   3 1C03C163  2C0003F      FFF        2 U-Cache L3 16processor(s)  8core(s) 12way(s) * 1partition(s) * 64B *  4096set(s)
                         6   0      7F3        2        9        0 +ThermalSensor +TurboBoost -ARAT +PLN +ECMD +PTM +HWP -HDC +SETBH
                         7   0        0   1C2BBF        0        0 +FSGSBASE +IA32_TSC_ADJUST +SGX +BMI1 +HLE +AVX2 -FDP_EXCPTN_ONLY +SMEP +BMI2 +FastString -INVPCID +RTM -PQM +SuppressFCS +SuppressFDS -MPX -PQE -AVX512F -AVX512DQ +RDSEED +ADX +SMAP -AVX512IFMA -PCOMMIT -CLFLUSHOPT -CLWB -PT -AVX512PF -AVX512ER -AVX512CD -SHA -AVX512BW -AVX512VL -PREFTEHCHWT1 -AVX512VBMI -PKU -OSPKE
                         B   0        1        2      100        0     SMT x2APIC-ID=0 Topology-ID=0 Logical-Processor=2
                         B   1        4        4      201        0    Core x2APIC-ID=0 Topology-ID=0 Logical-Processor=4
                         D   0        7      340      340        0 +x87 +SSE +AVX -BNDREGS -BNDCSR -Opmask -ZMM_Hi256 -Hi16_ZMM -PT -PKRU -LWP 832B 832B
                         D   1        1        0        0        0 +XSAVEOPT -Compaction_Extensions -XGETBV -XSAVES_IA32_XSS 0B
                         D   2      100      240        0        0 AVX        256B @  576B
                        15   0        2       D0        0        0 208TSC / 2CLK
                  40000000   0 4000000A 7263694D 666F736F 76482074 Microsoft Hv
                  40000001   0 31237648        0        0        0 Hv#1
                  40000002   0     295A    A0000        0        3 [Version 10.0.10586] SP0.3.0
                  40000003   0     1FFF   2BB9FF        2    7FBF2 +VP_Runtime +PartitionReferenceCounter +BasicSynIC_MSRs +SyntheticTimerMSRs +APIC_AccessMSRs +HypercallMSRs +AccessVirtualProcessorIndexMSRs +VirtualSystemResetMSR +AccessStatisticsPagesMSRs +AccessPartitionReferenceTSC +AccessGuestIdleMSRs +AccessFrequencyMSRs +AccessDebugMSRs +CreatePartitions +AccessPartitionId +AccessMemoryPool +AdjustMessageBuffers +PostMessages +SignalEvents +CreatePort +ConnectPort +AccessStats +Debugging +CpuManagement +ConfigureProfiler -EnableExpandedStackwalking C2 -HPET -MWAIT +GuestDebugging -PerformanceMonitor -PhysicalCPU_DynamicPartitioningEvents +HypercallInputViaXMM +VirtualGuestIdleState +HypervisorSleepState +NUMA_Distances +TimerFrequencies +SyntheticMachineChecks -GuestCrashMSRs +DebugMSRs +NPIEP +DisableHypervisor
                  40000004   0     2D1C      FFF        0        0 -RecommendAddressSpaceSwitch -RecommendLocalTLB_Flushes +RecommendRemoteTLB_Flushes +RecommendMSR_ForAPIC_Registers +RecommendMSR_ToInitiateSystemRESET -RecommendRelaxedTiming -UseDMA_Remapping -UseInterruptRemapping +Use_x2APIC_MSRs -DeprecateAutoEOI RecommendSpinLockRetry=4095
                  40000005   0      140      200      324        0 MaxOfVirtualProcessors=320 MaxOfLogicalProcessors=512 MaxOfPhysicalInterruptVectors=804
                  40000006   0       AF        0        0        0 +APIC_OverlayAssist +MSR_Bitmaps +ArchitecturalPerformanceCounters +SecondLevelAddressTranslation -DMA_Remapping +InterruptRemapping -MemoryPatrolScrubberPresent
                  40000007   0 80000003        3        0        0
                  80000000   0 80000008        0        0        0             
                  80000001   0        0        0      121 28100800 +LAHF +SAHF -CmpLegacy -SVM -ExtApicSpace -AltMovCr8 +ABM -SSE4A -MisAlignSse +3DNowPrefetch -OSVW -IBS -XOP -SKINIT -WDT -LWP -FMA4 -TBM -TopologyExtensions -PerfCtrExtCore -PerfCtrExtNB -DataBreakpointEx -PerfTsc -MONITORX +SYSCALL +SYSRET +NX -MmxExt -FFXSR -Page1GB +RDTSCP +LM -3DNowExt -3DNow!
                  80000002   0 65746E49 2952286C 726F4320 4D542865 Intel(R) Core(TM
                  80000003   0 35692029 3033362D 43205530 40205550 ) i5-6300U CPU @
                  80000004   0 342E3220 7A484730        0        0  2.40GHz        
                  80000006   0        0        0  1006040        0 L2:64B*0*8way=256KB
                  80000007   0        0        0        0      100 -McaOverflowRecov -SUCCOR -HWA CpuPwrSampleTimeRatio=0 -TS -FID -VID -TTP -TM -100MHzSteps -HwPstate +TscInvariant -CPB -EffFreqR0 -ProcFeedbackInterface -ProcPowerReporting
                  80000008   0     3027        0        0        0 PhysAddrSize=39 LinAddrSize=48 GuestPhysAddrSize=0 NC=0 ApicIdCoreIdSize=0 PerfTscSize=0

### How to output a CPUID leaf?

      jrmwng::cpuid_leaf_t<0x04> CPUID04;
      
      std::cout << CPUID04;

#### Sample Output (leaf 0x04)

     4   0      121  1c0003f       3f        0 D-Cache L1  1processor(s) 1core(s)  8way(s) * 1partition(s) * 64B *   64set(s) 
     4   1      122  1c0003f       3f        0 I-Cache L1  1processor(s) 1core(s)  8way(s) * 1partition(s) * 64B *   64set(s) 
     4   2      143  1c0003f      1ff        0 U-Cache L2  1processor(s) 1core(s)  8way(s) * 1partition(s) * 64B *  512set(s) 
     4   3      163  4c0003f     3fff        2 U-Cache L3  1processor(s) 1core(s) 20way(s) * 1partition(s) * 64B * 16384set(s) 

### How to save CPUID data to a file?

      jrmwng::cpuid_forest_t CPUID;
      
      std::ofstream ofs("cpuid.txt");
      ofs << CPUID;

### How to load CPUID data from a file?

      jrmwng::cpuid_forest_t CPUID;
      
      std::ifstream ifs("cpuid.txt");
      ifs >> CPUID;

### How to check features?

      jrmwng::cpuid_standard_tree_t CPUID;
      
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
