// cout
#include <iostream>
// setw to pretty output
#include <iomanip>
// autoexplicative...
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

// choosing to be practical...
#if 1
    using namespace std;
#else
    using std::cout;
    using std::endl;
#endif

int OddOccurencesInArraySlow(vector<int> &A){
    vector<int> hist;
    for (auto it : A) {
        bool found = false;
        for (auto ot = 0; ot < hist.size(); ot++) {
            if (hist[ot] == it) {
                found = true;
                hist.erase(hist.begin() + ot);
                break;
            }
        }
        if (!found)
            hist.push_back(it);
    }

    // I hope all pairs have nulled itselves and hist have one element only...
    if (hist.size() == 1)
        return hist.front();

    cout << "ERROR: hist has " << hist.size() << " elements!!" << endl;
    return 0;
}

int OddOccurencesInArray(vector<int> &A){
    std::unordered_map<int, int> hist;
    std::unordered_map<int, int>::iterator ut;

    for (auto it : A) {
        std::unordered_map<int, int>::iterator ot = hist.find(it);
        if (ot != hist.end()) {
            hist[it]++;
        } else {
            hist[it]= 1;
        }
    }

    for (ut = hist.begin(); ut != hist.end(); ++ut) {
        if ((ut->second % 2) != 0)
            return ut->first;
    }

    cout << "ERROR: hist have not odd numbered items!" << endl;
    return 0;
}

int main(int argc, char **argv) {
    auto ret = 0;

    vector<int> arr;

    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(4);
    arr.push_back(8);
    arr.push_back(2);

    int ans = OddOccurencesInArray(arr);

    cout << "Odd occurence is " << ans << endl;

    cout << "Breakpoint spot!" << endl;
    return ret;
}