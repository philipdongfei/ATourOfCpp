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
string_demo: string_demo.cc
	g++ -o string_demo.out ${CCFLAGS} string_demo.cc
Reg_Search: Reg_Search.cc
	g++ -o Reg_Search.out ${CCFLAGS} Reg_Search.cc
Reg_Expre: Reg_Expre.cc
	g++ -o Reg_Expre.out ${CCFLAGS} Reg_Expre.cc
Reg_Group: Reg_Group.cc
	g++ -o Reg_Group.out ${CCFLAGS} Reg_Group.cc
output_example: output_example.cc
	g++ -o output_example.out ${CCFLAGS} output_example.cc
input_example: input_example.cc
	g++ -o input_example.out ${CCFLAGS} input_example.cc
IO_UserDef: IO_UserDef.cc
	g++ -o IO_UserDef.out ${CCFLAGS} IO_UserDef.cc
Format_exp: Format_exp.cc
	g++ -o Format_exp.out ${CCFLAGS} Format_exp.cc
sstream_exp: sstream_exp.cc
	g++ -o sstream_exp.out ${CCFLAGS} sstream_exp.cc
# chapter 9
vector_exp: vector_exp.cc
	g++ -o vector_exp.out ${CCFLAGS} vector_exp.cc
list_exp: list_exp.cc 
	g++ -o list_exp.out ${CCFLAGS} list_exp.cc 
map_exp: map_exp.cc
	g++ -o map_exp.out ${CCFLAGS} map_exp.cc
unordermap_exp: unordermap_exp.cc
	g++ -o unordermap_exp.out ${CCFLAGS} unordermap_exp.cc







.PHONY: clean
clean:
	rm *.out


