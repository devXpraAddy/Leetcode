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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        if(root == NULL) return res;
        st.push(root);


        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);

            if(node->right != NULL) st.push(node->right); // as we are using stack we push right first then left
            if(node->left != NULL) st.push(node->left);

        }
        return res;
    }
};

