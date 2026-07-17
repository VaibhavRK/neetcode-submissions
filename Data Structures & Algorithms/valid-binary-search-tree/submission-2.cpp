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

    bool checkTree(TreeNode* root, int lt, int rt){
        if(!root) return true;


        if(root->val <= lt || root->val >= rt) return false;

        return checkTree(root->left, lt, min(rt, root->val)) && checkTree(root->right, max(lt, root->val), rt);
    }

    bool isValidBST(TreeNode* root) {
        return checkTree(root, INT_MIN, INT_MAX);
    }
};
