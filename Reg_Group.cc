#include    <regex>
#include    <iostream>
#include    <fstream>
#include    <istream>

using namespace std;

void test()
{
    string input = "aa as; asd ++e^asdf asdfg";
    //regex pat{R"(\s+(\w+))"};
    regex pat{R"((\w+))"};
    for(sregex_iterator p(input.begin(),input.end(),pat); p!=sregex_iterator{}; ++p)
        cout<<(*p)[1]<<'\n';
}

int main(int argc, char *argv[])
{

    test();

    ifstream in("xmldemo.txt");    // input file
    if (!in)
        cerr<<"no file\n";

    //regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"}; // U.S postal code pattern
    regex pat{R"(<(.*?)>(.*?)</\1>)"};

    int lineno = 0;
    for (string line; getline(in, line);) {
    
        ++lineno;
        if (regex_match(line, pat))
            cout<<lineno<<" match: "<<line<<'\n';
        else
            cout<<lineno<<" no match: "<<line<<'\n';
    }
    

    return 0;

}
