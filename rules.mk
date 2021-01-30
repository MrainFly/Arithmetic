empty :=
space := $(empty) $(empty)

CC        = gcc
AR        = ar
READELF   = readelf
RM        = -rm -rf
MAKE      = make

OPTIM     = -O0

CFLAGS    += $(OPTIM) -g -Wall

LIBSGROUP := -Wl,--start-group $(LIBS) -Wl,--end-group -L$(TOPDIR)/lib

dirs      := $(shell find . -maxdepth 1 -type d)   # find the max depth of the dirctory
dirs      := $(basename $(patsubst ./%,%,$(dirs))) # strip the ./
dirs      := $(filter-out $(exclude_dirs),$(dirs)) # filter the exclude_dirs
SUBDIRS   := $(dirs)

COBJS      = $(CSRCS:.c=.o)
DEPS       = $(CSRCS:.c=.d)

OBJS       = $(COBJS)
DEP_LIBS   = $(filter $(wildcard $(LIBOUT)/*.a), $(patsubst -l%, $(LIBOUT)/lib%.a, $(LIBS)))

TGTOUT    = $(TOPDIR)/out
LIBOUT    = $(TOPDIR)/lib

.PHONY: all clean ld libs apps subdirs_l subdirs_t subdirs_c ext strip show_lib_ver

all     : libs apps
libs    : $(LIBOUT)/$(LIB) ext subdirs_l
apps    : $(TGTOUT)/$(TARGET) ext subdirs_t

$(LIBOUT)/$(LIB)   : $(COBJS)
	if [ "$(LIB)" != "" ]; then \
	$(AR) rs $@  $^; \
	fi

$(TGTOUT)/$(TARGET): $(OBJS) $(DEP_LIBS)
	if [ "$(TARGET)" != "" ]; then \
	$(CC) -o $@ $(OBJS) $(LIBSGROUP); \
	fi
	
subdirs_l	:
	@for dir in $(SUBDIRS);\
    do if [ -f "$$dir/makefile" ]; then $(MAKE) -C $$dir libs||exit 1; fi;\
    done
    
subdirs_t	:
	@for dir in $(SUBDIRS);\
    do if [ -f "$$dir/makefile" ]; then $(MAKE) -C $$dir apps||exit 1; fi;\
    done

$(COBJS)	: %.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	
subdirs_c	:
	@for dir in $(SUBDIRS);\
	do if [ -f "$$dir/makefile" ]; then $(MAKE) -C $$dir clean||exit 1; fi;\
	done

clean	: subdirs_c
	@if [ -n "$(TARGET)" ]; then rm -rf $(TGTOUT)/$(TARGET)* $(COBJS)$(DEPS) *.o; fi
	@if [ -n "$(LIB)" ]; then rm -rf $(LIBOUT)/$(LIB) $(COBJS)$(DEPS) *.o; fi

-include $(DEPS)
