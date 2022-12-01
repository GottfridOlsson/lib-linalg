CC = gcc

CFLAGS = \
	 -fPIC\
	 -pedantic \
	 -Wall \
	 -Werror \
	 -Iinclude

CFLAGS_OPT = \
	     -O2 \
	     -march=native

LIBS = \
	-lm \
	-lgsl \
	-lgslcblas


ifeq ($(MAKECMDGOALS),test)
-include unit-test/test.mk
else
CFLAGS += $(CFLAGS_OPT)
endif

all: obj src/linalg

obj: 
	mkdir -p obj
	mkdir -p lib

src/%:
	$(CC) $(CFLAGS) -c src/$*.c -o obj/$*.o $(LIBS)
	$(CC) obj/$*.o -shared -o lib/lib$*.so $(LIBS)
#	$(CC) -dynamiclib obj/$*.o -o lib/lib$*.dylib $(LIBS)

clean:
	rm -rf obj
	rm -rf lib 
	
.PHONY: clean
