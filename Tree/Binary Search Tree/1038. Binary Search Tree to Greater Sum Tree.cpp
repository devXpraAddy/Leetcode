// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25

// Simple recursive approach
// T.C : O(n)
// S.C : O(1)
class Solution
{
public:
    void solve(TreeNode *root, int &sum)
    {
        if (!root)
        { // root == NULL
            return;
        }

        solve(root->right, sum); // RIGHT is covered

        sum += root->val;

        root->val = sum;

        solve(root->left, sum); // Covergin the left
    }

    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;

        solve(root, sum);

        return root;
    }
};
