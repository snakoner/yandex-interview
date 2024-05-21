#include <iostream>
#include <vector>
#include <queue>

struct treeNode {
    treeNode *left;
    treeNode *right;
    int value;

    treeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

treeNode *buildTreeFromVector(const std::vector<int>& v) {
    treeNode *root;
    treeNode *cur;

    if (v.empty())
        return nullptr;

    root = new treeNode(v[0]);
    cur = root;

    for (size_t i = 1; i < v.size(); ) {
        int value = v[i];
        if (cur->value == value) {
            cur = root;
            i++;
        } else if (cur->value > value) {
            if (cur->left == nullptr) {
                cur->left = new treeNode(value);
                cur = root;
                i++;
            } else {
                cur = cur->left;
            }
        } else {
            if (cur->right == nullptr) {
                cur->right = new treeNode(value);
                cur = root;
                i++;
            } else {
                cur = cur->right;
            }
        }
    }

    return root;
}

class Handler {
public:
    void init(treeNode *tree) {
        std::queue<std::pair<treeNode *,size_t>> q;

        q.push({tree, 0});

        while (!q.empty()) {
            auto p = q.front();

            q.pop();

            size_t level = p.second;
            treeNode *node = p.first;

            if (level_sum.size() <= level)
                level_sum.push_back(0);

            num_levels = level;
            level_sum[level] += node->value;


            if (node->left) {
                q.push({node->left, level + 1});
            }

            if (node->right) {
                q.push({node->right, level + 1});
            }

        }

        for (size_t i = 1; i < level_sum.size(); i++) {
            level_sum[i] += level_sum[i - 1];
        }
    }

    int sum(size_t level) {
        if (level > num_levels)
            return level_sum[num_levels];

        return level_sum[level];
    }
private:
    std::vector<int> level_sum;
    size_t num_levels;
};

void printTreePreorder(treeNode *tree) {
    if (tree == nullptr)
        return;

    printTreePreorder(tree->left);
    std::cout << tree->value << std::endl;
    printTreePreorder(tree->right);
}

//          3
//         / \
//        2   6
//       /     \
//      1       8
//

int main() {
    Handler h;
    treeNode *tree = buildTreeFromVector({3,2,6,1,8});
    h.init(tree);
    std::cout << h.sum(0) << std::endl;
    std::cout << h.sum(1) << std::endl;
    std::cout << h.sum(2) << std::endl;
    std::cout << h.sum(3) << std::endl;
    // printTreePreorder(tree);
}
