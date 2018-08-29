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

BUILD_SPEC = SIMPENTIUMdiab_RTP
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := /home/ilazrak/WindRiver/workspace
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/hello



#Global Build Macros
PROJECT_TYPE = RTP
DEFINES = 
DO_STRIP = 0
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = simpentium
CPU = SIMPENTIUM
TOOL_FAMILY = diab
TOOL = diab
TOOL_PATH = 
CC_ARCH_SPEC = -tX86LH:rtpsim
LIBPATH = 
LIBS = -lstlstd
VSB_DIR = $(WIND_BASE)/target/lib
VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h

IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/config/xlnx_zynq7k -I$(WIND_BASE)/target/usr/h/wrn/coreip 

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
PROJECT_TARGETS = hello/$(MODE_DIR)/hello.vxe


#Rules

# hello
ifeq ($(DEBUG_MODE),1)
hello/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
hello/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
hello/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
hello/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
hello/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
hello/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler =  -XO
hello/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler =  -XO
hello/$(MODE_DIR)/% : DEBUGFLAGS_Linker = 
hello/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
hello/$(MODE_DIR)/% : DEBUGFLAGS_Assembler =  -XO
endif
hello/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/usr/h -I$(WIND_BASE)/target/config/xlnx_zynq7k -I$(WIND_BASE)/target/usr/h/wrn/coreip 
hello/$(MODE_DIR)/% : IDE_LIBRARIES = 
hello/$(MODE_DIR)/% : IDE_DEFINES = -D_VX_CPU=_VX_$(CPU) -D_VX_TOOL_FAMILY=$(TOOL_FAMILY) -D_VX_TOOL=$(TOOL)   -D_VSB_CONFIG_FILE=\"$(VSB_DIR)/h/config/vsbConfig.h\" 
hello/$(MODE_DIR)/% : PROJECT_TYPE = RTP
hello/$(MODE_DIR)/% : DEFINES = 
hello/$(MODE_DIR)/% : DO_STRIP = 0
hello/$(MODE_DIR)/% : EXPAND_DBG = 0
hello/$(MODE_DIR)/% : VX_CPU_FAMILY = simpentium
hello/$(MODE_DIR)/% : CPU = SIMPENTIUM
hello/$(MODE_DIR)/% : TOOL_FAMILY = diab
hello/$(MODE_DIR)/% : TOOL = diab
hello/$(MODE_DIR)/% : TOOL_PATH = 
hello/$(MODE_DIR)/% : CC_ARCH_SPEC = -tX86LH:rtpsim
hello/$(MODE_DIR)/% : LIBPATH = 
hello/$(MODE_DIR)/% : LIBS = -lstlstd
hello/$(MODE_DIR)/% : VSB_DIR = $(WIND_BASE)/target/lib
hello/$(MODE_DIR)/% : VSB_CONFIG_FILE = $(VSB_DIR)/h/config/vsbConfig.h
hello/$(MODE_DIR)/% : OBJ_DIR := hello/$(MODE_DIR)

hello/$(MODE_DIR)/Objects/hello/hello.o : $(PRJ_ROOT_DIR)/hello.c $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dcc $(DEBUGFLAGS_C-Compiler) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(VSB_DIR)  -W:c++:.CPP -Xforce-declarations -ei4167,4092,4152,4167,4171,4174,4186,4188,4191,4192,4223,4231,4236,4284,4375,4494,4513,5152,5457,2273,5387,5388   -Xmake-dependency=0xd $(IDE_DEFINES) $(DEFINES) $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -o "$@" -c "$<"


OBJECTS_hello = hello/$(MODE_DIR)/Objects/hello/hello.o

ifeq ($(TARGET_JOBS),1)
hello/$(MODE_DIR)/hello.vxe : $(OBJECTS_hello)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)dplus $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -Xansi -WDVSB_DIR=$(VSB_DIR)  -W:c++:.CPP -Xforce-declarations -ei4167,4092,4152,4167,4171,4174,4186,4188,4191,4192,4223,4231,4236,4284,4375,4494,4513,5152,5457,2273,5387,5388   -Xmake-dependency=0xd  -f 0x90,1,1 -o "$@" $(OBJECTS_hello) $(ADDED_OBJECTS) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS) -L$(VSB_DIR)/usr/lib/simpentium/SIMPENTIUM/common $(ADDED_LIBPATH) $(ADDED_LIBS)   && if [ "$(DO_STRIP)" = "1" ]; then mv -f "$@" "$@.unstripped" && strippentium -g -o "$@" "$@.unstripped";fi && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

else
hello/$(MODE_DIR)/hello.vxe : hello/$(MODE_DIR)/hello.vxe_jobs

endif
hello/$(MODE_DIR)/hello_compile_file : $(FILE) ;

_clean :: hello/$(MODE_DIR)/hello_clean

hello/$(MODE_DIR)/hello_clean : 
	$(TRACE_FLAG)if [ -d "hello" ]; then cd "hello"; rm -rf $(MODE_DIR); fi

force : 

TARGET_JOBS_RULE?=echo "Update the makefile template via File > Import > Build Settings : Update makefile template";exit 1
%_jobs : 
	$(TRACE_FLAG)$(TARGET_JOBS_RULE)

DEP_FILES := hello/$(MODE_DIR)/Objects/hello/hello.d
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
