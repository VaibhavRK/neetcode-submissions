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
    // void inverse(TreeNode* root){
    //     if(root == NULL) return;

    //     inverse(root->left);
    //     inverse(root->right);

    //     TreeNode* dummy = root->left;
    //     root->left = root->right;
    //     root->right = dummy;
    // }

    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL;

        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);

        root->right = left;
        root->left = right;

        if(left) cout<<"left: "<<left->val<<endl;
        if(right) cout<<"right: "<<right->val<<endl;
        return root;
    }
};
