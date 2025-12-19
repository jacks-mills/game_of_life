#include <stdio.h>
#include "state.h"
#include "ui.h"

int main (int argc, char **argv) {

    struct State *s;
    state_alloc(&s);
    state_load(s, "#   \n    \n    \n    \n");

    ui_init(4, 4);

    while(1);
    return 0;
}
