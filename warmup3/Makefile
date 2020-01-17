docker:
	g++ -Wall -std=c++11 main.cpp

run:
	rm -rf a.out
	make docker
	./a.out -f doc.txt
	./a.out -f helloworld.txt

test:
	g++ -Wall -std=c++11 test.cpp
	./a.out

clean:
	rm -rf a.out
	rm -rf warmup3.zip