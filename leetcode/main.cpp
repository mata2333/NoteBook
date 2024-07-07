#include <iostream>

template<typename Type>
struct TreeNode {
    Type value;
    TreeNode* lchild, *rchild;
};

template<typename Type>
class BinaryTree {
private:
    TreeNode<Type> *root;
public:
    // explicit 无法进行隐式转换
    explicit BinaryTree(Type val) {
        root->value = val;
    }

};

int main() {

}
