/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    int getMaxSum(TreeNode* root, int& mx){
        if(!root){
            return 0;
        }

        int lt = getMaxSum(root->left, mx);
        int rt = getMaxSum(root->right, mx);

        mx = max(mx, lt + root->val + rt);

        return max(0, max(lt+root->val,rt+root->val));
    }

    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        getMaxSum(root, mx);

        return mx;
    }
};
