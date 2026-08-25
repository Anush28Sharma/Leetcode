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
    int levels(TreeNode* root)
    {
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }

    void printlevel(TreeNode* root, int currlevel, int reqlevel, vector<int>&level){
         if(root==NULL) return ;
        
         if(currlevel==reqlevel){
         level.push_back(root->val);
           
         }
         
         printlevel(root->left,currlevel+1, reqlevel, level);
         printlevel(root->right,currlevel+1, reqlevel, level);
         return;
         
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>>ans;
        for(int i = 0;i<levels(root);i++)
        {
         vector<int>level;
            printlevel(root,0,i,level);
        ans.push_back(level);
        }
        return ans;
        
    }
};