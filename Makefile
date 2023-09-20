RM:
	g++ -o tmp/main src/main.cpp -std=c++17
	cd tmp && touch main.in && ./main < main.in > main.out

RT:
	g++ -o tmp/test test/test.cpp -std=c++17
	cd tmp && ./test
