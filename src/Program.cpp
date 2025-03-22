#include "Program.hpp"

Program::Program(){
    bounce.Load("bounce.mp3");
    bounce.SetVolume(0.3f);
    scary.Load("Scary.ttf");
    text = "Welcome to Advanced Programming";
    textSize = scary.MeasureText(text, 20.0f, 0.0f);
    xSpeed = 2;
    ySpeed = 2;
    xPos = GetRandomValue(0, GetScreenWidth()-textSize.x);
    yPos = GetRandomValue(0, GetScreenHeight()-textSize.y);
}

void Program::Update(){
    if (xPos + (int)textSize.x >= GetScreenWidth() || xPos <= 0){
        xSpeed *= -1;
        bounce.Play();
    }

    if (yPos + (int)textSize.y >= GetScreenHeight() || yPos <= 0){
        ySpeed *= -1;
        bounce.Play();
    }

    xPos += xSpeed;
    yPos += ySpeed;
    
    //debug
    //std::cout << xPos << " x " << yPos << "y " << GetScreenHeight() << " yScr " << GetScreenWidth() << " xScr " << std::endl ;
}

void Program::Draw(){
    ClearBackground(GRAY);
    scary.DrawText("PA0", (GetScreenWidth() - raylib::TextLength(text))/2, 5, 20.0f, 0.0f, WHITE);
    scary.DrawText(text, xPos, yPos, 20.0f, 0.0f, WHITE);
}

void Program::Unload(){
    bounce.Unload();
    scary.Unload();
}

Program::~Program() {
    Unload();
}
