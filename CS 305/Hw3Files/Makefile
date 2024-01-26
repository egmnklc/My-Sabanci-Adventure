tutorial4: lex.yy.c tutorial4.tab.c tutorial4.tab.h
	gcc -o tutorial4 lex.yy.c tutorial4.tab.c -lfl

lex.yy.c: tutorial4.flx
	flex tutorial4.flx

clean:
	rm -f lex.yy.c 
	rm -f tutorial4.tab.c 
	rm -f tutorial4.tab.h 
	rm -f tutorial4

scanner: tutorial4.flx
	flex tutorial4.flx
	gcc -o scanner lex.yy.c -lfl

test1:
	./tutorial4 < test1.txt

test2:
	./tutorial4 < test2.txt

test3:
	./tutorial4 < test3.txt