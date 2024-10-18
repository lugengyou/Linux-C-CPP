/*
 * @Author: gengyou.lu 1770591868@qq.com
 * @Date: 2024-10-18 20:09:54
 * @FilePath: /leetcode/binary_search_tree.cc
 * @LastEditTime: 2024-10-18 22:52:07
 * @Description: 平衡二叉搜索树用例，华为机考1：求给定范围内叶子节点的和
 */
/*
1、满足查询范围的平衡树数据之和
数据库索引技术使用平衡树从树根到叶子节点的高度基本一致的特点，将数据保存到叶子节点
从而可以实现从树根查找到叶子遍历的节点数基本致，使查询速度更加稳定
给定一个数组，经过升序排列后，构造平衡二叉树，查询平衡二叉树满足条件的叶子节点的数据之和。
平衡二叉树的定义和约束如下:
a)每个节点的左右子树的高度差的绝对值不超过1
b)左右子树也是平衡二叉树
d)递增排序后构造的平衡二叉树是唯一的

解答要求
时间限制:C/C++1000ms,其他语言: 2000ms
内存限制:C/C++256MB,其他语言:512MB

输入
第一行：一个数组，第一个数据是节点数，范围是[1,5000]，后面跟的是树的节点值，范围是[1.20000]。
第二行：平衡树叶子节点值的查询范围，包含3个数，第一个数是个数，第二个数和第三个数分别是最小值和最大值。

输出
满足查询范围的叶节点的数据之和，如果找 到满足查询条件的叶节点，则输出叶节点的最大值，其他情况返回-1。

样例1
复制输入：
6 7 17 35 56 65 66
2 56 67
输出：
122
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

void sumOfLeafInRange(TreeNode* root, int min_val, int max_val, int& sum) {
    if (root == nullptr) {
        return;
    }

    // 中序遍历
    if (root->left == nullptr && root->right == nullptr) {
        // 叶子节点，判断是否在范围内
        if (root->val >= min_val && root->val <= max_val) {
            sum += root->val;
        }
    }

    // 左
    sumOfLeafInRange(root->left, min_val, max_val, sum);
    // 右
    sumOfLeafInRange(root->right, min_val, max_val, sum);
}


int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int count, min_val, max_val;
    cin >> count >> min_val >> max_val;

    // build binary search tree
    sort(nums.begin(), nums.end());
    int max_num = nums[n - 1];

    TreeNode* root = buildBST(nums, 0, n - 1);

    int sum = 0;
    sumOfLeafInRange(root, min_val, max_val, sum);

    if (sum == 0) {
        cout << max_num << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}



