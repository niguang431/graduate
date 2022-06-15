// https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    // 深度优先遍历
    int maxDepth_depth(TreeNode* root) {
        if (root == nullptr) 
            return 0;
        return max(maxDepth_depth(root->right), maxDepth_depth(root->left)) +  1;
    }

    // 广度优先遍历
    int maxDepth_breadth(TreeNode* root) {
        if (root == nullptr) 
            return 0;
        
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            while(size != 0) {
                TreeNode *tmp = q.front();
                q.pop();
                if (!tmp->left) 
                    q.push(tmp->left);
                if (!tmp->right) 
                    q.push(tmp->right);
                --size;
            }
            ++ans;
        }
        return ans;
    }
};