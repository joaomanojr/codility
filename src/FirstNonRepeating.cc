// cout
#include <iostream>
// setw to pretty output
#include <iomanip>
// autoexplicative...
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <unordered_set>




// choosing to be practical...
#if 1
    using namespace std;
#else
    using std::cout;
    using std::endl;
#endif

int FirstNonRepeatingWithQueue(const char &new_char, char *first_non_repeated) {
    static queue<char> unique;
    static unordered_set<char> occured;
    static unordered_set<char> repeated;

    if (occured.find(new_char) == occured.end()) {
        occured.insert(new_char);
        unique.push(new_char);
    } else {
        if (repeated.find(new_char) == repeated.end()) {
            repeated.insert(new_char);
        }
        if (unique.front() == new_char) {
            while (unique.size() > 0) {
                if (repeated.find(unique.front()) == repeated.end())
                    break;
                unique.pop();
            }
        }
    }

    // check for queue not empty.
    if (unique.size() > 0) {
        *first_non_repeated = unique.front();
        return 0;
    }
    return -1;
}

int FirstNonRepeating(const char &new_char, char *first_non_repeated) {
    // Create an empty deque
    static deque<char> unique;
    static unordered_set<char> repeated;

    if (repeated.find(new_char) == repeated.end()) {
        bool new_unique = true;
        for (auto i = 0; i < unique.size(); i++) {
            if (unique[i] == new_char) {
               repeated.insert(new_char);
               unique.erase(unique.begin() + i);
               new_unique = false;
               break;
            }
        }
        if (new_unique) {
            unique.push_back(new_char);
        }
    }

    // check for queue not empty.
    if (unique.size() > 0) {
        *first_non_repeated = unique.front();
        return 0;
    }
    return -1;
}

int main(int argc, char **argv) {
    auto ret = 0;
    char first_non_repeating = '\0';

    string test_string {"geeks for geeks for..."};
    for (auto i = 0; i < test_string.size(); i++) {
        ret = FirstNonRepeating(test_string[i], &first_non_repeating);
        cout << "'" << test_string[i] << "', ret = " << ret <<
            ", first is " << first_non_repeating << endl;
    }

    cout << "Breakpoint spot!" << endl;
    return ret;
}