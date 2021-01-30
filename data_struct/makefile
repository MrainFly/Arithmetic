TOPDIR=..

#lib or target you want to build: eg. LIB=libmisc.a  or TARGET=wlan
LIB		= libar.a

TARGET	=

#exclude subdirs
exclude_dirs= $(patsubst ./%,%,$(shell find . -maxdepth 2 -type d))

#files want to build: eg. CSRCS=a.c  CPPSRCS=b.cpp  SSRCS=c.S
CSRCS	= $(shell find . -name "*.c")
CPPSRCS	=
SSRCS	=

#includings and flags
CFLAGS =  -I $(TOPDIR)/include/ \
		-I $(TOPDIR)/include/data_struct

include $(TOPDIR)/rules.mk

