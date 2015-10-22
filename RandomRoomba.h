#include "./Roomba.h"
#ifndef RANDOMROOMBA_HPP
#define RANDOMROOMBA_HPP


using namespace std;

class RandomRoomba: public Roomba {
   private:
      int spaces_cleaned;
      int row; //stores the next movement row
      int col; //stores the next movement column
   public:
      RandomRoomba();
      void choose_direction(Floor &);
      void clean_floor(Floor &);
};

#endif
