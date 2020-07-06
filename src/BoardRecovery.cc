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

string solution(int U, int L, vector<int> &C) {
    string my_sol_u, my_sol_l;

    // Check for impossible
    // if (C.size() * 2 > (U + L)) {
    //     return "IMPOSSIBLE";
    // }

    for (auto it : C)
        switch (it) {
            // 0 and 2 means just fill upper and lower with ones or zeroes
            case 0:
                my_sol_u = my_sol_u + "0";
                my_sol_l = my_sol_l + "0";
                break;
            case 2:
                my_sol_u = my_sol_u + "1";
                U--;
                my_sol_l = my_sol_l + "1";
                L--;
                break;
            case 1:
                /* Wrong part on my answer to this : didn't tried to balance U and L */
                if (U >= L && U > 0) {
                    my_sol_u = my_sol_u + "1";
                    U--;
                    my_sol_l = my_sol_l + "0";
                } else if (L >= U && L > 0) {
                    my_sol_u = my_sol_u + "0";
                    my_sol_l = my_sol_l + "1";
                    L--;
                } else {
                    return "IMPOSSIBLE";
                }
        }

        return my_sol_u + "," + my_sol_l;
}

int main(int argc, char **argv) {
    auto ret = 0;

    std::vector<int> C {0, 1, 2, 1, 1, 0};

    cout << "Solution is " << solution(3, 2, C) << endl;
    cout << "Breakpoint spot!" << endl;
    return ret;
}