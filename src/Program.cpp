#include "Program.hpp"

void Program::Init(){
    cool.Load("wabbit_alpha.png");
    bounce.Load("bounce.mp3");
    scary.Load("scary.ttf");

}

void Program::Update(){

}

void Program::Draw(){
    ClearBackground(GRAY);

    scary.DrawText("PA0", (GetScreenWidth()/2), 200, 20.0f, 20.0f, WHITE);

    scary.DrawText("Hello Students", 200, 200, 20.0f, 20.0f, WHITE);
}

void Program::Unload(){
    cool.Unload();
    bounce.Unload();
    scary.Unload();
}
