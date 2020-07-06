/* https://www.hackerrank.com/challenges/designer-pdf-viewer/\
problem?utm_campaign=challenge-recommendation&utm_medium=email&utm_source=24-hour-campaign */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the designerPdfViewer function below.
int designerPdfViewer(vector<int> h, string word) {
    int max_h = 0;

    for(auto i = 0; i < word.size(); ++i) {
        /* avoid index out of range on h */
        if(!islower(word[i])) {
            cout << "char '" << word[i] << "' is *not* a lowercase letter!" << endl;
            return -1;
        }
        int v_offset = word[i] - 'a';
        // cout << "offset of '" << word[i] << "' is " << v_offset << endl;
        max_h = max(max_h, h[v_offset]);
    }

    return max_h * word.size();
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp_temp = "1 3 1 3 1 4 1 3 2 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5 7";
//    getline(cin, h_temp_temp);

    vector<string> h_temp = split_string(h_temp_temp);

    vector<int> h(26);

    for (int i = 0; i < 26; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    string word;
    getline(cin, word);

    int result = designerPdfViewer(h, word);

    //fout << result << "\n";
    cout << result << "\n";

    //fout.close();

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
