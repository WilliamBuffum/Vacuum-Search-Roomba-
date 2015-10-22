#include "./Roomba.h"
#ifndef ZIGROOMBA_H
#define ZIGROOMBA_H

class ZigRoomba: public Roomba {
   private:
      int spaces_cleaned;
      int row;
      int col;
      int top_left;
   public:
      ZigRoomba();
      void clean_floor(Floor &);
};

#endif
