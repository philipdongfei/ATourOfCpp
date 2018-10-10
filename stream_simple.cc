#include    <fstream>
#include    <set>
#include    <iterator>
#include    <string>
#include    <iostream>
#include    <algorithm>

using namespace std;

int main()
{
    string from, to;
    cin>>from>>to;      // get source and target file names

    ifstream is{from};  // input stream for file "from"
    ofstream os{to};    // output stream for file "to"

    //istream_iterator<string> ii {is};    // input iterator fro stream
    //istream_iterator<string> eos {};     // input sentinel
    set<string> b{istream_iterator<string>{is}, istream_iterator<string>{}};  // read input
    //set<string> b{ii,eos};

    //ostream_iterator<string> oo{os,"\n"};
    copy(b.begin(), b.end(), ostream_iterator<string>{os,"\n"});     // copy to output

    return !is.eof()||!os;    // return error state
}
