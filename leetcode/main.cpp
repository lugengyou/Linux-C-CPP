/*
 * @Author: lugy lugengyou@github.com
 * @Date: 2024-08-11 19:36:41
 * @FilePath: /debug_env/main.cpp
 * @LastEditTime: 2024-10-18 19:45:16
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildBST(vector<int>& nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }

    int mid = (left + right) / 2;

    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildBST(nums, left, mid - 1);
    root->right = buildBST(nums, mid + 1, right);

    return root;
}

void sumOfLeavesInRange(TreeNode* root, int low, int high, int& sum) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        if (root->val >= low && root->val <= high) {
            sum += root->val;
        }        
    }

    sumOfLeavesInRange(root->left, low, high, sum);
    sumOfLeavesInRange(root->right, low, high, sum);
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int max_val = nums[n - 1];

    int count, low, high;
    cin >> count >> low >> high;

    // build BST
    TreeNode* root = buildBST(nums, 0, n - 1);

    int sum = 0;
    sumOfLeavesInRange(root, low, high, sum);

    if (sum == 0) {
        cout << "0" << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}
