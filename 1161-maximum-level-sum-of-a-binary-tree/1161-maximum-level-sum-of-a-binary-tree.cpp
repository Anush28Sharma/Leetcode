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
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int ans= 1;
        int maxi = INT_MIN;
        queue<TreeNode*>q;

        q.push(root);
        while(q.size()>0)
        {
            int n = q.size();
            int sum = 0;
            while(n--)
            {
                TreeNode* curr = q.front();
                q.pop();
                sum+=curr->val;
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);

            }
            if(sum>maxi)
            {
                maxi = sum;
                ans = level;
            }
            level++;
        }
        return ans;
    }
};