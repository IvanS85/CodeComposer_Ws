#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = C:/ti/bios_6_73_01_01/packages;C:/ti/pdk_c667x_2_0_12/packages;C:/ti/ndk_3_40_01_01/packages;C:/ti/uia_2_30_01_02/packages;C:/MyWork/Work/CCS_Workspace/OmpTest/.config
override XDCROOT = C:/ti/xdctools_3_51_01_18_core
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = C:/ti/bios_6_73_01_01/packages;C:/ti/pdk_c667x_2_0_12/packages;C:/ti/ndk_3_40_01_01/packages;C:/ti/uia_2_30_01_02/packages;C:/MyWork/Work/CCS_Workspace/OmpTest/.config;C:/ti/xdctools_3_51_01_18_core/packages;..
HOSTOS = Windows
endif
