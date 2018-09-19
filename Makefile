C11FLAGS := -std=c++14 -O2

# chapter 1
helloworld: HelloWorld.cc
	g++ -o HelloWorld.out -std=c++11 -O2 HelloWorld.cc
printsquare: print_square.cc
	g++ -o print_square.out ${C11FLAGS} print_square.cc

# chapter 2








.PHONY: clean
clean:
	rm *.out


