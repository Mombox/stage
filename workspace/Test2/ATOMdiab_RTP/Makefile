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

BUILD_SPEC = ATOMdiab_RTP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := /home/ilazrak/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/Test2



#Global Build Macros
PROJECT_TYPE = RTP
DEFINES = 
DO_STRIP = 0
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = pentium
CPU = ATOM
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tATOMLH:rtp
LIBPATH = 
LIBS = -lstlstd
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 

IDE_LIBRARIES = 

IDE_DEFINES = -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler =  -XO
DEBUGFLAGS_C++-Compiler =  -XO
DEBUGFLAGS_Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler =  -XO
endif


#Project Targets
PROJECT_TARGETS = Test2/$(MODE_DIR)/Test2.vxe


#Rules

# Test2
ifeq ($(DEBUG_MODE),1)
Test2/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Test2/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Test2/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
Test2/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Test2/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Test2/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -XO
Test2/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -XO
Test2/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
Test2/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Test2/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -XO
endif
Test2/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/usr/h/wrn/coreip 
Test2/$(MODE_DIR)/% : IDE_LIBRARIES = 
Test2/$(MODE_DIR)/% : IDE_DEFINES = -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" 
Test2/$(MODE_DIR)/% : PROJECT_TYPE = RTP
Test2/$(MODE_DIR)/% : DEFINES = 
Test2/$(MODE_DIR)/% : DO_STRIP = 0
Test2/$(MODE_DIR)/% : EXPAND_DBG = 0
Test2/$(MODE_DIR)/% : VX_CPU_FAMILY = pentium
Test2/$(MODE_DIR)/% : CPU = ATOM
Test2/$(MODE_DIR)/% : TOOL_FAMILY = diab
Test2/$(MODE_DIR)/% : TOOL = diab
Test2/$(MODE_DIR)/% : TOOL_PATH = 
Test2/$(MODE_DIR)/% : CC_ARCH_SPEC = -tATOMLH:rtp
Test2/$(MODE_DIR)/% : LIBPATH = 
Test2/$(MODE_DIR)/% : LIBS = -lstlstd
Test2/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
Test2/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
Test2/$(MODE_DIR)/% : OBJ_DIR := Test2/$(MODE_DIR)

OBJECTS_Test2 =

ifeq ($(TARGET_JOBS),1)
Test2/$(MODE_DIR)/Test2.vxe : $(OBJECTS_Test2)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dplus $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(VSB_DIR)  -W:c++:.CPP -Xforce-declarations -ei4167,4092,4152,4167,4171,4174,4186,4188,4191,4192,4223,4231,4236,4284,4375,4494,4513,5152,5457,2273,5387,5388   -Xmake-dependency=0xd  -o "$@" $(OBJECTS_Test2) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/pentium/ATOM/common $(ADDED_LIBPATH) $(ADDED_LIBS)   && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
Test2/$(MODE_DIR)/Test2.vxe : Test2/$(MODE_DIR)/Test2.vxe_jobs

endif
Test2/$(MODE_DIR)/Test2_compile_file : $(FILE) ;

_clean :: Test2/$(MODE_DIR)/Test2_clean

Test2/$(MODE_DIR)/Test2_clean : 
	$(TRACE_FLAG)if [ -d "Test2" ]; then cd "Test2"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)


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
