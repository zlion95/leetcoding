#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//BF(Brute-Force): 大用例很容易超时
//时间复杂度：O(nm)
/*
class Solution {
public:
    int strStr(string &haystack, string needle) {
        if (!needle.size()) return 0;
        for (int j = 0; j < haystack.size(); ++j) {
            if (haystack[j] == needle[0]) {
                int i = 0;
                for (; i < needle.size(); ++i) {
                    if (haystack[j + i] != needle[i]) break;
                }
                if (i == needle.size()) return j;
            }
        }
        return -1;
    }
};
*/


#define SIZE 256	//字符集大小: 当前用例只用了ascii码
//BM(Boyer-Moore): 1977
//字符串搜索的思想：有模式串中不存在的字符，那么肯定不匹配，往后多移动几位，提高效率
//BM原理：坏字符规则，好后缀规则
//总体时间复杂度最好：O(n/m)【当一直没有匹配到好后缀，一直跳m步】 最差：O(n+m)
class Solution {
public:
    int strStr(string &haystack, string &needle)
	{
		return str_bm(haystack, needle);
	}

	int str_bm(string &s, string &t)
	{
		int n = s.size(), m = t.size();
		vector<int> bad(SIZE, -1), suffix;
		vector<bool> prefix;

		generate_bad(t, bad);				//初始化坏规则映射表
		generate_gs(t, m, suffix, prefix);		//初始化好规则隐射表

		int i = 0, j, move_bad, move_good;
		while (i < n-m+1) {//i代表的模式串t 与 s[i]~s[i+m-1] 范围的子串做比对
			for (j = m-1; j >= 0; --j) {
				if (s[i+j] != t[j]) break;//碰上了坏字符
			}
			if (j < 0) return i;
			move_bad = j - bad[static_cast<int>(s[i+j])];	//坏字符移动规则
			move_good = 0;
			if (j < m-1) move_good = move_by_gs(j, m, suffix, prefix); //只有当有好字符出现的时候，才计算好后缀移动
			i += max(move_bad, move_good);//取最大的移动
		}
		return -1;
	}
	
	int move_by_gs(const int j, const int m, const vector<int> &suffix, 
			const vector<bool> &prefix) {//j代表坏字符在模式串中的下标
		int k = m-1-j;//好后缀长度
		//case1: 找到最后出现的好后缀U等长的模式子串U*，获取移动到当前模式子串下标所需的移动步数
		if (suffix[k] != -1) return j - suffix[k] + 1;
		//case2: 没找到与好后缀U匹配的模式子串，需要在检查一下有没有存在U的后缀子串v，与模式串的前缀v*一致
		//Q: 这里为什么不是直接查看是否有匹配的后缀？
		//A：因为作为好后缀U的子集，却不能被涵盖到suffix[len(U)]里面。说明 除非v*前面没有字符这种情况【即v*是模式子串的前缀】，v*的前面一个字符必定与v的前面一个字符不同
		for (int r = j + 2; r < m; ++r) {
			if (prefix[m-r]) return r;
		}
		return m;//case3：没有匹配到好后缀串及其后缀子串，直接移动模式串长度大小
	}

	void generate_gs(const string &t, int m, vector<int> &suffix, vector<bool> &prefix)
	{
		suffix.assign(m, -1);
		prefix.assign(m, false);
		//BM算法的比较是从模式串结尾比对到开头，因此要找匹配的后缀，也需要从m-1开始，往前找匹配的suffix数组代表的是匹配长度
		//suffix[1] 代表t[m-1]与t[i]匹配上了，suffix[2]代表t[m-2]~t[m-1] 与 t[i-1]~t[i]这两部分子串匹配上了
		//prefix代表的含义是是否匹配到模式串开头了，即t[0]~t[i] 与 t[m-1-i]~t[m-1] 匹配上了
		//从0往m-2构造是为了保证 后出现的模式子串可以 覆盖前面的，保证始终用最大，最右的好字符来滑动
		for (int i = 0; i < m-1; ++i) {
			int j = i, k = 0;
			while (j >= 0 && t[j] == t[m-1-k]) {
				suffix[++k] = j--;
			}
			if (j == -1) prefix[k] = true;
		}
	}

	void generate_bad(const string &t, vector<int> &bad)//坏字符在模式串的位置只需要保留最右边的一个即可
	{													//因为模式字符串检查是从右到左比较，因此先访问最右侧的一个
		for (int i = 0; i < t.size(); ++i) {
			bad[static_cast<int>(t[i])] = i;//重复字符被覆盖，记录的是最后出现的该字符的位置
		}
	}
};

//KMP(Knuth-Morria-Pratt): 1974年构思，1977发表
//算法的核心在于构造 部分匹配表(Partial Match Table)，理解该pmt表的含义就能基本掌握KMP算法的思想
//时间复杂度：O(n+m)
/*
class Solution {
public:
    int strStr(string &haystack, string &needle) {
        if (!needle.size()) return 0;
        vector<int> next(needle.size(), 0);
        get_next(next, needle);
        int i=0, j=0;
        while (i < haystack.size() && j < int(needle.size())) {
            if (j == -1 || haystack[i] == needle[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
        }
        if (j == needle.size()) return i - j;
        return -1;
    }
    void get_next(vector<int> &next, string &t)
    {
       int j=0,k=-1;
       next[0]=-1;
       while (j < t.size() - 1)
       {
          if(k == -1 || t[j] == t[k]) next[++j] = ++k;
          else k = next[k];
       }
    }

};
*/

int main(int argc, char **argv)
{
	Solution s;
    string a = "abcacabcbcbacabc", b = "cbacabc";
    cout << a << "中第一次出现" << b << "的位置(从0开始)是：" << 
		s.strStr(a, b) << endl;
    return 0;
}
