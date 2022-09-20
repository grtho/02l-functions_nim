//
// Created by Griffin Thompson on 9/19/22.
//

#ifndef INC_02L_FUNCTIONS_NIM_MAIN_HPP
#define INC_02L_FUNCTIONS_NIM_MAIN_HPP

enum TurnType {
    User,
    Computer
};

enum GameOutcome {
    Won,
    Lost,
    InProgress
};

int takeAmount();

bool isValidMove(int userMove, int stones);
bool checkDone(int stones, TurnType type, GameOutcome& outcome);
void computerMove(int& stones);
void playMatch();

#endif //INC_02L_FUNCTIONS_NIM_MAIN_HPP
