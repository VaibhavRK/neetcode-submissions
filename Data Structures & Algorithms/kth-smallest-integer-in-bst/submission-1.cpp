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
    void inorder(TreeNode* root, vector<int>& ans){
        if(!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        // inorder(root, ans);
        inorder(root->right, ans);

    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        // inorder(root, ans);

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty()) {
        
        // Go as far left as possible
        // Corrected condition: while curr is NOT null
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // Process the current node
        curr = st.top();
        st.pop();
        
        // Decrement k, if it hits 0, we found our k-th smallest element
        k--;
        if (k == 0) {
            return curr->val;
        }

        // Move to the right child
        curr = curr->right;
        }


        return -1;
    }
};
