#include "./Floor.h"
#ifndef ROOMBA_H
#define ROOMBA_H

class Roomba {
   protected:
      int battery;//# of moves it can make
      int total_moves;//# of moves made
   public:
      Roomba();
      void operator=(const Roomba &);
      virtual void clean_floor(Floor &)=0;//polymorphs to specifc alg.
      void set_battery(int);
      int get_battery()const;
      void set_total_moves(int);
      int get_total_moves()const;
};

#endif

