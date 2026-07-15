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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> queue;
        if(root)
            queue.push(root);

        vector<vector<int>> ans;

        while(!queue.empty()){
            vector<int> temp;
            int sz = queue.size();
            while(sz--){
                temp.push_back(queue.front()->val);
                if(queue.front()->left)
                    queue.push(queue.front()->left);
                if(queue.front()->right)
                    queue.push(queue.front()->right);
                queue.pop();
            }

            ans.push_back(temp);
        }
        
        return ans;
    }
};
