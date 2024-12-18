#ifndef TRAINING_SFML_TESTS_ISORTEDSEQUENCE_H
#define TRAINING_SFML_TESTS_ISORTEDSEQUENCE_H
#include "../ISortedSequence.h"
#include <cassert>


int test_red_black_tree_default_constructor_int() {
    RedBlackTree<int> tree;
    assert(tree.GetSequence().empty());

    std::cout << "Test passed: test_red_black_tree_default_constructor_int\n";
    return 1;
}

int test_red_black_tree_add_int() {
    RedBlackTree<int> tree;
    tree.Add(3);
    tree.Add(1);
    tree.Add(5);
    tree.Add(2);
    tree.Add(4);

    std::vector<int> expected = {1, 2, 3, 4, 5};
    assert(tree.GetSequence() == expected);

    std::cout << "Test passed: test_red_black_tree_add_int\n";
    return 1;
}

int test_sorted_sequence_default_constructor_int() {
    ISortedSequence<int> sequence;
    assert(sequence.GetIsEmpty());
    assert(sequence.GetLength() == 0);

    std::cout << "Test passed: test_sorted_sequence_default_constructor_int\n";
    return 1;
}

int test_sorted_sequence_add_int() {
    ISortedSequence<int> sequence;
    sequence.Add(3);
    sequence.Add(1);
    sequence.Add(5);
    sequence.Add(2);
    sequence.Add(4);

    std::vector<int> expected = {1, 2, 3, 4, 5};
    assert(sequence.GetSequence() == expected);

    std::cout << "Test passed: test_sorted_sequence_add_int\n";
    return 1;
}

int test_sorted_sequence_get_first_int() {
    ISortedSequence<int> sequence;
    sequence.Add(3);
    sequence.Add(1);
    sequence.Add(5);

    assert(sequence.GetFirst() == 1);

    std::cout << "Test passed: test_sorted_sequence_get_first_int\n";
    return 1;
}

int test_sorted_sequence_get_last_int() {
    ISortedSequence<int> sequence;
    sequence.Add(3);
    sequence.Add(1);
    sequence.Add(5);
    sequence.Add(4);

    assert(sequence.GetLast() == 5);

    std::cout << "Test passed: test_sorted_sequence_get_last_int\n";
    return 1;
}

int test_sorted_sequence_index_of_int() {
    ISortedSequence<int> sequence;
    sequence.Add(3);
    sequence.Add(1);
    sequence.Add(5);

    assert(sequence.IndexOf(1) == 0);
    assert(sequence.IndexOf(5) == 2);
    //не был добавлен
    assert(sequence.IndexOf(2) == -1);

    std::cout << "Test passed: test_sorted_sequence_index_of_int\n";
    return 1;
}

int test_sorted_sequence_get_subsequence_int() {
    ISortedSequence<int> sequence;
    sequence.Add(3);
    sequence.Add(1);
    sequence.Add(5);
    sequence.Add(2);
    sequence.Add(4);

    ISortedSequence<int> subsequence = sequence.GetSubsequence(1, 3);

    std::vector<int> expected = {2, 3, 4};
    assert(subsequence.GetSequence() == expected);

    std::cout << "Test passed: test_sorted_sequence_get_subsequence_int\n";
    return 1;
}

void test_sorted_sequence() {
    int total_tests = 6;
    int passed_tests = test_sorted_sequence_default_constructor_int() +
                       test_sorted_sequence_add_int() +
                       test_sorted_sequence_get_first_int() +
                       test_sorted_sequence_get_last_int() +
                       test_sorted_sequence_index_of_int() +
                       test_sorted_sequence_get_subsequence_int();

    int failed_tests = total_tests - passed_tests;
    std::cout << "_____________________________________________________________\n";
    std::cout << "Total ISortedSequence tests: " << total_tests << ", Passed: " << passed_tests << ", Failed: " << failed_tests << std::endl;
    std::cout << "_____________________________________________________________\n";
}

void test_red_black_tree() {
    int total_tests = 2;
    int passed_tests = test_red_black_tree_default_constructor_int() +
                       test_red_black_tree_add_int();

    int failed_tests = total_tests - passed_tests;
    std::cout << "_____________________________________________________________\n";
    std::cout << "Total Red-Black Tree tests: " << total_tests << ", Passed: " << passed_tests << ", Failed: " << failed_tests << std::endl;
    std::cout << "_____________________________________________________________\n";
}



#endif //TRAINING_SFML_TESTS_ISORTEDSEQUENCE_H
