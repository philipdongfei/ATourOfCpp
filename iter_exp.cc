#include    <string>
#include    <algorithm>
#include    <vector>
#include    <iostream>


using namespace std;

bool has_c(const string& s, char c)     // does s contain the character c?
{
    auto p = find(s.begin(), s.end(), c);
    if (p!=s.end())
        return true;
    else
        return false;

    //return find(s.begin(),s.end(),c)!=s.end(); // equivalent upper code, shorter.
}

vector<string::iterator> find_all(string& s, char c)    // find all occurrences of c in s
{
    vector<string::iterator> res;
    for (auto p = s.begin(); p!=s.end(); ++p)
        if(*p == c)
            res.push_back(p);
    return res;

}

void test()
{
    string m {"Mary had a little lamb."};
    for (auto p : find_all(m,'a'))
        if(*p!='a')
            cerr<<"a bug!\n";
}



int main(int argc, char* argv[])
{
    test();


    return 0;
}

