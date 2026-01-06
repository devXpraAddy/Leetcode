/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {                 //implimented with BFS we can also use DFS but due to Queue
    public int maxLevelSum(TreeNode root) {          //BFS is faster than DFS
        if (root == null)
            return 0;

        int maxLevel = 0;
        int maxSum = Integer.MIN_VALUE;
        int level = 1;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            int currentSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                currentSum += node.val;

                if (node.left != null)
                    queue.offer(node.left);

                if (node.right != null)
                    queue.offer(node.right);
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                maxLevel = level;
            }

            level++;
        }

        return maxLevel;
    }
}
