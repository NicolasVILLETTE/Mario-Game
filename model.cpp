#include "model.h"


Model::Model()
{
    this->choix = new Choix;
    this->choix->hide();
    this->mario = new Mario();
    this->dk = new Dk;



    for(int i = 0; i < 5; i++)

    {   if( i == 0 ){
        this->baril[i] = new Baril(100,10);
        }
        else if ( i == 1){
            this->baril[i] = new Baril(130,470);

        }
        else if  (i == 2){
            this->baril[i] = new Baril(700,-5);
        }
        else if (i == 3 ){
            this->baril[i] = new Baril(680,-5);
            this->baril[i]->velocityX = 0;
        }
        else if ( i == 4){
            this->baril[i] = new Baril(90,100);

        }

    }

    for (int i = 0; i < 65; i++)                //Creation Block
    {
        if (i == 0  ){
            this->brick[i]=new Brick (-10,600);

        }

        else if (i == 24 ){
                this->brick[i] = new Brick (100,this->brick[i-1]->y()-200);

            }
        else if (i == 37){
            this->brick[i] = new Brick ( 95,165);

        }
        else if (i == 38){
            this->brick[i] = new Brick (this->brick[i-2]->x()+150,400);

        }

        else if (i == 41 )
        {
            this->brick[i] = new Brick (-25,this->brick[i-1]->y()-200);


        }

        else if (i == 53 ){
            this->brick[i] = new Brick (this->brick[i-1]->x()+100,this->brick[i-1]->y());

        }
        else if (i == 59 ){
            this->brick[i] = new Brick (65,565);

        }
        else if(i == 60 ) {
            this->brick[i] = new Brick (this->brick[53]->x()-10,this->brick[53]->y()+50);

        }
        else if(i == 61) {
            this->brick[i] = new Brick (765,300);

        }
        else if (i == 64 )
        {
            this->brick[i] = new Brick (25,500);

        }
        else if (i == 63)
        {
            this->brick[i] = new Brick (725,300);

        }
        else if (i == 62){
            this->brick[i] = new Brick (250,565);

        }


        else{
            this->brick[i]= new Brick(this->brick[i-1]->x()+35,this->brick[i-1]->y());
}
    }


}








Model::~Model(){

    this->dk->deleteLater();
   for(int i = 0; i < 5; i++){      //baril
        this->getBaril(i)->deleteLater();
    }
    for (int i = 0; i < 64; i++)  {  // Brick
        this->getBrick(i)->deleteLater();
    }
    //delete choix;
}
