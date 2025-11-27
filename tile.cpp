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
    std::vector<std::pair<int, int>> findMatches();
    void removeMatches();
    void swapTiles(int row1, int col1, int row2, int col2);
    void display();
    void displayWithTime(int remainingTime);