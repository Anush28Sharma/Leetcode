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
    int maxdia = INT_MIN;
    int levels(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int lmax = levels(root->left);
        int rmax = levels(root->right);
        int dia = 0;
        dia = lmax+rmax;
        maxdia = max(maxdia,dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxdia;
    }
};