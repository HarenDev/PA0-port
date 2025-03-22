#pragma once

#include "raylib-cpp/raylib-cpp.hpp"

class Program {
    private:
    int xPos;
    int yPos;
    int xSpeed;
    int ySpeed;

    //raylib methods
    raylib::Texture cool;
    raylib::Sound bounce;
    raylib::Font scary;
    
    public:
    void Init();
    void Update();
    void Draw();
    void Unload();

    ~Program();
};
