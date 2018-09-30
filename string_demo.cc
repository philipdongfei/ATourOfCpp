#include    <string>
#include    <iostream>

using namespace std;

using Jstring = basic_string<char>;

string name = "Niels Stroustrup";

string compose(const string& name, const string& domain)
{
    return name + '@' + domain;
}

void m2(string& s1, string& s2)
{
    s1 = s1+'\n';
    s2 += '\n';
}

void m3()
{
    string s = name.substr(6,10);   // s = "Stroustrup"
    name.replace(0, 5, "nicholas"); // name becomes "nicholas Stroustrup"
    name[0] = toupper(name[0]);


}

void print(const string& s)
{
    printf("For people who like printf:%s\n", s.c_str());
    cout<<"For people who like streams:"<<s<<'\n';
}

int main(int argc, char *argv[])
{
    auto addr = compose("dmr", "bell-labs.com");

    cout<<addr<<'\n';

    print("pig");

    Jstring strJapan{"japan"};

    cout<<strJapan<<'\n';


    return 0;
}
