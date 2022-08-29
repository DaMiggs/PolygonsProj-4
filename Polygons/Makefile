CC = gcc
CFLAGS = -I. -g -w
DEPS = polygons.h
OBJ = polygons.o handleFile.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

polygons: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
		rm -rf polygons
		rm -rf *.o
		
x:
		make
		./polygons 100

me:
		make
		./polygons 1
		
exec:
		./polygons