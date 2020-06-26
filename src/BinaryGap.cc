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

int main(int argc, char **argv) {
    auto ret = 0;

    cout << "Breakpoint spot!" << endl;
    return ret;
}