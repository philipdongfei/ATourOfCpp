#include    <vector>
#include    <iostream>
#include    <random>
#include    <functional>


using namespace std;

class Rand_int{
public:
    Rand_int(int low, int high):dist{low, high}{}
    int operator()(){return dist(re);}    // draw an int
private:
    default_random_engine re;
    uniform_int_distribution<> dist;

};

void testrandom()
{
    using my_engine = default_random_engine;    // type of engine
    using my_distribution = uniform_int_distribution<>;  // type of distribution

    my_engine re{};     // the default engine
    my_distribution one_to_six{1, 6};       // distribution that maps to the ints 1..6
    auto die = bind(one_to_six, re);        // make a generator

    int x = die();      // roll the die: x becomes a value in [1:6]

    cout<<"test random x = "<<x<<'\n';
}

int main(void)
{
    testrandom();

    constexpr int max = 9;
    Rand_int rnd{0, max};       // make a uniform random number generator

    vector<int> histogram(max+1);   // make a vector of appropriate size
    for (int i=0; i!=200; ++i)
        ++histogram[rnd()];         // fill histogram with the frequencies of numbers [0:max]

    for (int i=0; i!=histogram.size(); ++i) {    // write out a bar graph
        cout<<i<<'\t';
        for (int j=0;j!=histogram[i]; ++j) cout<<'*';
        cout<<endl;
    }

}

