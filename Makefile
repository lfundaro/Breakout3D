GCC = gcc
OPS =
LINK_OPS = -lglut -lGL -lGLU -lX11  -lm -L/usr/X11R6/lib
OBJS = main.o elementos.o
TEST_OBJS = 

all: $(OBJS) Makefile
	$(GCC) $(OPS) $(LINK_OPS) $(OBJS) -o breakout

main.o : main.c
	$(GCC) $(OPS) -c main.c

elements.o: elementos.c
	$(GCC) $(OPS) -c elementos.c

test: 
	$(GCC) $(LINK_OPS) test.c -o test 

clean:
	rm -rf main breakout test .\#* \#* *.o .*~ *~ *.gch
