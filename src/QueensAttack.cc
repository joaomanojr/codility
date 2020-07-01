// https://www.hackerrank.com/challenges/queens-attack-2/problem

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttackFirst(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    auto find_obstacle = [n](bool &flag, int r, int c, vector<vector<int>> o) {
        if(r > n || c > n || r < 1 || c < 1) {
            flag = false;
            return 0;
        }
        for (int i = 0; i < o.size(); ++i) {
            if (o[i][0] == r && o[i][1] == c) {
                o.erase(o.begin() + i);
                flag = false;
                return 0;
            }
        }
        return 1;
    };

    int radius = 1;
    int valid_squares = 0;

    bool inc_r = true;
    bool inc_r_c = true;
    bool inc_c = true;
    bool dec_r_inc_c = true;
    bool dec_r = true;
    bool dec_r_c = true;
    bool dec_c = true;
    bool inc_r_dec_c = true;

    do {

        if (inc_r)
            valid_squares += find_obstacle(inc_r,       (r_q + radius), c_q,            obstacles);
        if (inc_r_c)
            valid_squares += find_obstacle(inc_r_c,     (r_q + radius), (c_q + radius), obstacles);
        if (inc_c)
            valid_squares += find_obstacle(inc_c,       r_q,            (c_q + radius), obstacles);
        if (dec_r_inc_c)
            valid_squares += find_obstacle(dec_r_inc_c, (r_q - radius), (c_q + radius), obstacles);
        if (dec_r)
            valid_squares += find_obstacle(dec_r      , (r_q - radius), c_q,            obstacles);
        if (dec_r_c)
            valid_squares += find_obstacle(dec_r_c,     (r_q - radius), (c_q - radius), obstacles);
        if (dec_c)
            valid_squares += find_obstacle(dec_c,       r_q,            (c_q - radius), obstacles);
        if (inc_r_dec_c)
            valid_squares += find_obstacle(inc_r_dec_c, (r_q + radius), (c_q - radius), obstacles);

        radius++;

    }while (inc_r || inc_r_c || inc_c || dec_r_inc_c || dec_r || dec_r_c || dec_c || inc_r_dec_c);

    return valid_squares;
}
// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {

    // create a set and get rid of copies...
    std::unordered_set<string> my_obstacles;
    for (auto it : obstacles) {
        string coord = to_string(it[0]) + " " + to_string(it[1]);
        if (my_obstacles.find(coord) == my_obstacles.end())
            my_obstacles.insert(coord);
    }

    auto find_obstacle = [](bool &flag, int r, int c, std::unordered_set<string> my_o) {
        string coord = to_string(r) + " " + to_string(c);
        if (my_o.find(coord) != my_o.end()) {
            my_o.erase(coord);
            flag = false;
            return 0;
        }
        return 1;
    };

    int valid_squares = 0;
    bool inc_r = true;
    bool dec_r = true;
    bool inc_c = true;
    bool dec_c = true;
    bool inc_r_c = true;
    bool dec_r_c = true;
    bool dec_r_inc_c = true;
    bool inc_r_dec_c = true;
    bool done = false;

    int incd_r = r_q, incd_c = c_q, decd_r = r_q, decd_c = c_q;
    while(!done) {
        done = true;
        incd_r++;
        incd_c++;
        decd_r--;
        decd_c--;

        if (inc_r) {
            if (incd_r <= n) {
                done = false;
                valid_squares += find_obstacle(inc_r, incd_r, c_q, my_obstacles);
            } else {
                inc_r = false;
                inc_r_c = false;
                inc_r_dec_c = false;
            }
        }
        if (dec_r) {
            if (decd_r > 0) {
                done = false;
                valid_squares += find_obstacle(dec_r, decd_r, c_q, my_obstacles);
            } else {
                dec_r = false;
                dec_r_c = false;
                dec_r_inc_c = false;
            }
        }
        if (inc_c) {
            if (incd_c <= n) {
                done = false;
                valid_squares += find_obstacle(inc_c, r_q, incd_c, my_obstacles);
            } else {
                inc_c = false;
            }
        }
        if (dec_c) {
            if (decd_c > 0) {
                done = false;
                valid_squares += find_obstacle(dec_c, r_q, decd_c, my_obstacles);
            } else {
                dec_c = false;
            }
        }

        if (inc_r_c) {
            if ((incd_r <= n) && (incd_c <= n)) {
                done = false;
                valid_squares += find_obstacle(inc_r_c, incd_r, incd_c, my_obstacles);
            } else {
                inc_r_c = false;
            }
        }
        if (inc_r_dec_c) {
            if ((incd_r <= n) && (decd_c > 0)) {
                done = false;
                valid_squares += find_obstacle(inc_r_dec_c, incd_r, decd_c, my_obstacles);
            } else {
                inc_r_dec_c = false;
            }
        }
        if (dec_r_inc_c) {
            if ((decd_r > 0) && (incd_c <= n)) {
                done = false;
                valid_squares += find_obstacle(dec_r_inc_c, decd_r, incd_c, my_obstacles);
            } else {
                dec_r_inc_c = false;
            }
        }
        if (dec_r_c) {
            if ((decd_r > 0) && (decd_c > 0)) {
                done = false;
                valid_squares += find_obstacle(dec_r_c, decd_r, decd_c, my_obstacles);
            } else {
                dec_r_c = false;
            }
        }
    }

    return valid_squares;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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