// https://leetcode.com/problems/path-sum-ii/description/

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
class Solution
{
public:
    void solve(TreeNode *root, int sum, int &targetSum, vector<int> &temp, vector<vector<int>> &result)
    {
        if (root == NULL)
            return;
        sum += root->val;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == targetSum)
            {
                result.push_back(temp);
            }
        }
        solve(root->left, sum, targetSum, temp, result);
        solve(root->right, sum, targetSum, temp, result);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> result;
        vector<int> temp;
        solve(root, 0, targetSum, temp, result);
        return result;
    }
};
