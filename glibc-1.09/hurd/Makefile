# Copyright (C) 1991, 1992, 1993, 1994 Free Software Foundation, Inc.
# This file is part of the GNU C Library.

# The GNU C Library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public License
# as published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.

# The GNU C Library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Library General Public License for more details.

# You should have received a copy of the GNU Library General Public
# License along with the GNU C Library; see the file COPYING.LIB.  If
# not, write to the Free Software Foundation, Inc., 675 Mass Ave,
# Cambridge, MA 02139, USA.

subdir := hurd

all:

# Some things below (but before including Rules) use configuration variables.
include ../Makeconfig


headers = hurd.h $(interface-headers) \
	  $(addprefix hurd/,fd.h id.h port.h signal.h userlink.h \
		            resource.h threadvar.h)

distribute := hurdfault.h intr-rpc.awk intr-rpc.defs STATUS

# The RPC interfaces go in a separate library.
interface-library := libhurduser.a
user-interfaces		:= $(addprefix hurd/,\
				       auth process startup \
				       msg msg_reply msg_request \
				       exec core interrupt \
				       fs fsys io term socket ifsock)
server-interfaces	:= hurd/msg

routines = hurdinit hurdid hurdlookup hurdpid hurdrlimit hurdprio hurdexec \
	   __setauth setauth \
	   __pid2task __task2pid pid2task task2pid \
	   getuids setuids getumask fchroot \
	   hurdsock hurdauth invoke-trans \
	   privports \
	   msgportdemux \
	   fopenport __fopenport \
 	   vpprintf \
	   ports-get ports-set hurdports hurdmsg \
	   $(sig) $(dtable) hurdinline
sig	= hurdsig hurdfault faultexc siginfo hurd-raise preempt-sig \
	  trampoline longjmp-ctx longjmp-ts catch-exc exc2signal hurdkill
dtable	= dtable port2fd new-fd alloc-fd intern-fd \
	  __getdport getdport openport \
	  fd-close fd-read fd-write hurdioctl
aux := hurdsyms

# XXX this is a temporary hack; see hurdmalloc.h
routines += hurdmalloc
distribute += hurdmalloc.h

# Get the proper definition of `hurd-srcdir'.
include ../sysdeps/mach/hurd/Makefile

# Use and install the Hurd header files directly out of the Hurd source.

# Find the MiG defs files in the Hurd source.
vpath %.defs $(hurd-srcdir)

# Install all .h and .defs files we find in the Hurd's hurd/ directory.
hurd-headers := $(patsubst $(hurd-srcdir)/%,%,\
			   $(wildcard $(addprefix $(hurd-srcdir)/hurd/,\
						  *.defs *.h)))


# Don't distribute the Hurd headers; they are in the Hurd distribution.
dont_distribute = $(hurd-headers)

# DO NOT try to remake these in any way!!!
$(addprefix $(hurd-srcdir)/,$(hurd-headers)) : ;
install-others += $(addprefix $(includedir)/,$(hurd-headers))
$(includedir)/hurd/%: $(hurd-srcdir)/hurd/%; $(do-install)

include ../mach/Machrules
include ../Rules

# intr-rpc.defs defines the INTR_INTERFACE macro to make the generated RPC
# stubs send-interruptible, and to prefix them with `hurd_intr_rpc_'.
user-MIGFLAGS += -imacros intr-rpc.defs

# Run each generated user stub through intr-rpc.awk, which will detect
# stubs __hurd_intr_rpc_% and generate the user-callable function for the
# stub: this is a wrapper which calls __hurd_intr_rpc_% inside
# HURD_EINTR_RPC.
define transform-user-stub
gawk -v call=$${call} -f $(word 2,$^) \
	$(objpfx)tmp_$${call}.c > $(objpfx)tmpi_$${call}.c; \
rm -f $(objpfx)tmp_$${call}.c;
endef
transform-user-stub-output = tmpi

$(foreach if,$(user-interfaces),$($(if)-calls:%=$(objpfx)RPC_%.o))): \
	hurd/signal.h

$(user-interfaces:%=$(objpfx)%.ustamp): intr-rpc.awk

$(objpfx)fault%.c $(objpfx)fault%.h: $(mach-srcdir)/mach/%.defs
	$(MIG) $(MIGFLAGS) -prefix _hurdsig_fault_ \
	       -server $(@:.h=.c) -sheader $(@:.c=.h) \
	       -user /dev/null -header /dev/null \
	       $<
generated += faultexc.c faultexc.h

# We need this static dependency to get faultexc.h generated the first time.
$(objpfx)hurdfault.o $(objpfx)hurdfault.d: \
	$(objpfx)faultexc.h $(objpfx)faultexc.c
