#
# Warning: you may need more libraries than are included here on the
# build line.  The agent frequently needs various libraries in order
# to compile pieces of it, but is OS dependent and we can't list all
# the combinations here.  Instead, look at the libraries that were
# used when linking the snmpd master agent and copy those to this
# file.
#

CC=arm-linux-gcc

#OBJS1=snmpdemoapp.o
OBJS=wta.o nstAgentSubagentObject.o wlanID.o myTime.o
#OBJS3=asyncapp.o
TARGETS=wta 

CFLAGS=-I. `./net-snmp-config --cflags`
#BUILDLIBS=`net-snmp-config --libs`
BUILDAGENTLIBS=`./net-snmp-config --agent-libs`

# shared library flags (assumes gcc)
#DLFLAGS=-fPIC -shared

all: $(TARGETS)

#snmpdemoapp: $(OBJS1)
#	$(CC) -o snmpdemoapp $(OBJS1) $(BUILDLIBS)

#asyncapp: $(OBJS3)
#	$(CC) -o asyncapp $(OBJS3) $(BUILDLIBS)

wta: $(OBJS)
	$(CC) -o wta $(OBJS)  $(BUILDAGENTLIBS)

clean:
	rm $(OBJS) $(TARGETS)

# nstAgentPluginObject.so: nstAgentPluginObject.c Makefile
# 	$(CC) $(CFLAGS) $(DLFLAGS) -c -o nstAgentPluginObject.o nstAgentPluginObject.c
# 	$(CC) $(CFLAGS) $(DLFLAGS) -o nstAgentPluginObject.so nstAgentPluginObject.o

	