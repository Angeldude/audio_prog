POBJS = ieee80.o portsf.o

PLIB = ../include/portsf.h ieee80.h

CFLAGS = -c

CC = gcc

all:     libportsf.a

clean:
        -rm -f $(POBJS)

veryclean:
        -rm -f $(POBJS)
        rm -f libportsf.a
        sudo rm -f /usr/lib/libportsf.a
        sudo rm -f /usr/include/portsf.h
        sudo rm -f /usr/include/ieee80.h

libportsf.a: $(POBJS)
