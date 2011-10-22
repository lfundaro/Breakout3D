GCC = gcc
OPS =
LINK_OPS = -lglut -lGL -lGLU -lX11  -lm -L/usr/X11R6/lib
OBJS = main.o 
TEST_OBJS = 

all: $(OBJS) Makefile
	$(GCC) $(OPS) $(LINK_OPS) $(OBJS) -o breakout

main.o : main.c
	$(GCC) $(OPS) -c main.c

clean:
	rm -rf main breakout .\#* \#* *.o .*~ *~ *.gch
