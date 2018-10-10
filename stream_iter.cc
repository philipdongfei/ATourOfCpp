#include    <string>
#include    <fstream>
#include    <iostream>
#include    <iterator>
#include    <algorithm>

using namespace std;

int stream_test()
{
    //istream
    string from, to;
    cin>>from>>to;      // get source and target file names

    ifstream is {from};  // input stream for file "from"
    istream_iterator<string> ii {is};    // input iterator fro stream
    istream_iterator<string> eos {};     // input sentinel

    ofstream os {to};        // output stream for file "to"
    ostream_iterator<string> oo {os,"\n"};    // output iterator for stream

    vector<string> b{ii,eos};     // b is a vector initialized from input
    sort(b.begin(),b.end());        // sort the buffer

    unique_copy(b.begin(),b.end(),oo);    // copy buffer to output,discard replicated values

    return !is.eof() || !os;

}

int main()
{
    //ostream
    ostream_iterator<string> oo{cout};    //write strings to cout
    *oo = "Hello,";   // meaning cout<<"Hello,"
    ++oo;
    *oo = "world!\n";   // meaning cout<<"world!\n"

    return stream_test();

}
