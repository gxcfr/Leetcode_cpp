class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        }     
        else {
            int leftmax = maxDepth(root->left);
            int rightmax = maxDepth(root->right);
            return max(leftmax, rightmax) + 1;
        }
    }
};