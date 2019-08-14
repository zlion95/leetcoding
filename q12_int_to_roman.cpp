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

    void auto_reduce(int num, int seed, char *s) {
        int i = 0;
        char s1 = get1(seed), s5 = get5(seed), s10 = get1(seed + 1);

        if (num == 9) {
            s[0] = s1;
            s[1] = s10;
        } else if (num >= 5) {
            s[0] = s5;
            i = 1;
            while (num - 4 - i > 0) s[i++] = s1;
        } else if (num == 4) {
            s[0] = s1;
            s[1] = s5;
        } else {
            i = 0;
            while (num - i > 0) s[i++] = s1;
        }
    }

    string intToRoman(int num) {
        int n = 0, seed = 0;
        char cstr[5];
        string str = "";
        while (num != 0) {
            n = num % 10;
            memset(cstr, 0, sizeof(cstr));
            auto_reduce(n, seed, cstr);
            str = cstr + str;
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
