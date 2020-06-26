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

/* N can range from 0 to 7fff_ffff */
int BinaryGap(int N) {
    vector<int> ones;
    for (auto bit = 0; bit < 31; bit++) {
        auto mask = (1 << bit);
        if ((N & mask) == mask) {
            ones.push_back(bit);
        }
    }

    if (ones.size() < 2)
        return 0;

    cout << "First one is at " << ones.front() << endl;
    auto curr = ones.front();
    int ret = 0;
    for (auto it : ones) {
        cout << "one found at " << it << endl;
        auto this_gap = it - curr - 1;
        if (this_gap > ret) {
            cout << "new ret is " << this_gap << endl;
            ret = this_gap;
        }
        curr = it;
    }

    return ret;
}

int main(int argc, char **argv) {
    auto ret = 0;
    ret = BinaryGap(5);
    cout << "Solution for 5 is " << ret << endl;
    ret = BinaryGap(0x40000000);
    cout << "Solution for 0x40000000 is " << ret << endl;
    ret = BinaryGap(0x40000001);
    cout << "Solution for 0x40000001 is " << ret << endl;
    ret = BinaryGap(0x411);
    cout << "Solution for 0x411 is " << ret << endl;
    ret = BinaryGap(0x3);
    cout << "Solution for 0x3 is " << ret << endl;

    cout << "Breakpoint spot!" << endl;
    return ret;
}