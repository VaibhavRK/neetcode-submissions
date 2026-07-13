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
    bool flg = true;
    int checkBalanced(TreeNode* root){
        if(!root) return 0;


        int lt = checkBalanced(root->left);
        int rt = checkBalanced(root->right);

        if(abs(lt-rt) > 1) flg = false;

        return max(lt,rt)+1;
    }

    bool isBalanced(TreeNode* root) {
        checkBalanced(root);

        return flg;
    }
};
