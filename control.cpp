#include "control.h"
#include "view.h"
#include "model.h"

#include <QDebug>


Control::Control(Model *m ,View *v) : QObject()
{
    this->view = v;
    this->view->setControl(this);
    this->model = m;


    timerId = startTimer(17);

}

void Control::timerEvent(QTimerEvent *event)
{

    if(!initStarted){
        init();
    }

    if (gamStarted){
        UpdateMario();
        UpdateBaril();
        ColisiongroundMario();
        ColisionBarilGround();
        ColisionTopMario();
        ColisionLRMario();
        ColisionMarioBaril();
        ColisionBarilLR();
        UpdateBowser();
        marioMove();

        }
     marioMove();




    }





void Control::game()
{
  // this->model = new Model();
   QGraphicsScene *scene = new QGraphicsScene;


   Back->setMedia(QUrl("qrc:/Sound/Mario-Boss.ogg"));
   Back->setVolume(50);
   Back->play();

   scene->setBackgroundBrush(QBrush(QImage(":/images/background.png").scaled(800,600,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));

   model->getMario()->setPos(600,450);
   scene->addItem(model->getMario());

   scene->addItem(model->getDk());
   model->getMario()->setFlag(QGraphicsItem::ItemIsFocusable);
   model->getMario()->setFocus();
   model->getChoix()->hide();


   for (int i =0; i<= 5; i++){
        scene->addItem(model->getBaril(i));
    }


   for (int j = 0; j <= 65; j++){
     scene->addItem(model->getBrick(j));
   }


   view->setScene(scene);
   gamStarted = true;

   
}
void Control::init()
{
    gamStarted = false;
    Back = new QMediaPlayer;
    Back->setMedia(QUrl("qrc:/Sound/Mario-Castle.ogg"));
    Back->setVolume(50);
    Back->setPosition(5000);
    Back->play();

    QFontDatabase::addApplicationFont(":/Font/Jumpman.ttf");
    QFont font("Jumpman",30);


  QGraphicsScene *scene = new QGraphicsScene;


  QLabel *Play = new QLabel();
  Play->setText("PLAY");
  Play->setFont(font);
  Play->setStyleSheet("QLabel {background-color : black; color : red; }");
  Play->setGeometry(QRect(260,500,70,50));



  QLabel *Score = new QLabel();
  Score->setText("SCORES");
  Score->setFont(font);
  Score->setStyleSheet("QLabel {background-color : black; color : red; }");
  Score->setGeometry(QRect(260,550,200,50));



  scene->setBackgroundBrush(QBrush(QImage(":/images/menu.png").scaled(800,600,Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation)));

  scene->addWidget(Score);

  model->getChoix()->show();
  model->getChoix()->setFocus();

  scene->addItem(model->getChoix());
  scene->addWidget(Play);



  view->setScene(scene);
  initStarted = true ;

}

void Control::gameOver()
{
    model->~Model();
    QGraphicsScene *gameOver = new QGraphicsScene;
    QBrush *blackB = new QBrush(Qt::black);
    QFontDatabase::addApplicationFont(":/Font/Jumpman.ttf");
    QFont font("Jumpman",30);
    QFont fontover("Jumpman",100);

    gameOver->setBackgroundBrush(*blackB);
    gameOver->addItem(model->getChoix());



    Back->setMedia(QUrl("qrc:/Sound/Mario-GameOver.ogg"));
    Back->setVolume(50);
    Back->setPosition(750);
    Back->play();




    QLabel *gameOverLabel = new QLabel();
    gameOverLabel->setText("GAME\nOVER");
    gameOverLabel->setFont(fontover);
    gameOverLabel->setStyleSheet("QLabel {background-color : black; color : red; }");
    gameOverLabel->setGeometry(QRect(260,10,500,500));


    QLabel *Retry = new QLabel();
    Retry->setText("RETRY");
    Retry->setFont(font);
    Retry->setStyleSheet("QLabel {background-color : black; color : red; }");
    Retry->setGeometry(QRect(260,500,100,50));

    QLabel *Quit = new QLabel();
    Quit->setText("Quit");
    Quit->setStyleSheet("QLabel {background-color : black; color : red; }");
    Quit->setGeometry(QRect(260,550,300,50));
    Quit->setFont(font);

    gameOver->addWidget(gameOverLabel);
    gameOver->addWidget(Retry);
    gameOver->addWidget(Quit);
    view->setScene(gameOver);

    model->getChoix()->show();

}




void Control::ColisiongroundMario()
{
    for (int i = 0; i <=64 ;i++){

    if(       model->getMario()->y()+50 >= model->getBrick(i)->y()
            &&model->getMario()->y()+50 <= model->getBrick(i)->y()+10

            && model->getMario()->x() >= model->getBrick(i)->x()
            && model->getMario()->x() <= model->getBrick(i)->x()+30

            ||

            model->getMario()->y()+50 >= model->getBrick(i)->y()
            && model->getMario()->y()+50 <= model->getBrick(i)->y()+10

            && model->getMario()->x()+35 >= model->getBrick(i)->x()
            && model->getMario()->x()+35 <= model->getBrick(i)->x()+35


            )

    {   //qDebug()<<model->getMario()->velocityY;
        model->getMario()->velocityY = 0.0;
        model->getMario()->onGround=true;
        break;


    }
    else {
        model->getMario()->onGround = false;



    }
    }
}

void Control::ColisionTopMario()
{
    for(int i = 0 ; i <= 64 ;i++){

    if(  model->getMario()->y() >= model->getBrick(i)->y() // Y AXIS
       && model->getMario()->y() <= model->getBrick(i)->y()+30



       && model->getMario()->x() >=  model->getBrick(i)->x()
       && model->getMario()->x() <= model->getBrick(i)->x()+30      //X AXIS



                      ||

          model->getMario()->y() >= model->getBrick(i)->y()
      &&  model->getMario()->y() <= model->getBrick(i)->y()+30

      && model->getMario()->x()+35 >= model->getBrick(i)->x()
      && model->getMario()->x()+35 <= model->getBrick(i)->x()+35
         )
    {
      model->getMario()->velocityY = 3;





        }





    }
}

void Control::ColisionLRMario()
{
    for(int i = 0; i<65 ;i++){


    if(   model->getMario()->y()+8 >= model->getBrick(i)->y()+6
        &&model->getMario()->y()+8 <= model->getBrick(i)->y()+35-6

        && model->getMario()->x() <= model->getBrick(i)->x()+35
        && model->getMario()->x() >= model->getBrick(i)->x()

        ||

        model->getMario()->y()+35-8 >= model->getBrick(i)->y()+6
        && model->getMario()->y()+35-8 <= model->getBrick(i)->y()+35-6

        && model->getMario()->x() <= model->getBrick(i)->x()+35
        && model->getMario()->x() >= model->getBrick(i)->x())
        {
        model->getMario()->blockG = true;
        break;

         }
        else {
        model->getMario()->blockG = false;

        }



          if(model->getMario()->y()+8 >= model->getBrick(i)->y()+6
        &&model->getMario()->y()+8 <= model->getBrick(i)->y()+35-6

        && model->getMario()->x()+35 <= model->getBrick(i)->x()+35
        && model->getMario()->x()+35 >= model->getBrick(i)->x()

        ||

          model->getMario()->y()+35-8 >= model->getBrick(i)->y()+6
          && model->getMario()->y()+35-8 <= model->getBrick(i)->y()+35-6

          && model->getMario()->x()+35 <= model->getBrick(i)->x()+35
          && model->getMario()->x()+35 >= model->getBrick(i)->x())
    {
       model->getMario()->blockD = true;
       break;

    }
     else{
              model->getMario()->blockD = false;

     }
    }



}

void Control::ColisionBarilGround(){
     for (int j = 0 ; j <5 ;j++){
        for (int i = 0; i <=64 ;i++){


    if(        model->getBaril(j)->y()+35 >= model->getBrick(i)->y()
            && model->getBaril(j)->y()+35 <= model->getBrick(i)->y()+10

            && model->getBaril(j)->x() >= model->getBrick(i)->x()
            && model->getBaril(j)->x() <= model->getBrick(i)->x()+30

            ||

            model->getBaril(j)->y()+35 >= model->getBrick(i)->y()
            && model->getBaril(j)->y()+35 <= model->getBrick(i)->y()+10

            && model->getBaril(j)->x()+35 >= model->getBrick(i)->x()
            && model->getBaril(j)->x()+35 <= model->getBrick(i)->x()+35


            )

    {
        model->getBaril(j)->velocityY = 0.0;
        model->getBaril(j)->onGround=true;



    }
    else {
      model->getBaril(j)->onGround = false;
          }
        }
     }
}

void Control::ColisionBarilLR()
{
    for (int j = 0 ; j <5 ;j++){
       for (int i = 0; i <=64 ;i++){


                   if(   model->getBaril(j)->y()+8 >= model->getBrick(i)->y()+6
                       &&model->getBaril(j)->y()+8 <= model->getBrick(i)->y()+35-6

                       && model->getBaril(j)->x() <= model->getBrick(i)->x()+35
                       && model->getBaril(j)->x() >= model->getBrick(i)->x()

                       ||

                       model->getBaril(j)->y()+35-8 >= model->getBrick(i)->y()+6
                       && model->getBaril(j)->y()+35-8 <= model->getBrick(i)->y()+35-6

                       && model->getBaril(j)->x() <= model->getBrick(i)->x()+35
                       && model->getBaril(j)->x() >= model->getBrick(i)->x()

                       ||
                         model->getBaril(j)->y()+8 >= model->getBrick(i)->y()+6
                       &&model->getBaril(j)->y()+8 <= model->getBrick(i)->y()+35-6

                       && model->getBaril(j)->x()+35 <= model->getBrick(i)->x()+35
                       && model->getBaril(j)->x()+35 >= model->getBrick(i)->x()

                       ||

                         model->getBaril(j)->y()+35-8 >= model->getBrick(i)->y()+6
                         && model->getBaril(j)->y()+35-8 <= model->getBrick(i)->y()+35-6

                         && model->getBaril(j)->x()+35 <= model->getBrick(i)->x()+35
                         && model->getBaril(j)->x()+35 >= model->getBrick(i)->x()

                          )
                   {
                       model->getBaril(j)->velocityX*=-1;
                   }




       }
    }

}

void Control::ColisionMarioBaril()
{
    for(int j =1 ; j <5 ; j++){
        if(model->getMario()->collidesWithItem(model->getBaril(j))){
            gamStarted = false;
            gameOver();
        }
    }

}



void Control::getMarioPos()
{
       model->getMario()->posX = model->getMario()->x();
       model->getMario()->posY = model->getMario()->y();

}

void Control::marioMove()

{


    if(!view->moveJ){
        if(model->getMario()->velocityY < -4.0)
            model->getMario()->velocityY = -4.0;
    }


    if (view->moveR && model->getMario()->posX <= 780 && !model->getMario()->blockD )
        {

           model->getMario()->velocityX = 2.5;
           if(spriteD < 10  && !view->moveJ){
           model->getMario()->setPixmap(model->getMario()->spriteWalkD);
           spriteD += 1;
          }
           else if (spriteD < 20 && !view->moveJ) {
               model->getMario()->setPixmap(model->getMario()->SpriteStaticD);
               spriteD+=1;
           }
           else{
           spriteD = 0;
           }



            }

    else
        {

            model->getMario()->velocityX =0;

        }



    if (view->moveL && model->getMario()->x() >= -15 && !model->getMario()->blockG)
       {

            model->getMario()->velocityX = -2.5 ;
                if(spriteG < 15 && !view->moveJ ){
                    model->getMario()->setPixmap(model->getMario()->spriteWalkG);
                    spriteG += 1;
                }
                else if (spriteG < 25 && !view->moveJ ) {
                    model->getMario()->setPixmap(model->getMario()->SpriteStaticG);
                    spriteG+=1;
                }
                else{
                spriteG = 0;
                }
         }

    if (view->moveJ  && model->getMario()->onGround )
    {

       model->getMario()->velocityY = -10;
        model->getMario()->onGround = false;
        model->getMario()->jump->setPosition(0);
        model->getMario()->jump->play();





    }

    if (view->moveUp && model->getChoix()->y()>500){
        model->getChoix()->setPos(model->getChoix()->x(),500);
    }
    if (view->moveD && model->getChoix()->y()<550){
        model->getChoix()->setPos(model->getChoix()->x(),550);

    }

    if (view->enter && model->getChoix()->y() < 550)
    {
        game();
    }

}

void Control::UpdateMario()
{

    if (model->getMario()->velocityY < 8 && !model->getMario()->onGround){
        model->getMario()->velocityY += model->getMario()->gravity;

    }



  // qDebug()<<model->getMario()->y();
   model->getMario()->setPos(model->getMario()->x()+model->getMario()->velocityX,model->getMario()->y()+model->getMario()->velocityY);
   model->getMario()->posY +=  model->getMario()->velocityY;
   model->getMario()->posX += model->getMario()->velocityX;


}

void Control::UpdateBaril()
{
    for(int i = 0 ;i <5 ;i++){
         model->getBaril(i)->setPos(model->getBaril(i)->x()+model->getBaril(i)->velocityX,model->getBaril(i)->y()+model->getBaril(i)->velocityY);
         model->getBaril(i)->posX += model->getBaril(i)->velocityX;


        if(model->getBaril(i)->x()+35 > 800 || model->getBaril(i)->x() < -25){
            model->getBaril(i)->velocityX*=-1;
    }

        if (model->getBaril(i)->velocityY < 5){
            model->getBaril(i)->velocityY += model->getBaril(i)->gravity;
     }
        if (model->getBaril(2)->x() >760 && model->getBaril(2)->y()>530){
            model->getBaril(2)->setPos(700,-5);
            //qDebug()<< model->getBaril(2)->posX;
        }
        if(model->getBaril(2)->x() <20 && model->getBaril(1)->y()>560){
            model->getBaril(2)->setPos(90,190);
    }
        if(model->getBaril(3)->y()>=350){
            model->getBaril(3)->velocityY = -1;
            model->getBaril(3)->gravity=0;


        }
        else if (model->getBaril(3)->y()<190){
            model->getBaril(3)->velocityY = 1;
            model->getBaril(3)->gravity=0;
        }
        if (model->getBaril(4)->x() < 20 && model->getBaril(4)->y()>560){
            model->getBaril(4)->setPos(90,100);
        }

    }
}

void Control::UpdateBowser()
{
    if(spriteB < 10  ){
    model->getDk()->setPixmap(model->getDk()->Sprite1);
    spriteB += 1;

   }
    else if (spriteB < 20) {
        model->getDk()->setPixmap(model->getDk()->Sprite2);
        spriteB+=1;
    }
    else{
    spriteB = 0;
    }

}
















