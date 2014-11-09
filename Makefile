# current directory
PWD := $(shell pwd)

# cross-compiler prefix
CCPREFIX = $(PWD)/../crosscompilers

# LMSASM directory
LMSASMDIR = $(PWD)/../lmsasm

# installation prefix
PREFIX = /Users/antonin/local

# EV3 SD card
SDCARD = /Volumes/EV3DISK

# compilation options
CXX      = $(CCPREFIX)/bin/arm-none-linux-gnueabi-g++
CXXFLAGS = -W -Wall --std=c++11
AR       = $(CCPREFIX)/bin/arm-none-linux-gnueabi-ar
JAVA     = java
LMSASM   = $(JAVA) -jar assembler.jar

# library name 
NAME = BotLib

# source list
SRCS = Device.cpp Motor.cpp Robot.cpp

# header list
HEAD = Device.hpp Global.hpp Motor.hpp Robot.hpp

# programs
PROG = botlib_test

###############################################################################
# full library name
LIBNAME = lib$(NAME).a

# objects
OBJ = $(SRCS:%.cpp=%.o)

# Lego VM programs
LMSPROG = $(PROG:%=%.rbf)

# LMS2012 headers
CXXFLAGS += -I $(PWD)/lms2012 -I $(PWD)/..

# dependencies location
DEPDIR = .deps
df     = $(DEPDIR)/$(*F)

all: $(LIBNAME) $(LMSPROG)

botlib_test: test.cpp $(LIBNAME)
	@ echo "CXXLD (ARM) $@"
	@ $(CXX) $(CXXFLAGS) test.cpp -static-libstdc++ -o $@ -L $(PWD) -lBotLib

$(LIBNAME): $(OBJ)
	@ echo "AR    (ARM) $@"
	@ $(AR) rcs $@ $^

# C++ rule
%.o: %.cpp
	@ $(CXX) -MM $(CXXFLAGS) -o $(DEPDIR)/$*.d $<;      \
	cp $(df).d $(df).P;                                 \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $(df).d >> $(df).P;\
	rm -f $(df).d
	@ echo "CXX   (ARM) $@"
	@ $(CXX) $(CXXFLAGS) -c -o $@ $<

# LMSASM rule
%.rbf: %.lms
	@ echo "LMSASM      $@"
	@ cd $(LMSASMDIR); $(LMSASM) $(PWD)/$*; cd - &>/dev/null
	
%.lms: %
	@ sed 's/@bin@/$*/g' program.lms.template > $@

# dependency include
-include $(SRCS:%.cpp=$(DEPDIR)/%.P)

.PHONY: clean distclean install uninstall

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f $(LIBNAME) $(PROG) $(LMSPROG) $(PROG:%=%.lms)
	
install:
	mkdir -p $(PREFIX)/include/$(NAME)
	install $(HEAD) $(PREFIX)/include/$(NAME)
	mkdir -p $(PREFIX)/lib
	install $(LIBNAME) $(PREFIX)/lib
	[ -d $(SDCARD)/bin ]    && (install $(PROG) $(SDCARD)/bin) || true
	[ -d $(SDCARD)/myapps ] && (install $(LMSPROG) $(SDCARD)/myapps) || true
	
uninstall:
	rm -rf $(PREFIX)/include/$(NAME)
	rm -f  $(PREFIX)/lib/$(LIBNAME)
