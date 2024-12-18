#ifndef TRAINING_SFML_EXAMLPE_ISET_H
#define TRAINING_SFML_EXAMLPE_ISET_H
#include "../ISet.h"
void example_ISet_work(){
    ISet<int> intSet;

    intSet.insert(42);
    intSet.insert(10);
    intSet.insert(23);

    intSet.contains(42);
    intSet.contains(15);

    intSet.remove(10);

    intSet.contains(10);

    intSet.printState();
}

#endif //TRAINING_SFML_EXAMLPE_ISET_H
