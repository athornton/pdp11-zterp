# C makefile for the ZIP Infocom interpreter (now called "Zterp" for
#  obvious reasons).  This particular one is for a PDP-11/70, with split
#  instruction and data spaces, running 2.11BSD.

CC = cc
CFLAGS = -O
LDFLAGS =
LIBS = -ltermcap

INC = ztypes.h
OBJ1= zip.o control.o extern.o fileio.o input.o interpre.o math.o 
OBJ2= object.o operand.o osdepend.o property.o screen.o text.o
OBJ3= variable.o unixio.o
OBJS= ${OBJ1} ${OBJ2} ${OBJ3} ${MEM}
MEM= memory.o
ALL_OBJ= -Z ${OBJ1} -Z ${OBJ2} -Z ${OBJ3} -Z ${MEM}
zterp : ${OBJS}
	ld -s -i -X /lib/crt0.o -o zterp ${ALL_OBJ} -Y ${LIBS} -lc

$(OBJS) : $(INC) extern.c

clean :
	-rm *.o zterp
