// cout
#include <iostream>
// setw to pretty output
#include <iomanip>
// autoexplicative...
#include <vector>
#include <string>
#include <algorithm>

// choosing to be practical...
#if 1
    using namespace std;
#else
    using std::cout;
    using std::endl;
#endif

// Useful functions (I really need them?)
void print_vector(const vector<int> &V) {
    cout << "vector [ ";
    for (auto it : V)
        cout << it << " ";
    cout << "]" << endl;
}

vector<int> solution(int N, vector<int> &A) {

    vector<int> *p_counters = new vector<int>(N);
    int counter_max = 0;

    constexpr int kSetAllToMax = -1;

    auto counter_sel = [p_counters](int value) {
        if (value < (p_counters->size() + 1))
            return value - 1;
        return kSetAllToMax;
    };

    for (auto it : A) {
        int idx = counter_sel(it);

        if (idx >= 0) {
            (*p_counters)[idx]++;
            counter_max = max(counter_max, (*p_counters)[idx]);
        } else {
            delete p_counters;
            p_counters = new vector<int>(N, counter_max);
//            for (int i = 0; i < N; i++)
//                counters[i] = counter_max;
        }
        // output
        // print_vector(*p_counters);
    }

    return *p_counters;
}


int main(int argc, char **argv) {
    auto ret = 0;

    int my_ints[] = {3, 4, 4, 6, 1, 4, 4};
    vector<int> my_vec(my_ints, my_ints + (sizeof(my_ints)/sizeof(int)));
    vector<int> cnts;

    cnts = solution(5, my_vec);

    cout << "Breakpoint spot!" << endl;
    return ret;
}