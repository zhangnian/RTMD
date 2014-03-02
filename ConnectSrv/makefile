#****************************************************************************
#
# Makefile
#
# This is a GNU make (gmake) makefile
#****************************************************************************

# DEBUG can be set to YES to include debugging info, or NO otherwise
DEBUG          := YES

# PROFILE can be set to YES to include profiling info, or NO otherwise
PROFILE        := NO

#****************************************************************************

CC     := gcc
CXX    := g++
LD     := g++
AR     := ar rc

DEBUG_CFLAGS     := -Wall -Wno-format -g
RELEASE_CFLAGS   := -Wall -Wno-unknown-pragmas -Wno-format -O3


#****************************************************************************

LIBS		 := /dev_common/curl-7.35.0/lib/libcurl.a				\
				/dev_common/hiredis/lib/libhiredis.a				\
				/dev_common/jsoncpp/lib/libjsoncpp.a				\
				/dev_common/log4cpp-1.1.1/lib/liblog4cpp.a			\
				/dev_common/tinyxml2/lib/libtinyxml2.a				\
				/dev_common/muduo-1.0.0-rc1/lib/libmuduo_base.a		\
				/dev_common/muduo-1.0.0-rc1/lib/libmuduo_net.a		\
				/dev_common/protobuf-2.4.1/lib/libprotobuf.a     	\
				-lpthread

#****************************************************************************				
				
DEBUG_CXXFLAGS   := ${DEBUG_CFLAGS} 
RELEASE_CXXFLAGS := ${RELEASE_CFLAGS}

DEBUG_LDFLAGS    := -g
RELEASE_LDFLAGS  :=

ifeq (YES, ${DEBUG})
   CFLAGS       := ${DEBUG_CFLAGS}
   CXXFLAGS     := ${DEBUG_CXXFLAGS}
   LDFLAGS      := ${DEBUG_LDFLAGS}
else
   CFLAGS       := ${RELEASE_CFLAGS}
   CXXFLAGS     := ${RELEASE_CXXFLAGS}
   LDFLAGS      := ${RELEASE_LDFLAGS}
endif

ifeq (YES, ${PROFILE})
   CFLAGS   := ${CFLAGS} -pg -O3
   CXXFLAGS := ${CXXFLAGS} -pg -O3
   LDFLAGS  := ${LDFLAGS} -pg
endif

#****************************************************************************
# Preprocessor directives
#****************************************************************************

DEFS :=


#****************************************************************************

INCS := -I/dev_common/muduo-1.0.0-rc1/include		\
		-I/dev_common/tinyxml2/include				\
		-I/dev_common/zeromq-3.2.4/include			\
		-I/dev_common/protobuf-2.4.1/include		\
		-I/dev_common/hiredis/include				\
		-I/dev_common/jsoncpp/include				\
		-I/dev_common/curl-7.35.0/include			\
		-I/dev_common/log4cpp-1.1.1/include		
		
#****************************************************************************


#****************************************************************************
# Makefile code common to all platforms
#****************************************************************************

CFLAGS   := ${CFLAGS}   ${DEFS}
CXXFLAGS := ${CXXFLAGS} ${DEFS}

#****************************************************************************
# Targets of the build
#****************************************************************************

OUTPUT := ConnectSrv

all: ${OUTPUT}


#****************************************************************************
# Source files
#****************************************************************************

SRCS := main.cpp logger.cpp

# Add on the sources for libraries
SRCS := ${SRCS}

OBJS := $(addsuffix .o,$(basename ${SRCS}))

#****************************************************************************
# Output
#****************************************************************************

${OUTPUT}: ${OBJS}
	${LD} -o $@ ${LDFLAGS} ${OBJS} ${LIBS} ${EXTRA_LIBS}

#****************************************************************************
# common rules
#****************************************************************************

# Rules for compiling source files to object files
%.o : %.cpp
	${CXX} -c ${CXXFLAGS} ${INCS} $< -o $@

%.o : %.c
	${CC} -c ${CFLAGS} ${INCS} $< -o $@

	
clean:
	-rm -f core ${OBJS} ${OUTPUT}

