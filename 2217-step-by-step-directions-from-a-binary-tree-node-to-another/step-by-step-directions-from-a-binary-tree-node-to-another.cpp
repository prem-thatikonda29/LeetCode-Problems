class Solution {
public:
    bool findPath(TreeNode* root, int value, string& path) {
        if (!root) return false;
        if (root->val == value) return true;
        path.push_back('L');
        if (findPath(root->left, value, path)) return true;
        path.pop_back();
        path.push_back('R');
        if (findPath(root->right, value, path)) return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        findPath(root, startValue, pathToStart);
        findPath(root, destValue, pathToDest);

        int commonLength = 0;
        while (commonLength < pathToStart.size() && commonLength < pathToDest.size() && pathToStart[commonLength] == pathToDest[commonLength]) {
            commonLength++;
        }

        string pathUp = string(pathToStart.size() - commonLength, 'U');
        string pathDown = pathToDest.substr(commonLength);

        return pathUp + pathDown;
    }
};