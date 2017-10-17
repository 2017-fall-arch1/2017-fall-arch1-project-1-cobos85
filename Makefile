all: pm_bst


CFLAGS = -g -03

pm_bst: pm_bst.o
	cc -o $@ $^

pm_bst.o: pm_bst.c pm_bst.h
	cc -c $(CFLAGS) pm_bst.c

clean:
	rm -f *.o pm_bst

demo: pm_bst
	./pm_bst
