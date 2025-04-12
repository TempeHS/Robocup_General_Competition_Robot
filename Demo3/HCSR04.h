#ifndef _HCSR04_H_
#define _HCSR04_H_



class HCSR04{
  public:
  HCSR04();
  HCSR04(int trigger, int echo);

  void begin();

  int getDistance();

  int _trigger; 
  int _echo;
  int maxDistance;
  int timeout;
};


#endif