// Copyright 2024 Vladislav Labutin

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <map>
#include <string>
#include <iostream>

enum STATE { OFF, WAIT, ACCEPT, CHECK, COOK };

class Automata {
 private:
    int cash;
    std::map<std::string, int> menu;
    STATE state;
    std::string coffee;
 public:
    Automata();
    void on();
    void off();
    void coin(int value);
    void choice(std::string value);
    void cancel();
    bool check();
    void cook();
    void finish();
    int getCash();
    void getMenu();
    STATE getState();
};

#endif  // INCLUDE_AUTOMATA_H_
