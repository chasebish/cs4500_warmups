compile:
	clang -g -Wall -pedantic print.cpp

test:
	./a.out
	./a.out kidzbop
	./a.out -f diff.txt
	./a.out -i 90
	./a.out -i 90 -f diff.txt
	./a.out -f chase.txt -i 10 comment
	- ./a.out -f chase.txt -i -1 comment
	- ./a.out -f chase.txt -i 1 comment comment2
	- ./a.out -f chase.txt -f chad.txt
	- ./a.out -i 90 -i 91
	- ./a.out bob builder

clean:
	rm -rf a.out a.out.dSYM