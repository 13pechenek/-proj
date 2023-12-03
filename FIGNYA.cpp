#include <iostream>
#include <cmath>
#include <vector>
#include <random>
#include <algorithm>


template <typename T>
class Move {
public:

    Point(T x, T y)
    {
        this->x = x;
        this->y = y;
    }

    virtual void &move(T x, T y)
    {
        this->x += x;
        this->y += y;
    }

    virtual bool CanMove(T x, T y)
    {
       if (this->x = x && this->y = y) return true else return false
    }
private:
    T x; T y;
};


template <typename T>
class Bullets: public Move {

private:
    T x; T y;

public:

    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<int> dis(1, 5);
    int rand = dis(gen);

    std::vector<int> vec {rand + 1, rand + 2};

    Bullets(T x, T y)
    {
        this->x = x; 
        this->y = y;
    }
    
    void &move(vec) override 
    {
        this->x += vec[0];
        this->y += vec[1];
    }
};



class Obstacles{
public:
    bool Obstacle;
}




template <typename T>
class Player: public Move {
public:

    int Lives;
    Player(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
}



template <typename T>
class Enemies: public Player, public Bullets {
public:


    Enemies(T x, T y, Player player)
    {
        this->x = x;
        this->y = y;
        this->distance_to_Player = sqrt( pow((player.x - x), 2) + pow((player.y - y), 2) )
        this->cos = (player.x - x)/distance_to_Player; 
        this->sin = (player.y - y)/distance_to_Player;
        bool able_to_move = true;
        bool see_Player = true;

    }

    Enemies &move(Player player) override
    {
        if (Obstacle)
        {
            if (distance_to_Player >= 300) able_to_move = false 
            else 
            {
                able_to_move = true;
                speed_enemy = {3*cos, 3*sin};
                this->x += v_enemy[0]; this->y += speed_enemy[1];
            } 
        }
    }

private:
    T x; T y;
    float cos, sin;
    float distance_to_Player;
    bool able_to_move;
    int count_of_bullets = 20;
    bool see_Player = true;
    std::array<float, 2> speed_enemy {};

}












