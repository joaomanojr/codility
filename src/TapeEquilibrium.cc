// cout
#include <iostream>
// setw to pretty output
#include <iomanip>
// autoexplicative...
#include <vector>
#include <string>

#include <stdlib.h> /* labs */

// choosing to be practical...
#if 1
    using namespace std;
#else
    using std::cout;
    using std::endl;
#endif

int TapeEquilibrium(const vector<int> &A) {
    int partA, partB = 0, min = 0;

    partA = A[0];
    for (auto i = 1; i < A.size(); i++) {
        partB += A[i];
    }
    min = labs(partA - partB);

    if (A.size() == 2)
        return min;

    for (auto i = 1; i < (A.size() - 1); i++) {
        int new_min;
        partA += A[i];
        partB -= A[i];
        new_min = labs(partA - partB);
        if (new_min < min)
            min = new_min;
    }

    return min;
}

int main(int argc, char **argv) {
    auto ret = 0;
    int my_ints[] = {-10, -20, -30, -40, 100};
    vector<int> my_vec(my_ints, my_ints + (sizeof(my_ints)/sizeof(int)));

    cout << "Equilibrium is " << TapeEquilibrium(my_vec) << endl;
    cout << "Breakpoint spot!" << endl;
    return ret;
}