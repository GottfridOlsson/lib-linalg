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

#obj/%.o: src/%.c
#	$(CC) -MMD -c $(CFLAGS) $< -o $@
#	$(CC) $@ -shared -o lib/$*.so $(LIBS)
#

src/%:
	$(CC) $(CFLAGS) -c src/$*.c -o obj/$*.o $(LIBS)
	$(CC) obj/$*.o -shared -o lib/lib$*.so $(LIBS)

clean:
	find -iname "*.o" -exec rm {} \;
	find -iname "*.d" -exec rm {} \;
	find -iname "*.so" -exec rm {} \;
	rm -rf obj
	rm -rf lib 
	
.PHONY: clean
