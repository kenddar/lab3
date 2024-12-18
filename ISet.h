#ifndef TRAINING_SFML_ISET_H
#define TRAINING_SFML_ISET_H
#include <iostream>
#include <unordered_set>

template <typename T>
class ISet {
private:
    std::unordered_set<T> data;

public:
    ISet() {}

    ISet(const std::unordered_set<T>& initialData) : data(initialData) {}

    void insert(const T& element) {
        data.insert(element);
        std::cout << "Inserted: " << element << std::endl;
    }

    bool contains(const T& element) const {
        bool result = data.find(element) != data.end();
        std::cout << "Contains " << element << ": " << (result ? "true" : "false") << std::endl;
        return result;
    }

    void remove(const T& element) {
        data.erase(element);
        std::cout << "Removed: " << element << std::endl;
    }

    void printState() const {
        std::cout << "ISet state: { ";
        for (const auto& element : data) {
            std::cout << element << " ";
        }
        std::cout << "}" << std::endl;
    }
};
#endif //TRAINING_SFML_ISET_H
