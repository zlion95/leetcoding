#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        //for 1000
        while (s[0] == 'M') {
            value += 1000;
            s = s.substr(1, s.size() - 1);
        }
        //for 100
        if (s[0] == 'C') {
            if (s[1] == 'M') {
                value += 900;
                s = s.substr(2, s.size() - 2);
            } else if (s[1] == 'D') {
                value += 400;
                s = s.substr(2, s.size() - 2);
            } else {
                while (s[0] == 'C') {
                    value += 100;
                    s = s.substr(1, s.size() - 1);
                }
            }
        } else if (s[0] == 'D') {
            value += 500;
            s = s.substr(1, s.size() - 1);
            while (s[0] == 'C') {
                value += 100;
                s = s.substr(1, s.size() - 1);
            }
        }

        //for 10
        if (s[0] == 'X') {
            if (s[1] == 'C') {
                value += 90;
                s = s.substr(2, s.size() - 2);
            } else if (s[1] == 'L') {
                value += 40;
                s = s.substr(2, s.size() - 2);
            } else {
                while (s[0] == 'X') {
                    value += 10;
                    s = s.substr(1, s.size() - 1);
                }
            }
        } else if (s[0] == 'L') {
            value += 50;
            s = s.substr(1, s.size() - 1);
            while (s[0] == 'X') {
                value += 10;
                s = s.substr(1, s.size() - 1);
            }
        }
        //for 1
        if (s[0] == 'I') {
            if (s[1] == 'X') {
                value += 9;
                s = s.substr(2, s.size() - 2);
            } else if (s[1] == 'V') {
                value += 4;
                s = s.substr(2, s.size() - 2);
            } else {
                while (s[0] == 'I') {
                    value += 1;
                    s = s.substr(1, s.size() - 1);
                }
            }
        } else if (s[0] == 'V') {
            value += 5;
            s = s.substr(1, s.size() - 1);
            while (s[0] == 'I') {
                value += 1;
                s = s.substr(1, s.size() - 1);
            }
        }
        return value;
    }
};


int main(int argc, char **argv) {
    Solution s;
    string str;
    cin >> str;
    cout << s.romanToInt(str) << endl;
}
