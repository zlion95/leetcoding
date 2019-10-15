#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        char c, p;
        stack<char> sk;

        while (i < s.size()) {
            if (sk.empty()) {
                sk.push(s[i]);
            } else {
                c = sk.top();
                switch(c) {
                    case '[':
                        p = ']';
                        break;
                    case '{':
                        p = '}';
                        break;
                    case '(':
                        p = ')';
                        break;
                    default:
                        p = ' ';
                }
                if (p == s[i]) sk.pop();
                else sk.push(s[i]);
            }
            ++i;
        }
        if (sk.empty()) return true;
        return false;
    }
};

int main(int argc, char **argv) {
    Solution s;
    string str;

    while (getline(cin, str)) {
        cout << str << endl;
        cout << s.isValid(str) << endl;
    }
}
