#include "./Floor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <stdlib.h>

//default constructor
Floor::Floor(){
   obj_row = 0;
   obj_col = 0;
}

//parameterized constructor
Floor::Floor(int r, int c){
   obj_row = r;
   obj_col = c;
}

//copy constructor
Floor::Floor(const Floor &temp){
   obj_row = temp.get_obj_row();
   obj_col = temp.get_obj_col();
}

//sets the obj row
void Floor::set_obj_row(int r){
   obj_row = r;
}

//returns the obj row
int Floor::get_obj_row()const{
   return obj_row;
}

//sets the obj col
void Floor::set_obj_col(int c){
   obj_col = c;
}

//returns the obj col
int Floor::get_obj_col()const{
   return obj_col;
}

//sets the floorplan for the entire room
//creates space in the vector for the input
//then reads in the textfile until it reaches
//the end of file at which point it 
//closes the file
void Floor::set_vector(char floorplan[]){
   char temp;
   v.push_back(vector <char>(0));
   fstream myfile;
   try{
      myfile.open(floorplan, ios::in | ios::out | ios::app);
      if(!myfile.is_open()){
	 throw "Error: Bad file input";
      }
   }
   catch(const char* msg){
      cout << "Error: Bad file input!" << endl;
      exit(0);
   }



   int y=0;
   while(!myfile.eof()){
      myfile.get(temp);
      if(temp == '\n'){
	 myfile.get(temp);
	 v.push_back(vector <char>(0));
	 y++;
      }
      v[y].push_back(temp);
   }
   myfile.close();
}

//returns the size of the row
int Floor::get_vector_rsize(){
   return v.size();
}

//returns the size of the column
int Floor::get_vector_csize(){
   return v[0].size();
}

//prints the vector
//used by Room
void Floor::print_vector(){
   usleep(800000);//slows down the output rate of program
   for(int i=0; i<v.size(); i++){
      for(int x=0; x<v[i].size();x++){
	 cout << v[i][x] << " ";
      }
      cout << endl;
   }
}

//checks the room to see if it is completely clean
bool Floor::check_clean(int spaces_cleaned){
   if(spaces_cleaned <= ((v.size()-1)*v[0].size()-1)){
      return 0;
   }
   else{
      return 1;
   }
}

//checks the direction to see if it is an okay 
//place to access, if it is, then it returns 1
//if it is not okay, it returns 0
bool Floor::check_direction(int row, int col){
   if((row >= 0) and (col >=0)and(row < v.size()-1) and (col < v[0].size())){
      return 1;
   }
   else{
      return 0;
   }
}

//ammends the vector with new row and col and then updates the number
//of spaces that have been cleaned
void Floor::edit_vectors(int row, int col, int &spaces_cleaned){
   //replace current position element with 'c'
   if(v[row][col] == 'f'){
      v[obj_row][obj_col] = 'c';
      spaces_cleaned++;
   }
   else{
      v[obj_row][obj_col] = 'c';
   }

   v[row][col] = 'r';

   //move to designated row and column
   //store row and column in obj_row and obj_col
   obj_row = row;
   obj_col = col;      
}
