#include "./Roomba.h"
#ifndef CIRCLEROOMBA_H
#define CIRCLEROOMBA_H

class CircleRoomba: public Roomba {
   private:
      int spaces_cleaned;
      int row;
      int col;
      int top_left;
      int layer;
      int step;
   public:
      CircleRoomba();
      void clean_floor(Floor &);
};

#endif
