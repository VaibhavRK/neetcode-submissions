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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;

        if(root) q.push(root);

        vector<int> ans;

        while(!q.empty()){
            int sz = q.size();
            TreeNode* node = q.front();
            ans.push_back(node->val);

            while(sz--){
                if(q.front()->right)q.push(q.front()->right);
                if(q.front()->left) q.push(q.front()->left);
                q.pop();
            }
        }

        return ans;
    }
};
