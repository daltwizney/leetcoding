#include <unordered_set>

#include <unordered_map>
#include <queue>

#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:

    int _minDepthRecursive(TreeNode *root) {

        if (root == nullptr) {
            return INT_MAX;
        }

        int leftNodeMinDepth = _minDepthRecursive(root->left);
        int rightNodeMinDepth = _minDepthRecursive(root->right);

        if (leftNodeMinDepth == INT_MAX && rightNodeMinDepth == INT_MAX)
        {
            return 1;
        }

        return min(leftNodeMinDepth, rightNodeMinDepth) + 1;
    }

public:

    int minDepth(TreeNode* root) {
        
        if (root == nullptr)
        {
            return 0;
        }

        return _minDepthRecursive(root);
    }
};