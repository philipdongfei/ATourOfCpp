#include    <regex>
#include    <iostream>
#include    <fstream>
#include    <istream>


using namespace std;

bool is_identifier(const string& s)
{
    //regex pat{"[_[:alpha:]]\\w*"};//underscore or letter
                                  // followed by zero or more underscores,letters,or digits
    regex pat{R"([_[:alpha:]]\w*)"};
    return regex_match(s,pat);
}

bool is_submatch(const string& s)
{
    regex pat{R"((?:\s|:|,)*(\d*))"};
    return regex_match(s,pat);

}

int main(int argc, char *argv[])
{

    ifstream in("file_match.txt");    // input file
    if (!in)
        cerr<<"no file\n";

    regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"}; // U.S postal code pattern

    int lineno = 0;
    for (string line; getline(in, line);) {
    
        ++lineno;
        if (is_identifier(line))
            cout<<lineno<<" match: "<<line<<'\n';
        else
            cout<<lineno<<" no match: "<<line<<'\n';
    }
    

    return 0;

}

