#
_XDCBUILDCOUNT = 1
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/libarch_1_0_0_0/packages;C:/ti/mathlib_c66x_3_1_1_0/packages;C:/ti/linalg_1_2_0_0/packages;C:/ti/dsplib_c66x_3_4_0_0/packages;C:/ti/xdais_7_24_00_04/packages;C:/ti/xdais_7_24_00_04/examples;C:/ti/ctoolslib_2_2_0_0/packages;C:/ti/bios_6_73_01_01/packages;C:/ti/ndk_3_40_01_01/packages;C:/ti/openmp_dsp_c667x_2_06_00_00/packages;C:/ti/edma3_lld_2_12_05_30C/packages;C:/ti/openmp_dsp_c667x_2_06_02_01/packages;C:/ti/pdk_c667x_2_0_5/packages;C:/ti/imglib_c66x_3_1_1_0/packages;C:/ti/ipc_3_50_03_04/packages;C:/ti/uia_2_30_01_02/packages;C:/ti/framework_components_3_40_02_07/packages;C:/ti/framework_components_3_40_02_07/examples;C:/ti/xdctools_3_51_01_18_core/packages
override XDCROOT = C:/ti/xdctools_3_51_01_18_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/libarch_1_0_0_0/packages;C:/ti/mathlib_c66x_3_1_1_0/packages;C:/ti/linalg_1_2_0_0/packages;C:/ti/dsplib_c66x_3_4_0_0/packages;C:/ti/xdais_7_24_00_04/packages;C:/ti/xdais_7_24_00_04/examples;C:/ti/ctoolslib_2_2_0_0/packages;C:/ti/bios_6_73_01_01/packages;C:/ti/ndk_3_40_01_01/packages;C:/ti/openmp_dsp_c667x_2_06_00_00/packages;C:/ti/edma3_lld_2_12_05_30C/packages;C:/ti/openmp_dsp_c667x_2_06_02_01/packages;C:/ti/pdk_c667x_2_0_5/packages;C:/ti/imglib_c66x_3_1_1_0/packages;C:/ti/ipc_3_50_03_04/packages;C:/ti/uia_2_30_01_02/packages;C:/ti/framework_components_3_40_02_07/packages;C:/ti/framework_components_3_40_02_07/examples;C:/ti/xdctools_3_51_01_18_core/packages;C:/ti/xdctools_3_51_01_18_core/packages;..
HOSTOS = Windows
endif
