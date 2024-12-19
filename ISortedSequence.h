#ifndef TRAINING_SFML_ISORTEDSEQUENCE_H
#define TRAINING_SFML_ISORTEDSEQUENCE_H
#include <iostream>
#include "vector"
#include "ReadBlackTree.h"


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
