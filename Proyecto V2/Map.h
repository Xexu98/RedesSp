#ifndef TRACK_H
#define TRACK_H

#include "GameObject.h"

#include <vector>

class Player;

const int MIN_O_DIST = 50;
const int MAX_O_DIST = 100;

class Map : public Serializable
{
private:
    static std::vector<Vector2D> obstaclesBasePos;
    static double endY;

    std::vector<GameObject *> obstacles;

    Player *player;
    GameObject *background;
    GameObject *goal;

    std::string obstacleFilename;
    std::string playerFilename;
    std::string backgroundFilename;
    std::string goalFilename;

    int offset;
    Vector2D startPos;

    SDL_Renderer *renderer;

public:
    Map(SDL_Renderer *renderer, const Vector2D &startPos = Vector2D(), int width = 0);
    ~Map();

    virtual void to_bin();
    virtual int from_bin(char *data);

    void update(double deltaTime);
    void render();
    void handleInput(Input input);

    void createObstacles();
    void checkCollisions();

    static void setObstaclesPosition(int width, int posY);

    bool raceEnded();

    void removeObstacle(GameObject *obstacle);
    void clearObstacles();
};

#endif