egemenkilic-hw3: lex.yy.c egemenkilic-hw3.tab.c egemenkilic-hw3.tab.h
	gcc -o egemenkilic-hw3 lex.yy.c egemenkilic-hw3.tab.c -lfl

lex.yy.c: egemenkilic-hw3.flx
	flex egemenkilic-hw3.flx

egemenkilic-hw3.tab.c  egemenkilic-hw3.tab.h:  egemenkilic-hw3.y
	bison -d  egemenkilic-hw3.y

clean:
	rm -f lex.yy.c
	rm -f egemenkilic-hw3.tab.c
	rm -f egemenkilic-hw3.tab.h
	rm -f egemenkilic-hw3

scanner: egemenkilic-hw3.flx
	flex egemenkilic-hw3.flx
	gcc -o scanner lex.yy.c -lfl

test1:
	./egemenkilic-hw3 < test1.txt