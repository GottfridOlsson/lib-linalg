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
      -lm


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
#	$(CC) $@ -shared -o lib/$*.so

src/%:
	$(CC) $(CFLAGS) -c src/$*.c -o obj/$*.o
	$(CC) obj/$*.o -shared -o lib/lib$*.so $(LIBS)
	$(CC) -dynamiclib obj/$*.o -o lib/lib$*.dylib $(LIBS)

clean:
	find -iname "*.o" -exec rm {} \;
	find -iname "*.d" -exec rm {} \;
	find -iname "*.so" -exec rm {} \;
	rm -rf obj
	rm -rf lib 
	
.PHONY: clean
