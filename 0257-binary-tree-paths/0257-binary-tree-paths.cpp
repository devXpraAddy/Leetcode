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
private:
    void solve(TreeNode* root, string path, vector<string>&res){
        if(root->left == NULL && root->right == NULL){
            res.push_back(path);
            return;
        }
        if(root->left != NULL){
            solve(root->left, path+ "->"+to_string(root->left->val), res);
        }
        if(root->right != NULL){
            solve(root->right, path+ "->"+to_string(root->right->val), res);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string path = to_string(root->val);
        solve(root, path, res);
        return res;
    }
};