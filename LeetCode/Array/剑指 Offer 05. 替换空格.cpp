// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int oldsize = s.length();
        int blankcount = 0;
        for (auto c : s) {
            if (c == ' ') ++blankcount;
        }
        // if (blankcount == 0) return s;
        int newsize = oldsize + 2 * blankcount;
        s.resize(newsize);
        for (int i = oldsize-1, j = newsize-1; i >= 0; --i, --j) {
            if (s[i] == ' ') {
                s[j] = '0';
                s[--j] = '2';
                s[--j] = '%';
            } else {
                s[j] = s[i];
            }
        }
        return s;
    }
};