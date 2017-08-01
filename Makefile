
CC=gcc

_libs=x11

CFLAGS=$(shell pkg-config --cflags $(_libs))
LDLIBS=$(shell pkg-config --libs $(_libs))

#%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

all: kbdevent

termlex: kbdevent.c

clean:
	$(RM) *.o kbdevent

#install:
#	install -Dm755 termlex /usr/local/bin/termlex
#	install -Dm644 termlex.desktop /usr/share/applications/termlex.desktop
