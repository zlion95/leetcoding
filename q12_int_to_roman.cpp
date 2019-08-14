#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Solution {
public:
    char get1(int seed) {
        switch(seed) {
        case 0:
            return 'I';
        case 1:
            return 'X';
        case 2:
            return 'C';
        case 3:
            return 'M';
        default:
            return '\0';
        }
    }

    char get5(int seed) {
        switch(seed) {
        case 0:
            return 'V';
        case 1:
            return 'L';
        case 2:
            return 'D';
        default:
            return '\0';
        }
    }

    bool is3to4(char *s, int len, int seed) {
        char s1 = get1(seed);

        if (len < 3) return false;
        if (s[len - 3] == s1 && s[len - 2] == s1 && s[len - 1] == s1)
            return true;
        return false;
    }

    bool is4to5(char *s, int len, int seed) {
        char s1 = get1(seed), s5 = get5(seed);

        if (len < 2) return false;
        if (s[len - 2] == s1 && s[len - 1] == s5) return true;
        return false;
    }
    
    bool is8to9(char *s, int len, int seed) {
        char s1 = get1(seed), s5 = get5(seed);

        if (len < 4) return false;
        if (s[len - 4] == s5
                && s[len - 3] == s1
                && s[len - 2] == s1
                && s[len - 1] == s1)
            return true;
        return false;
    }

    string auto_reduce(int num, int seed) {
        int len = 0;
        char *s = (char *)malloc(sizeof(char) * 16);
        char s1 = get1(seed), s5 = get5(seed), s10 = get1(seed + 1);
        string str;
        memset(s, 0, sizeof(char) * 16);

        for(; num > 0; --num) {
            if (is8to9(s, len, seed)) {
                s[len - 4] = s1;
                s[len - 3] = s10;
                s[len - 2] = '\0';
            } else if (is3to4(s, len, seed)) {
                s[len - 3] = s1;
                s[len - 2] = s5;
                s[len - 1] = '\0';
            } else if (is4to5(s, len, seed)) {
                s[len - 2] = s5;
                s[len - 1] = '\0';
            } else {
                s[len] = s1;
                s[len + 1] = '\0';
            }
            len = strlen(s);
        }
        str = s;
        return str;
    }

    string intToRoman(int num) {
        int n = 0, seed = 0;
        string str = "";
        while (num != 0) {
            n = num % 10;
            str = auto_reduce(n, seed) + str;
            num /= 10;
            seed += 1;
        }
        return str;
    }
};


int main(int argc, char **argv) {
    Solution s;
    int num;

    cin >> num;
    cout << s.intToRoman(num) << endl;
}
