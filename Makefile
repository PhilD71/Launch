CFLAGS = -Wall

all: launch

release: CFLAGS += -O2
release: launch tidy

debug: CFLAGS += -g -O0
debug: launch

launch: launch.o
	gcc $(CFLAGS) -o launch launch.o

launch.o:
	gcc $(CFLAGS) -o launch.o -c launch.c

clean:
	rm -rf launch.o launch

tidy:
	rm -rf *.o
