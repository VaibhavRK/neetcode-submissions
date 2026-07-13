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
    int diameter(TreeNode* root, int& d){
        if(root == NULL) return 0;

        int lt = diameter(root->left,d);
        int rt = diameter(root->right,d);

        cout<<root->val<<" "<<lt<<" "<<rt<<endl;
        d = max(d, lt + rt);
        return max(lt, rt)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        int x = diameter(root, d);
        return d;
    }
};
