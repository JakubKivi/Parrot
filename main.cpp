#include "Header.h"
#include "Board.h"

static bool win          = false;
static bool player       = false;
static int roundNumber         = 0;
static bool attacked;
static bool moved;
static std::string input;


void move() {}

int main() {
    int positionX, positionY, targetX, targetY;
    Board* board = GetFromFile();

    do {
        player = roundNumber % 2 + 1 != 0;
        std::cout << "Tura gracza " << player << std::endl;
        attacked = false;
        moved = false;
//===========================================CHECKING============================================//

        std::cout << "Jakie pola chcesz sprawdzić        x-nie chce już sprawdzać";
        do {
            std::cin >> input;
            if (input.size() == 2) {
                positionX = reverse(input[1] - '0', board->getY());
                positionY = toInt(input[0], board->getX());
            }else if (input.size() == 3) {
                positionX = reverse(input[1] * 10 + input[2], board->getY());
                positionY = toInt(input[0], board->getX());
            }else error("Zbyt duzy input");


//            auto k1 = (*board)[positionX];
//            auto k5 = k1.Fields;
//            for(int j10 = 0; j10 < 5; ++j10) {
//                auto k22 = k5[j10];
//                auto k30 = 3;
//            }
//            auto k2 = (*board)[positionX][positionY];
            (*board)[positionX][positionY]->reveal();

        } while (!(input.size() == 1 && input[0] == 'x'));
//======================================MOVE============================================//
        for (int i = 0; i < 1; i++) {     //to  sie robi raz ale mozna tu wracac :v
            std::cout << "Czy chcesz sie ruszyc y/n : " << std::endl;
            std::cin >> input;
            if (input =="y") {
                std::cout << "Wybierz figure                     exit <-wyjdz " << std::endl;
                std::cin >> input;
                if (input.size() == 2) {
                    positionX = reverse(input[1], board->getY());
                    positionY = toInt(input[0], board->getX());
                } else if (input.size() == 3) {
                    positionX = reverse(input[1] * 10 + input[2], board->getY());
                    positionY = toInt(input[0], board->getX());
                } else if (input == "exit") {
                    i--;
                    continue;
                } else error("Zły input");

            }
            else if(input=="n"){
                break;
            }else error("Zbyt duzy input");

            std::cout << "Wybierz cel :                          exit-wyjscie" << std::endl;
            std::cin >> input;
            if (input.size() == 2) {
                targetX = reverse(input[1], board->getY());
                targetY = toInt(input[0], board->getX());
            } else if (input.size() == 3) {
                targetX = reverse(input[1] * 10 + input[2], board->getY());
                targetY = toInt(input[0], board->getX());
            } else if (input == "exit") {
                i--;
                continue;
            } else error("Zły input");

            if(board->canMove(positionX, positionY, targetX, targetY)){         //drogi remku z przyszłości wiemy że to inaczej
                move(); // kiedys się zrobi
                moved= true;
            }
            else {
                std::cout<<"Nie mozesz sie tak ruszyc!" << std::endl;
                i--;
                continue;
            }
        }
//=============================================ATTACK=====================================================//

        for (int i = 0; i < 1; i++) {     //to  sie robi raz ale mozna tu wracac :v
            std::cout << "Czy chcesz atakować y/n : " << std::endl;
            std::cin >> input;
            if (input[0] == 'y') {
                std::cout << "Wybierz figure :                    exit <-wyjdz " << std::endl;
                std::cin >> input;
                if (input.size() == 2) {
                    positionX = reverse(input[1], board->getY());
                    positionY = toInt(input[0], board->getX());
                } else if (input.size() == 3) {
                    positionX = reverse(input[1] * 10 + input[2], board->getY());
                    positionY = toInt(input[0], board->getX());
                } else if (input == "exit") {
                    i--;
                    continue;
                } else error("Zły input");

            }else if(input=="n") {
                break;
            } else error("Zbyt duzy input");

            std::cout << "Wybierz cel : " << std::endl;
            std::cin >> input;
            if (input.size() == 2) {
                targetX = reverse(input[1], board->getY());
                targetY = toInt(input[0], board->getX());
            } else if (input.size() == 3) {
                targetX = reverse(input[1] * 10 + input[2], board->getY());
                targetY = toInt(input[0], board->getX());
            } else if (input == "exit") {
                i--;
                continue;
            }
            else error("Zły input");

            if((*board)[positionX][positionY]->canAttack(positionX, positionY, targetX, targetY)){    //drogi remku z przyszłości wiemy że to inaczej
                (*board)[positionX][positionY]->addHP(123456/*placeholder*/); // kiedys się zrobi żeby atakowało
                moved= true;
            }
             else {
                std::cout<<"Nie mozesz sie tak ruszyc!" << std::endl;
                i--;
                continue;
            }

        }

        roundNumber ++;

    }while(!win);
    std::cin.get();
}

