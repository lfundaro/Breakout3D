GCC = gcc
OPS = -g
LINK_OPS = -lglut -lGL -lGLU -lX11  -lm -L/usr/X11R6/lib
OBJS = main.o elementos.o Lector.o Nivel.o utils.o
TEST_OBJS = 

all: $(OBJS) Makefile
	$(GCC) $(OPS) $(LINK_OPS) $(OBJS) -o breakout

main.o : main.c
	$(GCC) $(OPS) -c main.c

elementos.o: elementos.c
	$(GCC) $(OPS) -c elementos.c

Lector.o: Lector.c
	$(GCC) $(OPS) -c Lector.c

Nivel.o: Nivel.c
	$(GCC) $(OPS) -c Nivel.c

utils.o: utils.c
	$(GCC) $(OPS) -c utils.c

test: 
	$(GCC) $(LINK_OPS) test.c -o test 

clean:
	rm -rf main breakout test .\#* \#* *.o .*~ *~ *.gch
