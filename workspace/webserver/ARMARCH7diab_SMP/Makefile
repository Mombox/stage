# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))
WRVX_COMPBASE := $(subst \,/,$(WRVX_COMPBASE))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

JOBS?=1
TARGET_JOBS?=$(JOBS)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = ARMARCH7diab_SMP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := /home/ilazrak/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/webserver



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = arm
CPU = ARMARCH7
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tARMV7LV:vxworks69
VSB_DIR = $(WIND_BASE)/target/lib_smp
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = 

IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler =  -XO -Xsize-opt 
DEBUGFLAGS_C++-Compiler =  -XO -Xsize-opt 
DEBUGFLAGS_Linker =  -XO -Xsize-opt 
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler =  -XO -Xsize-opt 
endif


#Project Targets
PROJECT_TARGETS = webserver/$(MODE_DIR)/webserver.out \
	 webserver_partialImage/$(MODE_DIR)/webserver_partialImage.o


#Rules

# webserver
ifeq ($(DEBUG_MODE),1)
webserver/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
webserver/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
webserver/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
webserver/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
webserver/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
webserver/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
webserver/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -XO -Xsize-opt 
webserver/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -XO -Xsize-opt 
webserver/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -XO -Xsize-opt 
webserver/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
webserver/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
webserver/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -XO -Xsize-opt 
endif
webserver/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
webserver/$(MODE_DIR)/% : IDE_LIBRARIES = 
webserver/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 
webserver/$(MODE_DIR)/% : PROJECT_TYPE = DKM
webserver/$(MODE_DIR)/% : DEFINES = 
webserver/$(MODE_DIR)/% : EXPAND_DBG = 0
webserver/$(MODE_DIR)/% : VX_CPU_FAMILY = arm
webserver/$(MODE_DIR)/% : CPU = ARMARCH7
webserver/$(MODE_DIR)/% : TOOL_FAMILY = diab
webserver/$(MODE_DIR)/% : TOOL = diab
webserver/$(MODE_DIR)/% : TOOL_PATH = 
webserver/$(MODE_DIR)/% : CC_ARCH_SPEC = -tARMV7LV:vxworks69
webserver/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib_smp
webserver/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
webserver/$(MODE_DIR)/% : LIBPATH = 
webserver/$(MODE_DIR)/% : LIBS = 
webserver/$(MODE_DIR)/% : OBJ_DIR := webserver/$(MODE_DIR)

OBJECTS_webserver = webserver_partialImage/$(MODE_DIR)/webserver_partialImage.o

ifeq ($(TARGET_JOBS),1)
webserver/$(MODE_DIR)/webserver.out : $(OBJECTS_webserver)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";ddump -Ng $(OBJECTS_webserver) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c arm -tags $(VSB_DIR)/tags/arm/ARMARCH7/common/dkm.tags > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dcc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xdollar-in-ident -ei1518,4177,4223,4301,4550,5409,1606 -ei4193,4826,4381,4237,1573,4007,4082,4177,4223,4260,4550,5361,5828,2273,5387,5388 -ei1522,4092,4111,4152,4167,4171,4174,4186,4188,4191,4192,4223,4231,4236,4284,4375,4494,4513,5152,5457 -Xforce-declarations  $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES)  $(IDE_DEFINES) $(DEFINES) -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)dld -tARMV7LV:vxworks69 -X -r5 -r4 -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_webserver) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
webserver/$(MODE_DIR)/webserver.out : webserver/$(MODE_DIR)/webserver.out_jobs

endif
webserver/$(MODE_DIR)/webserver_compile_file : $(FILE) ;

_clean :: webserver/$(MODE_DIR)/webserver_clean

webserver/$(MODE_DIR)/webserver_clean : 
	$(TRACE_FLAG)if [ -d "webserver" ]; then cd "webserver"; rm -rf $(MODE_DIR); fi


# webserver_partialImage
ifeq ($(DEBUG_MODE),1)
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -XO -Xsize-opt 
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -XO -Xsize-opt 
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker =  -XO -Xsize-opt 
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
webserver_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -XO -Xsize-opt 
endif
webserver_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/wrn/coreip 
webserver_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = 
webserver_partialImage/$(MODE_DIR)/% : IDE_DEFINES = -DCPU=_VX_$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL -D_WRS_VX_SMP -D_WRS_CONFIG_SMP -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" -DARMEL -DARMEL  -DARM_USE_VFP -DARM_USE_VFP -DIP_PORT_VXWORKS=69 
webserver_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
webserver_partialImage/$(MODE_DIR)/% : DEFINES = 
webserver_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
webserver_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = arm
webserver_partialImage/$(MODE_DIR)/% : CPU = ARMARCH7
webserver_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = diab
webserver_partialImage/$(MODE_DIR)/% : TOOL = diab
webserver_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
webserver_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -tARMV7LV:vxworks69
webserver_partialImage/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib_smp
webserver_partialImage/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
webserver_partialImage/$(MODE_DIR)/% : LIBPATH = 
webserver_partialImage/$(MODE_DIR)/% : LIBS = 
webserver_partialImage/$(MODE_DIR)/% : OBJ_DIR := webserver_partialImage/$(MODE_DIR)

webserver_partialImage/$(MODE_DIR)/Objects/webserver/webserver.o : $(PRJ_ROOT_DIR)/webserver.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -W:c:,-Xclib-optim-off -W:c++:,-Xclib-optim-off -Xansi -Xlocal-data-area-static-only  -W:c++:.CPP -Xfp-fast  -Xc-new -Xdialect-c89  -ei1518,4177,4223,4301,4550,5409,1606 -ei4193,4826,4381,4237,1573,4007,4082,4177,4223,4260,4550,5361,5828,2273,5387,5388 -ei1522,4092,4111,4152,4167,4171,4174,4186,4188,4191,4192,4223,4231,4236,4284,4375,4494,4513,5152,5457 -Xforce-declarations   -Xmake-dependency=0xd $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_webserver_partialImage = webserver_partialImage/$(MODE_DIR)/Objects/webserver/webserver.o

ifeq ($(TARGET_JOBS),1)
webserver_partialImage/$(MODE_DIR)/webserver_partialImage.o : $(OBJECTS_webserver_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dld -tARMV7LV:vxworks69 -X -r5  -o "$@" $(OBJECTS_webserver_partialImage) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
webserver_partialImage/$(MODE_DIR)/webserver_partialImage.o : webserver_partialImage/$(MODE_DIR)/webserver_partialImage.o_jobs

endif
webserver_partialImage/$(MODE_DIR)/webserver_partialImage_compile_file : $(FILE) ;

_clean :: webserver_partialImage/$(MODE_DIR)/webserver_partialImage_clean

webserver_partialImage/$(MODE_DIR)/webserver_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "webserver_partialImage" ]; then cd "webserver_partialImage"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := webserver_partialImage/$(MODE_DIR)/Objects/webserver/webserver.d
-include $(DEP_FILES)


WIND_SCOPETOOLS_BASE := $(subst \,/,$(WIND_SCOPETOOLS_BASE))

clean_scopetools :
	$(TRACE_FLAG)rm -rf $(PRJ_ROOT_DIR)/.coveragescope/db

CLEAN_STEP := clean_scopetools


-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

TARGET_JOBS_RULE=$(MAKE) -f $(MAKEFILE) --jobs $(TARGET_JOBS) $(MFLAGS) $* TARGET_JOBS=1
ifeq ($(JOBS),1)
main_all : external_build  $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"
else
main_all : external_build 
	@$(MAKE) -f $(MAKEFILE) --jobs $(JOBS) $(MFLAGS) $(PROJECT_TARGETS) TARGET_JOBS=1 &&\
	echo "make: built targets of `pwd`"
endif 

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
