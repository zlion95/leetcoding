#include <iostream>
#include <stdlib.h>

using namespace std;

struct block_t {
    char c;
    bool is_multi;
    struct block_t *next;
};

class Solution {
public:
    void filter_pattern(string p, struct block_t *phead) {
        if (p.size() == 0) return;
        int last = p[0];
        bool is_multi = false;
        struct block_t *b;
        for (int i = 1; i < p.size(); ++i) {
            if (p[i] == '*') {
                is_multi = true;
            } else if (p[i] != '*') {
                if (!(last == phead->c && is_multi && phead->is_multi)) {
                    b = (struct block_t *) malloc(sizeof(block_t));
                    b->c = last;
                    b->is_multi = is_multi;
                    b->next = NULL;
                    phead->next = b;
                    phead = b;
                }

                is_multi = false;
                last = p[i];
            }
        }
        if (!(last == phead->c && is_multi && phead->is_multi)) {
            b = (struct block_t *) malloc(sizeof(block_t));
            b->c = last;
            b->is_multi = is_multi;
            b->next = NULL;
            phead->next = b;
            phead = b;
        }
    }

    bool is_multi(string p, int pi) {
        if (pi + 1 == p.size())
            return false;
        if (p[pi + 1] == '*')
            return true;
        return false;
    }

    bool match(string s, string p, int si, int pi)
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
        struct block_t head = {
            c : '\0',
            is_multi : false,
            next : NULL
        };
        struct block_t *pblock, *temp;
        string newp = "";

        filter_pattern(p, &head);

        for (pblock = head.next; pblock != NULL;) {
            newp += pblock->c;
            if (pblock->is_multi) newp += '*';
            temp = pblock;
            pblock = pblock->next;
            free(temp);
            cout << "???" << endl;
        }

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
