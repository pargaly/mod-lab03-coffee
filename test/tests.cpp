// Copyright 2024 Vladislav Labutin

#include <gtest/gtest.h>
#include "../include/Automata.h"

TEST(test, on) {
    Automata cof;
    cof.on();
    EXPECT_EQ(STATE::WAIT, cof.getState());
}

TEST(test, off) {
    Automata cof;
    cof.on();
    cof.off();
    EXPECT_EQ(STATE::OFF, cof.getState());
}

TEST(test, coin) {
    Automata cof;
    cof.on();
    cof.coin(20);
    EXPECT_EQ(STATE::ACCEPT, cof.getState());
}

TEST(test, twocoins) {
    Automata cof;
    cof.on();
    cof.coin(20);
    cof.coin(100);
    EXPECT_EQ(120, cof.getCash());
}

TEST(test, badchoice) {
    Automata cof;
    cof.on();
    cof.coin(140);
    cof.choice("Cappuccino");
    EXPECT_EQ(false, cof.check());
}

TEST(test, goodchoice) {
    Automata cof;
    cof.on();
    cof.coin(140);
    cof.choice("Latte");
    EXPECT_EQ(true, cof.check());
}

TEST(test, cancel) {
    Automata cof;
    cof.on();
    cof.coin(200);
    cof.cancel();
    EXPECT_EQ(STATE::WAIT, cof.getState());
}

TEST(test, cook) {
    Automata cof;
    cof.on();
    cof.coin(140);
    cof.choice("Latte");
    cof.cook();
    EXPECT_EQ(STATE::COOK, cof.getState());
}

TEST(test, finish) {
    Automata cof;
    cof.on();
    cof.coin(140);
    cof.choice("Latte");
    cof.cook();
    cof.finish();
    EXPECT_EQ(STATE::WAIT, cof.getState());
}

TEST(test, twochoices) {
    Automata cof;
    cof.on();
    cof.coin(200);
    cof.choice("Latte");
    cof.cancel();
    cof.coin(200);
    cof.choice("Cappuccino");
    EXPECT_EQ(STATE::CHECK, cof.getState());
}
