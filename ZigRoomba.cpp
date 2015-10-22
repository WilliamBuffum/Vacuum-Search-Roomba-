#include <iostream>
#include <stdlib.h>
#include "./ZigRoomba.h"
#include "./Floor.h"

ZigRoomba::ZigRoomba(){
   spaces_cleaned = 1;
   row = 0;
   col = 0;
   top_left = 1;
}

void ZigRoomba::clean_floor(Floor &f){
   //to get it to the top left corner
   //use if statement to check if it's there
   //if not, move left
   //if cannot move left, move up
   //if cannot move left and cannot move up
   //then do the rest of the program.

   if(top_left){
      if(f.get_obj_row()){
	 row = f.get_obj_row()-1;
	 col = f.get_obj_col();
	 f.edit_vectors(row, col, spaces_cleaned);
	 battery -= 1;
	 total_moves++;
	 if(!(row) and !(col)){
	    top_left = 0;
	 }
      }
      else if(f.get_obj_col()){
	 col = f.get_obj_col()-1;
	 row = f.get_obj_row();
	 f.edit_vectors(row, col, spaces_cleaned);
	 battery -= 1;
	 total_moves++;
	 if(!(col) and !(row)){
	    top_left = 0;
	 }
      }
      else{
	 top_left = 0;
      }
   }


   else{
      //movement algorithm
      //if in an even col, move down
      //if in an odd col, move up
      //if cannot move down and cannot move up, move right
      if(col%2 == 0){
	 row = f.get_obj_row()+1;
	 col = f.get_obj_col();
      }
      else{
	 col = f.get_obj_col();
	 row = f.get_obj_row()-1;
      }
      if(f.check_direction(row, col)){
	 f.edit_vectors(row, col, spaces_cleaned);
	 battery -= 1;
	 total_moves++;
      }
      else{
	 row = f.get_obj_row();
	 col = f.get_obj_col()+1;
	 if(f.check_direction(row, col)){
	    f.edit_vectors(row, col, spaces_cleaned);
	    battery -= 1;
	    total_moves++;
	 }
      }
   }

   //checks if the entire room has been cleaned
   //if it has, then it prints the final floor
   //and exits the program
   if(f.check_clean(spaces_cleaned)){
      cout << "Final:" << endl;
      cout << "Battery life: \t\t" << battery << endl;
      cout << "Total moves: \t\t" << total_moves << endl;
      cout << "\n";
      f.print_vector();
      exit(0);
   }
}
