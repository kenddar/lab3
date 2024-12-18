#include "Start_Game.h"
#include "menu.h"
#include "handlers.h"
#include "Tests/Summary_Tests.h"
#include "Examples/Examlpe_ISet.h"

int main() {
    int var_prog = 0;
    print_choose_prog();
    handlerInput(&var_prog, 1, 3);
    if(var_prog == 1)
        start_game();
    else if(var_prog == 2)
        tests();
    else {
        cout << "_____________________________________________________________\n";
        cout << "ISET WORK\n\n";
        example_ISet_work();
        cout << "_____________________________________________________________\n";
        cout << "IPRIORITYQUEUE WORK\n\n";
        cout << "_____________________________________________________________\n";
    }
    return 0;
}
