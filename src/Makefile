CC = gcc
CFLAGS = -Wall
LDFLAGS = -lm
RM = rm -f
SRC = reader.c graph.c scanner.c postscript.c list.c dijkstra.c solver.c heap.c packet.c packetmod.c timer.c
OBJ = $(SRC:.c=.o)
EXEC = main convertPostscript convertPostscriptDijkstra convertPostscriptCritical testList testPacket convertTimer


all: $(EXEC)

.depend: $(SRC) $(EXEC:=.c)
	 $(CC) -MM $^ > $@

-include .depend

%: %.o $(OBJ) 
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	$(RM) $(OBJ) .depend $(SRC:.c=.h.gch) $(EXEC:=.o)

mrproper:
	$(RM) $(OBJ) $(EXEC) .depend $(SRC:.c=.h.gch) $(EXEC:=.o)

.PHONY: all clean mrproper
