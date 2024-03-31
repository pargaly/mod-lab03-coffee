#include "../include/Automata.h"

int main() {
    Automata cof;
    cof.on();
    cof.coin(50);
    cof.coin(110);
    cof.choice("Cappuccino");
    cof.check();
    cof.cook();
    cof.finish();
    cof.off();
}