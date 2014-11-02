# current directory
PWD := $(shell pwd)

# cross-compiler prefix
CCPREFIX = $(PWD)/../crosscompilers

# installation prefix
PREFIX = /Users/antonin/local

# compilation options
CXX      = $(CCPREFIX)/bin/arm-none-linux-gnueabi-g++
CXXFLAGS = -W -Wall --std=c++11
AR       = $(CCPREFIX)/bin/arm-none-linux-gnueabi-ar

# library name 
NAME = BotLib

# source list
SRCS = Device.cpp Motor.cpp

# header list
HEAD = Device.hpp Global.hpp Motor.hpp

###############################################################################
# full library name
LIBNAME = lib$(NAME).a

# objects
OBJ = $(SRCS:%.cpp=%.o)

# LMS2012 headers
CXXFLAGS += -I $(PWD)/lms2012 -I $(PWD)/..

# dependencies location
DEPDIR = .deps
df     = $(DEPDIR)/$(*F)

all: $(LIBNAME) botlib_test

botlib_test: test.cpp $(LIBNAME)
	@ echo "CXXLD (ARM) $@"
	@ $(CXX) $(CXXFLAGS) test.cpp -static-libstdc++ -o $@ -L $(PWD) -lBotLib

$(LIBNAME): $(OBJ)
	@ echo "AR    (ARM) $@"
	@ $(AR) rcs $@ $^

# C++ rule
%.o: %.cpp Makefile
	@ $(CXX) -MM $(CXXFLAGS) -o $(DEPDIR)/$*.d $<;      \
	cp $(df).d $(df).P;                                 \
	sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
		-e '/^$$/ d' -e 's/$$/ :/' < $(df).d >> $(df).P;\
	rm -f $(df).d
	@ echo "CXX   (ARM) $@"
	@ $(CXX) $(CXXFLAGS) -c -o $@ $<

# dependency include
-include $(SRCS:%.cpp=$(DEPDIR)/%.P)

.PHONY: clean install

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f $(LIBNAME) botlib_test
	
install:
	mkdir -p $(PREFIX)/include/$(NAME)
	install $(HEAD) $(PREFIX)/include/$(NAME)
	mkdir -p $(PREFIX)/lib
	install $(LIBNAME) $(PREFIX)/lib
	
uninstall:
	rm -rf $(PREFIX)/include/$(NAME)
	rm -f  $(PREFIX)/lib/$(LIBNAME)
