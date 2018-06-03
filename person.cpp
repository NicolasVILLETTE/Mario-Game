#include "person.h"

Person::Person(int ,int)
{

    rect.translate(x,y);
    dead = false;
    isMovingR = false;
    isMovingR=false;
    isMovingL=false;
    isJumping=false;
}


Person::~Person()
{
std:cout << ("Person Deleted\n");
}

void Person::move(int, int)
{
    rect.moveTo(x,);

}
