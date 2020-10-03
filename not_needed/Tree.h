#ifndef INC_2_TREE_H
#define INC_2_TREE_H

#include <cstdlib>
#include <iostream>

template<typename T>
class Tree {
public:
    T data;
    Tree *left;
    Tree *right;

    Tree(T _data) : data(_data), left(nullptr), right(nullptr) {};
};

template<typename T>
void deleteTree(Tree<T> *tree) {
    if (tree != NULL) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}


template<typename T>
Tree<T> *addNode(Tree<T> *tree, T _data) {
    if (tree == nullptr) {
        tree = (Tree<T> *) std::malloc(sizeof(Tree<T>));
        tree->data = _data;
        tree->left = nullptr;
        tree->right = nullptr;
    } else if (tree->data > _data)
        tree->left = addNode(tree->left, _data);
    else
        tree->right = addNode(tree->right, _data);
    return tree;
}

Tree<std::string> *addNode(Tree<std::string> *tree, std::string _data) {
    tree = addNode<std::string>(tree, _data);
    return tree;
}

template<typename T>
void inorderPrint(Tree<T> *root) {
    if (root == nullptr)   // Базовый случай
    {
        return;
    }
    inorderPrint(root->left);
    std::cout << root->data << " ";
    inorderPrint(root->right);
}

template<typename T>
void givenLevelPrint(Tree<T> *root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        std::cout << root->data << " ";
    else if (level > 1) {
        givenLevelPrint(root->left, level - 1);
        givenLevelPrint(root->right, level - 1);
    }
}

template<typename T>
void levelOrderPrint(Tree<T> *root) {
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        givenLevelPrint(root, i);
}

template<typename T>
int height(Tree<T> *node) {
    if (node == NULL)
        return 0;
    else {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
            return (lheight + 1);
        else return (rheight + 1);
    }
}

template<typename T>
void BFS(Tree<T>* root)
{
    Queue<Tree<T>*> q(new ArraySeq<T>);
    if (root) {
        q.push(root);
        std::cout << root->data << " ";
    }
    while (!q.empty()) {
        Tree<T>* temp_node = *(q.front());
        q.pop();
        if (temp_node->left) {
            q.push(temp_node->left);
            std::cout << temp_node->left->data << " ";
        }
        if (temp_node->right) {
            q.push(temp_node->right);
            std::cout << temp_node->right->data << " ";
        }
    }
}

#endif //INC_2_TREE_H
