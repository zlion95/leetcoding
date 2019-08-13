#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    string filter_pattern(string &p) {
        string newp = "";
        char last = p[0];
        char newp_last = '\0';
        bool is_multi = false;

        if (p.size() == 0) return newp;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i] == '*') {
                is_multi = true;
            } else if (p[i] != '*') {
                if (!(last == newp_last && is_multi && newp[newp.size() - 1] == '*')) {
                    newp += last;
                    if (is_multi) newp += '*';
                    newp_last = last;
                }
                is_multi = false;
                last = p[i];
            }
        }
        if (!(last == newp_last && is_multi 
                && newp[newp.size() - 1] == '*')) {
            newp += last;
            if (is_multi) newp += '*';
        }
        return newp;
    }

    bool is_multi(string &p, int pi) {
        if (pi + 1 == p.size())
            return false;
        if (p[pi + 1] == '*')
            return true;
        return false;
    }

    bool match(string &s, string &p, int si, int pi)
    {
        if (si >= s.size() && pi >= p.size())
            return true;

        if (si >= s.size()) {
            if (is_multi(p, pi)) return match(s, p, si, pi + 2);
            else return false;
        }

        if (pi >= p.size()) {
            return false;
        }
        
        if (s[si] == p[pi] || p[pi] == '.') {
            if (is_multi(p, pi))
                return match(s, p, si + 1, pi)
                    || match(s, p, si + 1, pi + 2)
                    || match(s, p, si, pi + 2);
            return match(s, p, si + 1, pi + 1);
        } else {
            if (is_multi(p, pi))
                return match(s, p, si, pi + 2);
            return false;
        }
    }

    bool isMatch(string s, string p)
    {
        string newp = filter_pattern(p);

        cout << s << endl;
        cout << p << endl;
        cout << newp << endl;
        return match(s, newp, 0, 0);
    }
};


int main(int argc, char **argv)
{
    string pattern, str;
    Solution s;

    cin >> str;
    cin >> pattern;

    cout << s.isMatch(str, pattern) << endl;;
    return 0;
}
