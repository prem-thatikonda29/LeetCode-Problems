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
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode * n = q.front();
                q.pop();

                if(n->left == NULL && n->right == NULL) return depth;

                if(n->left != NULL) q.push(n->left);
                if(n->right != NULL) q.push(n->right);
            }

            depth++;
        }

        return depth;
    }
};