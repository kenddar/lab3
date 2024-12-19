#include "Start_Game.h"
#include "menu.h"
#include "handlers.h"
#include "Tests/Summary_Tests.h"

int main() {
    int var_prog = 0;
    print_choose_prog();
    handlerInput(&var_prog, 1, 2);
    if(var_prog == 1)
        start_game();
    if(var_prog == 2)
        tests();

    return 0;
}
