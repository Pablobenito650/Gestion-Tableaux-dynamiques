#include <iostream>

#include "ScoreBoard.h"

void Actions(ScoreBoard& _scoreBoard, bool& _play);

int main(int argc, char** argv)
{
    ScoreBoard _scoreBoard;
    bool _play = true;

    _scoreBoard.DisplayTab();

    while(_play)
    {
        Actions(_scoreBoard, _play);
    }

    return 0;
}

void Actions(ScoreBoard& _scoreBoard, bool& _play)
{
    int _option;
    std::cin >> _option;

    if(_option == 1)
    {
        _scoreBoard.RedimTab();
    }
    else if(_option == 2)
    {
        _scoreBoard.AddScore();
    }
    else if(_option == 3)
    {
        _scoreBoard.RemoveScore();
    }
    else
    {
        _play = false;
        system("exit");
    }

    _scoreBoard.DisplayTab();
}