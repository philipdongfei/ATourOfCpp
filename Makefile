CCFLAGS := -std=c++14 -O2

# chapter 1
helloworld: HelloWorld.cc
	g++ -o HelloWorld.out ${CCFLAGS}  HelloWorld.cc
printsquare: print_square.cc
	g++ -o print_square.out ${CCFLAGS} print_square.cc

# chapter 2
MyEnum: MyEnum.cc
	g++ -o MyEnum.out ${CCFLAGS} MyEnum.cc
MyStruct: MyStruct.cc
	g++ -o MyStruct.out ${CCFLAGS} MyStruct.cc
MyClass: MyClass.cc
	g++ -o MyClass.out ${CCFLAGS} MyClass.cc
Template_Func: Template_Func.cc T_Vector.h T_Vector.cc
	g++ -o Template_Func.out ${CCFLAGS} Template_Func.cc T_Vector.h T_Vector.cc



.PHONY: clean
clean:
	rm *.out


