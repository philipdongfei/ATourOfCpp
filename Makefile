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
con_copy: con_copy.cc Entry.h 
	g++ -o con_copy.out ${CCFLAGS} con_copy.cc Entry.h 
iter_exp: iter_exp.cc
	g++ -o iter_exp.out ${CCFLAGS} iter_exp.cc
iter_gen: iter_gen.cc
	g++ -o iter_gen.out ${CCFLAGS} iter_gen.cc
stream_iter: stream_iter.cc
	g++ -o stream_iter.out ${CCFLAGS} stream_iter.cc
stream_simple: stream_simple.cc
	g++ -o stream_simple.out ${CCFLAGS} stream_simple.cc
bitset_exp: bitset_exp.cc
	g++ -o bitset_exp.out ${CCFLAGS} bitset_exp.cc
# to fix function_exp, some error.
function_exp: function_exp.cc
	g++ -o function_exp.out -std=c++17 -O2 function_exp.cc
functional_demo: functional_demo.cc
	g++ -o functional_demo.out ${CCFLAGS} functional_demo.cc
# chapter12 
errno_exp: errno_exp.cc
	g++ -o errno_exp.out ${CCFLAGS} errno_exp.cc
NumAlg_exp: NumAlg_exp.cc
	g++ -o NumAlg_exp.out ${CCFLAGS} NumAlg_exp.cc
random_exp: random_exp.cc
	g++ -o random_exp.out ${CCFLAGS} random_exp.cc







.PHONY: clean
clean:
	rm *.out


