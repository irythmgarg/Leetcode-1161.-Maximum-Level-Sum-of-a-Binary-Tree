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
    int maxans = INT_MIN;  // Holds the maximum sum encountered at any level
    int mainans = 0;       // Stores the level number (1-indexed) where max sum occurred

    /**
     * Helper function to compute the maximum sum at any level of the binary tree.
     * Performs level-order traversal (BFS) and computes the sum of nodes at each level.
     * 
     * @param root - Reference to the root node of the binary tree
     */
    void maxsum(TreeNode*& root) {
        if (!root) return; // Edge case: if tree is empty, no processing needed

        queue<TreeNode*> q;
        q.push(root);  // Start BFS from the root
        int level = 1; // Level counter (1-indexed)

        // BFS traversal
        while (!q.empty()) {
            int n = q.size(); // Number of nodes at current level
            int ans = 0;      // Sum of node values at current level

            // Process all nodes at this level
            while (n--) {
                TreeNode* top = q.front();
                q.pop();
                ans += top->val;

                // Add child nodes to the queue for the next level
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }

            // Update max sum and corresponding level if current level sum is higher
            if (ans > maxans) {
                maxans = ans;
                mainans = level;
            }

            level++; // Move to the next level
        }
    }

    /**
     * Returns the level number (1-indexed) of the binary tree which has the maximum sum.
     *
     * @param root - Pointer to the root of the binary tree
     * @return int - Level number with the maximum sum
     */
    int maxLevelSum(TreeNode* root) {
        maxsum(root); // Perform BFS and compute level-wise sums
        return mainans; // Return the level with the maximum sum
    }
};
