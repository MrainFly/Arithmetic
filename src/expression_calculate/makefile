TOPDIR=../..

LIB		= 
TARGET = $(shell basename `pwd`)

LIBS	= -lar

#exclude subdirs
exclude_dirs=

#files want to build: eg. CSRCS=a.c  CPPSRCS=b.cpp  SSRCS=c.S
CSRCS	= $(wildcard *.c)

#includings and flags
CFLAGS = -I $(TOPDIR)/include/ \
		-I $(TOPDIR)/include/data_struct

include $(TOPDIR)/rules.mk