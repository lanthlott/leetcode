* struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution{
public:
    bool isBalanced(TreeNode* root)
    {
        if(!root) return true;
        int result = DFS(root->left) - DFS(root->right);
        if(abs(result) > 1) return false;
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        return left && right;
    }

private:
    int DFS(TreeNode* root)
    {
        if(root)
        {
            int left = DFS(root->left);
            int right = DFS(root->right);
            return max(left, right) + 1;
        }
        return 0;
    }
};