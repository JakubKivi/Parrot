#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
#include <array>
#include <math.h>
#include <fstream>

const int boardX = 8;
const int boardY = 8;
const int boardSize = 8;


inline void error(const std::string message);
int toint(char c);
int reverse(char a);


class GameObject{
private:

public:
    std::string Name;        
    GameObject(std::string name = "uninitialized");   
    virtual void reveal();
	int cordX;
	int cordY;
};

class Figure : public GameObject{
private:
    const int HP;
    double movement;	    
public:
    bool owner;        
    const int dmg;        
	Figure(std::string name, bool own, int HP, int dmg, int cordX, int cordY);
	Figure() = default;
    virtual bool isYour(bool player);
    void reveal();    
    void setHP(int hp);  // Zmienia HP obiektu o hp        
    bool canMove(int targetX, int targetY);
    virtual bool canAttak(int targetX, int targetY);   
};

//dziedziczenie po klasie Figure
class Pawn : public Figure  //pionek
{
public:
	Pawn(int HP, int dmg, std::string name);
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Horseman : public Figure  //ko�
{
public:
	Horseman(int HP, int dmg, std::string name);
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Tower : public Figure //wie�a
{
public:
	Tower(int HP, int dmg, std::string name);
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Bishop : public Figure  //goniec
{
public:
	Bishop(int HP, int dmg, std::string name);
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class Queen : public Figure  //kr�lowa
{
public:
	Queen(int HP, int dmg, std::string name);
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

class King : public Figure  //kr�l
{
public:
	King(int HP, int dmg, std::string name);
    bool canAttak(int positionX, int positionY, int targetX, int targetY);
};

