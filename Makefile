
CC = g++
LD = g++

CFLAGS = -Wall -std=c++11 -g
LFLAGS = -Wall -g

TRAB4OBJS = main.o sistema.o paciente.o

TRABALHOS = ./execTrab4

.cpp.o:
	$(CC) $(CFLAGS) -c $<

all: $(TRABALHOS)

execTrab4: $(TRAB4OBJS)
	$(LD) $(LFLAGS) -o $@ $(TRAB4OBJS) -lm

clean:
	rm -f *.o $(TRABALHOS)
