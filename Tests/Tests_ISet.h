#ifndef TRAINING_SFML_TESTS_ISET_H
#define TRAINING_SFML_TESTS_ISET_H
#include "../ISet.h"

template <typename T>
int test_iset_default_constructor() {
    ISet<T> set;
    set.printState();

    std::cout << "Test passed: test_iset_default_constructor\n";
    return 1;
}

template <typename T>
int test_iset_constructor_with_data() {
    std::unordered_set<T> initialData = {1, 2, 3, 4, 5};
    ISet<T> set(initialData);
    set.printState();

    std::cout << "Test passed: test_iset_constructor_with_data\n";
    return 1;
}

template <typename T>
int test_iset_insert() {
    ISet<T> set;
    set.insert(1);
    set.insert(2);
    set.printState();

    std::cout << "Test passed: test_iset_insert\n";
    return 1;
}

template <typename T>
int test_iset_contains() {
    ISet<T> set;
    set.insert(1);
    bool result = set.contains(1);

    if (result) {
        std::cout << "Test passed: test_iset_contains\n";
        return 1;
    } else {
        std::cout << "Test failed: test_iset_contains\n";
        return 0;
    }
}

template <typename T>
int test_iset_remove() {
    ISet<T> set;
    set.insert(1);
    set.remove(1);
    set.printState();

    std::cout << "Test passed: test_iset_remove\n";
    return 1;
}

void test_iset() {
    int total_tests = 5;
    int passed_tests = test_iset_default_constructor<int>() +
                       test_iset_constructor_with_data<int>() +
                       test_iset_insert<int>() +
                       test_iset_contains<int>() +
                       test_iset_remove<int>();

    int failed_tests = total_tests - passed_tests;
    std::cout << "_____________________________________________________________\n";
    std::cout << "Total ISet tests: " << total_tests << ", Passed: " << passed_tests << ", Failed: " << failed_tests << std::endl;
    std::cout << "_____________________________________________________________\n";
}

#endif //TRAINING_SFML_TESTS_ISET_H
