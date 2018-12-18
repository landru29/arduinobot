#ifndef ROUE_H
#define ROUE_H

class Roue {
  public:
    Roue(int mTriggerDroite, int mTriggerGauche);

    void reset();
    void resetDroite();
    void resetGauche();

    unsigned long compteurDroite();
    unsigned long compteurGauche();

    
    
    static void resetAll();
    static void resetLeft();
    static void resetRight();

    static unsigned long counterRight;
    static unsigned long counterLeft;

    static int steps;

 private:
  static void processRight();
  static void processLeft();
  
  
};

#endif
