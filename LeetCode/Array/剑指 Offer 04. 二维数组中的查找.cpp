// https://leetcode.cn/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
#include <vector>

using namespace std;
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int> >& matrix, int target) {
        int found = false;
        if (matrix.size() > 0 && matrix[0].size() > 0) {
            int row = 0;
            int col = matrix[0].size() - 1;
            while(row < matrix.size() && col >= 0) {
                int n = matrix[row][col];
                if (n == target) {
                    found = true;
                    break;
                } else if (n < target) {
                    ++row;
                } else {
                    --col;
                }
            }
        }
        return found;
    }
};