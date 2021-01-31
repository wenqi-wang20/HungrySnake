#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

class Controller
{
public:
    Controller() : speed(200), key(1), score(0) {}
    void Start();
    void Select();
    void DrawGame();
    int PlayGame();
    void UpdateScore(const int& );
    void RewriteScore();
    int Menu();
    void Game();
    int GameOver();
private:
    int speed;
    int key;
    int score;
};

#endif