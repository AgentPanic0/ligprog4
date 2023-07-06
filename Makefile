
CC = g++
LD = g++

CFLAGS = -Wall -std=c++11
LFLAGS = -Wall

TRAB3OBJS = main.o sistema.o paciente.o

TRABALHOS = ./execTrab4

.cpp.o:
	$(CC) $(CFLAGS) -c $<

all: $(TRABALHOS)

execTrab3: $(TRAB4OBJS)
	$(LD) $(LFLAGS) -o $@ $(TRAB4OBJS) -lm

clean:
	rm -f *.o $(TRABALHOS)
