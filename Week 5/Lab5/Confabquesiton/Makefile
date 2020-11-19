.RECIPEPREFIX = +

CFLAGS = -g -std=c99 -Wall -Werror


coder: confab.o coder.o
+gcc -o coder coder.o confab.o -lm

coder.o: coder.c confab.h
+gcc $(CFLAGS) -c coder.c

confab.o: confab.c confab.h
+gcc $(CFLAGS) -c confab.c


clean:
+rm coder.o confab.o

