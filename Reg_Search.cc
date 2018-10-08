#include    <regex>
#include    <iostream>
#include    <fstream>
#include    <istream>


using namespace std;

void use()
{
    ifstream in("file.txt");    // input file
    if (!in)
        cerr<<"no file\n";

    regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"}; // U.S postal code pattern

    int lineno = 0;
    for (string line; getline(in, line);) {
        ++lineno;
        smatch matches; // matched strings go here
        if (regex_search(line, matches, pat)) {    
            cout<<lineno<<": "<<matches[0]<<'\n';   // the complete match
            if (1<matches.size() && matches[1].matched)
                cout<<"\t: "<<matches[1]<<'\n'; // submatch
            

        }
    }
}

int main(int argc, char *argv[])
{


    use();

    //regex pat{"\\w{2}\\s*\\d{5}(-\\d{4})?}"};  // regular expressions error ?
    //regex pat{R"(\w{2}\s*\d{5}(-\d{4})?)"}; // U.S postal code pattern
    //regex pat{R"((ab)+)"};
    regex pat{R"((ab)+?)"};

    int lineno = 0;
    for (string line; getline(cin, line);) {    // read into line buffer
        ++lineno;
        smatch matches;     // matched strings go here
        if (regex_search(line, matches, pat)) // search for pat in line
            cout<<lineno<<":"<<matches[0]<<'\n';
        else
            cout<<"no match: "<<line<<'\n';

    
    }
    

    return 0;

}
