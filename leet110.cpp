class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        return abs(height(root->left) - height(root->right)) <= 1
            && isBalanced(root->left) && isBalanced(root->right);

		// return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
    }
    int height(TreeNode* root){
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
    bool isBalanced(TreeNode* root, int& depth){
        if (!root){
            depth = 0;
            return true;
        }
        int l, r;
        if (isBalanced(root->left, l) && isBalanced(root->right, r)){
            if (abs(l - r) <= 1){
                depth = 1 + max(l, r);
                return true;
            }
        }
        return false;
    }
};

#출처 : https://leetcode.com/problems/balanced-binary-tree/discuss/577388/leetcode-110-c-booksun
