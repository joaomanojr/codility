// cout
#include <iostream>
// setw to pretty output
#include <iomanip>
// autoexplicative...
#include <vector>
#include <string>
#include <unordered_set>

// choosing to be practical...
#if 1
    using namespace std;
#else
    using std::cout;
    using std::endl;
#endif

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::unordered_set<int> occurences;
    int min = 1;

    for (auto it : A) {
        if (it < 1)
            continue;
        if (it == min) {
            while(occurences.find(++min) != occurences.end());
        } else {
            if(occurences.find(it) == occurences.end())
                occurences.insert(it);
        }
    }

    return min;
}

int main(int argc, char **argv) {
    auto ret = 0;

    std::vector<int> my_vec {-1, -3};

    cout << "Solution is " << solution(my_vec) << endl;
    cout << "Breakpoint spot!" << endl;
    return ret;
}



