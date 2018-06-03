#ifndef MODEL_H
#define MODEL_H

#include "choix.h"
#include "view.h"
#include "mario.h"
#include "baril.h"
#include "brick.h"
#include "dk.h"




class Model {

public:

    Model();
     Mario *getMario(){return mario;}
     Baril *getBaril(int j){return baril[j];}
     Brick *getBrick(int i){return brick[i];}

     Choix *getChoix(){return choix;}
     Dk    *getDk(){return dk;}
    ~Model();

private:
    Mario *mario;
    Dk    *dk;
    Brick *brick[64];
    Baril *baril[5];
    Choix *choix;

};

#endif // MODEL_H
