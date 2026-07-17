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
    void countGood(TreeNode* node, int mx, int& count){
        if(node == NULL) return;

        if(mx <= node->val) count++;
        mx = max(mx, node->val);

        countGood(node->left, mx, count);
        countGood(node->right, mx, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        countGood(root, INT_MIN, count);

        return count;
    }
};
