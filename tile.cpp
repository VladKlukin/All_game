#include <vector>
#include <string>
#include "tile.h"
using namespace std;

class Game {
private:
    vector<vector<Tile>> grid;
    int gridSize;
    int score;
    int movesLeft;
    int timeLeft;
    string mode;

    const vector<string> colors = { "$", "&", "*", "#", "@" };

public:
    Game(int size, std::string gameMode);
    void initializeGrid();
    void ensureNoMatches();