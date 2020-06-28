// cout
#include <iostream>
// setw to pretty output
#include <iomanip>
// autoexplicative...
#include <vector>
#include <string>

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

vector<int> CyclicRotation(const vector<int> &A, int K) {
    if (A.size() < 2 || K == 0)
        return A;

    vector<int> B = A;
    for (auto i = 0; i < K; i++) {
        int rot = B.back();
        B.pop_back();
        auto it = B.begin();
        B.insert(it, rot);
    }
    return B;
}

int main(int argc, char **argv) {
    auto ret = 0;

    vector<int> my_vec;

    for (auto i = 0; i < 5; i ++)
        my_vec.push_back(i);
    print_vector(my_vec);

    vector<int> my_vec_r = CyclicRotation(my_vec, 1);
    print_vector(my_vec_r);

    my_vec_r = CyclicRotation(my_vec, 3);
    print_vector(my_vec_r);

    cout << "Breakpoint spot!" << endl;
    return ret;
}