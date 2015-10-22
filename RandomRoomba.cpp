#include <iostream>
#include <stdlib.h>
#include "./RandomRoomba.h"

RandomRoomba::RandomRoomba(){
   spaces_cleaned = 1;
   row = 0;
   col = 0;
}

void RandomRoomba::choose_direction(Floor &f){
   int i = 0;

   //lines 28 - 48 select direction to move
   //rand used to randomly select row or column to change
   //once determine -> rand uses to select move +1 or -1
   i = rand() % 2 + 1;

   if(i == 1){//row selection
      i = rand() % 2 + 1;
      if(i == 1){//row direction
	 row = f.get_obj_row()+1;
      }
      else{
	 row = f.get_obj_row()-1;
      }
   }
   else{//col selection
      i = rand() % 2 + 1;
      if(i == 1){//col direction
	 col = f.get_obj_col()+1;
      }
      else{
	 col = f.get_obj_col()-1;
      }
   }
}

void RandomRoomba::clean_floor(Floor &f){

   //set the starting location for search alg. 
   row = f.get_obj_row();
   col = f.get_obj_col();

   choose_direction(f);


   //checks if valid movement, if not, no move made
   if(f.check_direction(row, col)){
      f.edit_vectors(row, col, spaces_cleaned);
      battery -= 1;
      total_moves++;
   }

   //checks for fully clean room
   if(f.check_clean(spaces_cleaned)){
      cout << "Final:" << endl;
      cout << "Battery left: \t\t" << battery << endl;
      cout << "Total Moves: \t\t" << total_moves << endl;
      cout << "\n";
      f.print_vector();
      exit(0);
   }

}
