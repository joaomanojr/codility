// cout
#include <iostream>
// setw to pretty output
#include <iomanip>
// autoexplicative...
#include <vector>
#include <string>
#include <limits>

// choosing to be practical...
#if 1
    using namespace std;
#else
    using std::cout;
    using std::endl;
#endif

int solution(int A, int B) {
    int bits = 0;
    int d_bit = 0;
    unsigned long long big_a = static_cast<unsigned long long> (A);
    unsigned long long big_b = static_cast<unsigned long long> (B);
    unsigned long long big_long = big_a * big_b;

    for(; big_long != 0; big_long >>= 1, d_bit++) {
        if (big_long & 1) {
            bits++;
            cout << "biT " << d_bit << " is set!" << endl;
        }
    }

    return bits;
}

int main(int argc, char **argv) {
    auto ret = 0;
    //                     2386f26fc10000 = maxprod
    long long big_long = 0x23860000000000;
//                            100_0000_0000
    int bits = solution(100000000,100000000);

    cout << "I can see " << bits << " bits." << endl;
    return ret;
}