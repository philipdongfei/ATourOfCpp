CCFLAGS := -std=c++14 -O2

# chapter 1
helloworld: HelloWorld.cc
	g++ -o HelloWorld.out -std=c++11 -O2 HelloWorld.cc
printsquare: print_square.cc
	g++ -o print_square.out ${CCFLAGS} print_square.cc

# chapter 2
MyEnum: MyEnum.cc
	g++ -o MyEnum.out ${CCFLAGS} MyEnum.cc
MyStruct: MyStruct.cc
	g++ -o MyStruct.out ${CCFLAGS} MyStruct.cc
MyClass: MyClass.cc
	g++ -o MyClass.out ${CCFLAGS} MyClass.cc



.PHONY: clean
clean:
	rm *.out


