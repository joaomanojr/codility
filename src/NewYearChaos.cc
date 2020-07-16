/* https://www.hackerrank.com/challenges/new-year-chaos/\
 * problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
 */

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

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    constexpr auto kMaxBribes = 2;
    int min_b = 0;
    std::unordered_map<int, int> bribes;

    /* map and enforce up to kMaxBribes from each person */
    auto add_bribe = [] (std::unordered_map<int, int> &b, int &min_b, int pos) {
        std::unordered_map<int, int>::iterator got = b.find(pos);
        if (got == b.end()) {
            b.insert(make_pair(pos, 1));
            min_b++;
            return true;
        }
        if (got->second < kMaxBribes) {
            got->second++;
            min_b++;
            return true;
        }
        return false;
    };

    for (auto i = 0; i < q.size(); i++) {
        // person on right place -- skip
        if (q[i] == i + 1)
            continue;

        // find were person of this position is now -- all people in between used bribes...
        for(auto j = i; i < q.size(); j++) {
            if (q[j] == i + 1) {
                q.insert(q.begin() + i, q[j]);
                q.erase(q.begin() + (j + 1));
                break;
            }
            if (!add_bribe(bribes, min_b, q[j])) {
                cout << "Too chaotic";
                return;
            }
        }
    }

    cout << min_b;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}






#if 0
int main(int argc, char **argv) {
    auto ret = 0;

    cout << "Breakpoint spot!" << endl;
    return ret;
}
#endif