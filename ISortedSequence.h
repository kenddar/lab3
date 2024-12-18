#ifndef TRAINING_SFML_ISORTEDSEQUENCE_H
#define TRAINING_SFML_ISORTEDSEQUENCE_H
#include <iostream>
#include "vector"

template <typename T>
class RedBlackTree {
private:
    enum class Color { Red, Black };

    struct Node {
        T data;
        Node* parent;
        Node* left;
        Node* right;
        Color color;

        Node(const T& value, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr, Color color = Color::Red)
                : data(value), parent(parent), left(left), right(right), color(color) {}
    };

    Node* root;

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;

        if (y->left != nullptr) {
            y->left->parent = x;
        }

        y->parent = x->parent;

        if (x->parent == nullptr) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }

        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;

        if (x->right != nullptr) {
            x->right->parent = y;
        }

        x->parent = y->parent;

        if (y->parent == nullptr) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }

        x->right = y;
        y->parent = x;
    }

    void insertFixup(Node* z) {
        while (z->parent != nullptr && z->parent->color == Color::Red) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;

                if (y != nullptr && y->color == Color::Red) {
                    z->parent->color = Color::Black;
                    y->color = Color::Black;
                    z->parent->parent->color = Color::Red;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }

                    z->parent->color = Color::Black;
                    z->parent->parent->color = Color::Red;
                    rightRotate(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;

                if (y != nullptr && y->color == Color::Red) {
                    z->parent->color = Color::Black;
                    y->color = Color::Black;
                    z->parent->parent->color = Color::Red;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        z = z->parent;
                        rightRotate(z);
                    }

                    z->parent->color = Color::Black;
                    z->parent->parent->color = Color::Red;
                    leftRotate(z->parent->parent);
                }
            }
        }

        root->color = Color::Black;
    }

    void insert(const T& value) {
        Node* z = new Node(value);
        Node* y = nullptr;
        Node* x = root;

        while (x != nullptr) {
            y = x;

            if (z->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        z->parent = y;

        if (y == nullptr) {
            root = z;
        } else if (z->data < y->data) {
            y->left = z;
        } else {
            y->right = z;
        }

        insertFixup(z);
    }

    void inOrderTraversal(Node* node, std::vector<T>& result) const {
        if (node != nullptr) {
            inOrderTraversal(node->left, result);
            result.push_back(node->data);
            inOrderTraversal(node->right, result);
        }
    }

public:
    RedBlackTree() : root(nullptr) {}

    void Add(const T& element) {
        insert(element);
    }

    std::vector<T> GetSequence() const {
        std::vector<T> result;
        inOrderTraversal(root, result);
        return result;
    }
};

template <typename T>
class ISortedSequence {
private:
    RedBlackTree<T> tree;

public:
    void Add(const T& element) {
        tree.Add(element);
    }

    int GetLength() const {
        return static_cast<int>(tree.GetSequence().size());
    }

    bool GetIsEmpty() const {
        return tree.GetSequence().empty();
    }

    T Get(int index) const {
        const auto& sequence = tree.GetSequence();
        if (index >= 0 && index < static_cast<int>(sequence.size())) {
            return sequence[index];
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    T GetFirst() const {
        const auto& sequence = tree.GetSequence();
        if (!sequence.empty()) {
            return sequence.front();
        } else {
            throw std::out_of_range("Sequence is empty");
        }
    }

    T GetLast() const {
        const auto& sequence = tree.GetSequence();
        if (!sequence.empty()) {
            return sequence.back();
        } else {
            throw std::out_of_range("Sequence is empty");
        }
    }

    int IndexOf(const T& element) const {
        const auto& sequence = tree.GetSequence();
        auto it = std::find(sequence.begin(), sequence.end(), element);
        if (it != sequence.end()) {
            return static_cast<int>(std::distance(sequence.begin(), it));
        } else {
            return -1;
        }
    }

    ISortedSequence<T> GetSubsequence(int startIndex, int endIndex) const {
        ISortedSequence<T> subsequence;

        const auto& sequence = tree.GetSequence();

        if (startIndex >= 0 && endIndex >= startIndex && endIndex < static_cast<int>(sequence.size())) {
            for (int i = startIndex; i <= endIndex; ++i) {
                subsequence.Add(sequence[i]);
            }
        } else {
            throw std::out_of_range("Invalid start or end index for subsequence");
        }

        return subsequence;
    }
    std::vector<T> GetSequence() const {
        return tree.GetSequence();
    }
};

#endif //TRAINING_SFML_ISORTEDSEQUENCE_H
