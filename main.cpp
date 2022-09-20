#include <iostream>
#include <iomanip>
#include <exception>
#include <random>
#include "main.hpp"

using std::cout, std::cin, std::endl;


int main() {
    playMatch();
}

void playMatch() {
    bool gameDone = false;
    auto outcome = GameOutcome::InProgress;
    int stones = 16;

    while (!gameDone) {
        auto turnType = TurnType::User;

        cout << "Stones in the pile: " << std::fixed << std::setw(2) << stones << endl;
        int take = takeAmount();
        stones -= take;

        gameDone = checkDone(stones,turnType, outcome);

        if (gameDone)
            continue;

        turnType = TurnType::Computer;

        computerMove(stones);

        gameDone = checkDone(stones, turnType, outcome);

    }

    if (outcome == Won)
        cout << "You win!" << endl;
    else
        cout << "You lost." << endl;
}

int takeAmount() {
    while(true) {
        std::string takestr;
        int take = 0xABBA;

        cout << "How many will you take? ";

        try {
            cin >> takestr;
            take = std::stoi(takestr);
            if (take <= 0 || take > 3) {
                cout << "Your input must be between 1 and 3, inclusive. Please try again." << endl;
                continue;
            }

            return take;

        } catch(std::exception& e) {
            cout << "Something was incorrect about your input. Please try again." << endl;

        }
    }
}

bool checkDone(int stones, TurnType type, GameOutcome& outcome) {
    if (stones != 0)
    {
        outcome = GameOutcome::InProgress;
        return false;
    }

    switch (type)
    {
        case TurnType::User:
            outcome = GameOutcome::Lost;
            return true;
        case TurnType::Computer:
            outcome = GameOutcome::Won;
            return true;
    }
}

void computerMove(int& stones) {
    if (stones == 1 || stones == 2) {
        stones -= 1;
        cout << "Computer takes 1" << endl;
    }
    else if (stones == 3) {
        stones -= 2;
        cout << "Computer takes 2" << endl;
    }
    else if (stones == 4) {
        stones -= 3;
        cout << "Computer takes 3" << endl;
    }
    else {
        std::random_device r;

        std::default_random_engine rand(r());
        std::uniform_int_distribution<int> uniformDist(1, 3);

        int takeAmt = uniformDist(rand);

        stones -= takeAmt;

        cout << "Computer takes " << takeAmt << endl;
    }
}

