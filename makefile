CC 	= ccache gcc
LINKING = -lm -I.
DEBUG	= -g -fvar-tracking -Wall -W -pedantic -Wformat=2 -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wextra -Wunused-variable -fstrict-aliasing -Wstrict-aliasing=2 -Wfloat-equal -Wundef -Wshadow -Wlarger-than-8192 -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wconversion -Waggregate-return -Wmissing-field-initializers -Wmissing-noreturn -Wredundant-decls -Wunreachable-code -Winline -Winvalid-pch -Wlong-long -DUSE_IO #-DDEBUG
CDEBUG  = -Wbad-function-cast -Wdeclaration-after-statement  -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations 
PROFILE = -pg -Q -ftime-report -fmem-report -fprofile-arcs -ftree-based-profiling -fbranch-probabilities -ftest-coverage 
ERROR 	= -Werror
CCFLAGS	=  -D_GNU_SOURCE  
OPTIMIZE =  -DOPTIMIZE -std=c9x -DNOCHECKS
BASE	= $(CC) $(CCFLAGS)
TESTING = $(BASE) $(DEBUG) $(CDEBUG)
ALL	= $(TESTING) $(OPTIMIZE) $(LINKING)
OBJECTS	= list.o node.o queue.o deque.o vector.o conversions.o stack.o binary_tree.o

all: vec_tests list_tests tree_tests
list_tests: list_test.x queuelist_test.x dequelist_test.x stacklist_test.x
vec_tests: vec_test.x queuevector_test.x dequevector_test.x stackvector_test.x basevector_test.x vector_test.x
tree_tests: binarytree_test.x

list_test.x: list_test.c $(OBJECTS)
	$(ALL) list_test.c -o list_test.x $(OBJECTS)

queuelist_test.x: queuelist_test.c $(OBJECTS)
	$(ALL) queuelist_test.c -o queuelist_test.x $(OBJECTS)

stacklist_test.x: stacklist_test.c $(OBJECTS)
	$(ALL) stacklist_test.c -o stacklist_test.x $(OBJECTS)

dequelist_test.x: dequelist_test.c $(OBJECTS)
	$(ALL) dequelist_test.c -o dequelist_test.x $(OBJECTS)

queuevector_test.x: queuevector_test.c $(OBJECTS)
	$(ALL) queuevector_test.c -o queuevector_test.x $(OBJECTS)

stackvector_test.x: stackvector_test.c $(OBJECTS)
	$(ALL) stackvector_test.c -o stackvector_test.x $(OBJECTS)

dequevector_test.x: dequevector_test.c $(OBJECTS)
	$(ALL) dequevector_test.c -o dequevector_test.x $(OBJECTS)

vector_test.x: vector_test.c $(OBJECTS)
	$(ALL) vector_test.c -o vector_test.x $(OBJECTS)

basevector_test.x: basevector_test.c $(OBJECTS)
	$(ALL) basevector_test.c -o basevector_test.x $(OBJECTS)

binarytree_test.x: binarytree_test.c $(OBJECTS)
	$(ALL) binarytree_test.c -o binarytree_test.x $(OBJECTS)

vec_test.x: vec_test.c $(OBJECTS)
	$(ALL) vec_test.c -o vec_test.x $(OBJECTS)
.c.o:
	$(TESTING) -c $(COPT) $<

clean: 
	rm *.x *.o *~ *.gcno *.gcda; clear
