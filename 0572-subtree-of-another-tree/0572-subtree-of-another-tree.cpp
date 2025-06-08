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
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root == NULL && subRoot == NULL){
            return true;
        }
        if(root == NULL || subRoot == NULL || root->val != subRoot->val){
            return false;
        }
        bool left = isSame(root->left, subRoot->left);
        bool right = isSame(root->right, subRoot->right);
        return left && right;
    }
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(root == NULL) return false;

        if(root->val == subRoot->val && isSame(root, subRoot)){
            return true;
        }
        bool left = solve(root->left, subRoot);
        bool right = solve(root->right, subRoot);
        return left || right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};
