POBJS = ieee80.o portsf.o

CFLAGS = -c

CC = gcc

all:	libportsf.a

clean:
	-rm -f $(POBJS)
	rm -f libportsf.a

libportsf.a: $(POBJS)
	ar -rc libportsf.a $(POBJS)
	ranlib libportsf.a

ieee80.o: ieee80.c ieee80.h
	$(CC) $(CFLAGS) ieee80.c

portsf.o: portsf.c
	$(CC) $(CFLAGS) portsf.c
