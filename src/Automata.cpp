#include "../include/Automata.h"

Automata::Automata() {
    cash = 0;
    state = OFF;
    menu = {
        {"Latte", 140},
        {"Cappuccino", 150},
        {"Raf", 200},
        {"Tea", 110}
    };
}

void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        std::cout << "Turned on" << std::endl;
    } else {
        std::cout << "Can't do it now" << std::endl;
    }
}

void Automata::off() {
    if (state == WAIT) {
        state = OFF;
        std::cout << "Turned off" << std::endl;
    } else {
        std::cout << "Can't do it now" << std::endl;
    }
}

void Automata::coin(int value) {
    if (state == WAIT || state == ACCEPT) {
        state = ACCEPT;
        cash += value;
        std::cout << "Deposited " << cash << std::endl;
    } else {
        std::cout << "Can't do it now" << std::endl;
    }
}

void Automata::choice(std::string value) {
    if (state == ACCEPT) {
        coffee = value;
        state = CHECK;
    } else {
        std::cout << "Can't do it now" << std::endl;
    }
}

void Automata::cancel() {
    if (state == ACCEPT || state == CHECK) {
        cash = 0;
        state = WAIT;
        std::cout << "Operation canceled" << std::endl;
    } else {
        std::cout << "Can't do it now" << std::endl;
    }
}

bool Automata::check() {
    if (state == CHECK) {
        if (cash >= menu[coffee]) return true;
        std::cout << "Low money" << std::endl;
    } else {
        std::cout << "Can't do it now" << std::endl;
    }
    return false;
}

void Automata::cook() {
    if (state == CHECK) {
        if (!check()) return;
        cash -= menu[coffee];
        state = COOK;
        std::cout << "Cooking..." << std::endl;
    } else {
        std::cout << "Can't do it now" << std::endl;
    }
}

void Automata::finish() {
    if (state == COOK) {
        std::cout << "Your " << coffee << " done" << std::endl;
        std::cout << "Take " << cash << " back" << std::endl;
        cash = 0;
        state = WAIT;
    } else {
        std::cout << "Can't do it now" << std::endl;
    }
}

int Automata::getCash() {
    return cash;
}

void Automata::getMenu() {
    for (const auto& [name, price] : menu)
        std::cout << name << " - " << price << std::endl;
}

STATE Automata::getState() {
    return state;
}