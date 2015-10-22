#include <iostream>
#include <vector>
#include <stdlib.h>
#include "./CircleRoomba.h"
#include "./Floor.h"

//default constructor
CircleRoomba::CircleRoomba(){
   spaces_cleaned = 1;
   row = 0;
   col = 0;
   top_left = 1;
   layer = 0;
   step = 1;
}

//clean room function
void CircleRoomba::clean_floor(Floor &f){
   //lines 19-44 get the roomba to the top left corner
   //of the room so that the circle algorithm can work
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

   //circle algorithm that has the roomba go around 
   //the outter-most non-clean area of the room
   else{
      if(step == 1){
	 row = f.get_obj_row()+1;
	 col = f.get_obj_col();
	 if(row == (f.get_vector_rsize()-1)-layer){
	    step = 2;
	 }
      }
      else if(step == 2){
	 row = f.get_obj_row();
	 col = f.get_obj_col()+1;
	 if(col == (f.get_vector_csize()-1)-layer){
	    step = 3;
	 }
      }
      else if(step == 3){
	 row = f.get_obj_row()-1;
	 col = f.get_obj_col();
	 if(row == layer){
	    step = 4;
	 }
      }
      else{
	 row = f.get_obj_row();
	 col = f.get_obj_col()-1;
	 if(col == layer){
	 layer++;
	    step = 1;
	 }
      }
   }

   //checks for viable movement and if good
   //then edits the vector
   if(f.check_direction(row, col)){
      f.edit_vectors(row, col, spaces_cleaned);
      battery -= 1;
      total_moves++;
   }

   //checks if the entire room has been cleaned
   //if it has, then it exits the program
   if(f.check_clean(spaces_cleaned)){
      cout << "Final:" << endl;
      cout << "Battery life: \t\t" << battery << endl;
      cout << "Total moves: \t\t" << total_moves << endl;
      cout << "\n";
      f.print_vector();
      exit(0);
   }
}
