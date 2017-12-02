#include "Header.h"

Pawn::Pawn(int HP, int dmg, std::string name) 
	:figureHP(HP), figureDMG(dmg), figureName(name) {
}
Horseman::Horseman(int HP, int dmg, std::string name) 
	:figureHP(HP), figureDMG(dmg), figureName(name){
}
Bishop::Bishop(int HP, int dmg, std::string name) 
	:figureHP(HP), figureDMG(dmg), figureName(name) {
}
Tower::Tower(int HP, int dmg, std::string name)
	: figureHP(HP), figureDMG(dmg), figureName(name) {
}
Queen::Queen(int HP, int dmg, std::string name) 
	: figureHP(HP), figureDMG(dmg), figureName(name) {
}
King::King(int HP, int dmg, std::string name) 
	: figureHP(HP), figureDMG(dmg), figureName(name) {
}

bool Pawn::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    double X = pow((positionX - targetX), 2);
    double Y = pow((positionY - targetY), 2);
    
    double required = sqrt(X + Y);
    
    if (required > 1 && required < 2)
        return 1;
    else
        return 0;    
}

bool  Horseman::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;
    
    if (positionX == 2 && positionY == 0)
        return 1;
    else if (positionX == 0 && positionY == 2)
        return 1;
    else
        return 0;   
}

bool Tower::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    positionY = positionY - targetY;
    
    if (positionX == targetX || positionY == targetY)
        return 1;
    else
        return 0;
    
}

bool Bishop::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    positionY = positionY - targetY;
    
    if (positionX == targetX || positionY == targetY)
        return 1;
    else
        return 0;
}

bool Queen::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;
    
    if (positionX == positionY)
        return 1;
    else
        return 0;
}

bool King::canAttak(int positionX, int positionY, int targetX, int targetY)
{
    positionX = positionX - targetX;
    if (positionX < 0) targetX *= -1;
    positionY = positionY - targetY;
    if (positionY < 0) positionY *= -1;
    
    if (positionX <= 1 && positionY <= 1)
        return 1;
    else
        return 0;
}
