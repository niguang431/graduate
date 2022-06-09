// https://leetcode.cn/problems/two-sum/
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // <target-nums[index], index>
        for(int i = 0; i < nums.size(); ++i) {
            auto it = map.find(nums[i]);
            if (it != map.end()) {
                return {i, it->second};
            } 
            map[target-nums[i]] = i;
        }
        return {};
    }
};