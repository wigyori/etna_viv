GCABI ?= v2
PLATFORM_GL_LIBS ?= -lEGL -lGLESv2

CC = $(GCCPREFIX)gcc
CXX = $(GCCPREFIX)g++
LD = $(GCCPREFIX)ld
AR = $(GCCPREFIX)ar

GCC_CFLAGS = -D_POSIX_C_SOURCE=200809 -D_GNU_SOURCE
COMMON_FLAGS = -O2 -g -Wall -Wmissing-prototypes -DGCABI_${GCABI} $(GCC_CFLAGS) -I$(TOP)/lib -I$(TOP)/include_$(GCABI) -g -fPIC \
          -I$(TOP)/gallium/include -I$(TOP)/gallium/auxiliary -I$(TOP) \
          -fdiagnostics-show-option \
          -Werror=missing-prototypes -Werror=missing-declarations -Werror=implicit-function-declaration

CFLAGS += $(PLATFORM_CFLAGS) $(COMMON_FLAGS) -std=gnu99
CXXFLAGS += $(PLATFORM_CXXFLAGS) $(COMMON_FLAGS)
LDFLAGS += $(PLATFORM_LDFLAGS) $(COMMON_FLAGS) -lm

