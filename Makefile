all:cloudfs

#OBJS=cloudfs.o fs.o
CC=gcc
OBJS=hello.o
LDFLAGS=-lanl -lrt `pkg-config fuse --libs`
CFLAGS+=--std=c99 -Wall -Wshadow -pedantic -g `pkg-config fuse --cflags`
CFLAGS+=-D_GNU_SOURCE -D_POSIX_C_SOURCE=200809 -D_XOPEN_SOURCE

cloudfs:$(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
.PHONY=clean all
clean:
	-rm -f *.o cloudfs tags
