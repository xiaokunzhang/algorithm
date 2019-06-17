class Solution {
public:
    int helper(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) 
{
    if (!root) {
        return 0;
    }
    
    int cnt = 0;
    if (root == p || root == q) {
        cnt++;
    }
    cnt += helper(root->left, p, q, ans) + helper(root->right, p, q, ans);
    if (cnt == 2) {
        ans = root;
        cnt = 0;
    }
    
    return cnt;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode *ans;
    helper(root, p, q, ans);
    return ans;
}
};