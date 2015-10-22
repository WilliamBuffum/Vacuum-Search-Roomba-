#include <string.h>
#include <stdlib.h>
#include <string>
#include "./Roomba.h"
#include "./RandomRoomba.h"
#include "./ZigRoomba.h"
#include "./CircleRoomba.h"
#include "./Floor.h"
#ifndef ROOM_HPP
#define ROOM_HPP

template <typename T>
class Room {
   private:
      Floor f;
      T* obj;
   public:
      //default constructor
      Room(){
	 obj = NULL;
      }

      //copy constructor
      Room(const Room &temp){
	 f = temp.get_floor();
	 obj = new T;
	 *obj = temp.get_obj();
      }

      //operator overload
      void operator=(const Room &temp){
	 f = temp.get_floor();
	 obj = new T;
	 *obj = temp.get_obj();
      }

      //allows user to select which object to clean the room with
      //at the moment, users select between three roomba algorithms
      void choose_obj(){
	 int choice;
	 cout << "Which Roomba (1 - Random, 2 - Zig Zag, 3 - Circle)? ";
	 cin >> choice;

	 if(obj != NULL){
	    delete [] obj;
	 }

	 if(choice == 1){
	    obj = new RandomRoomba;
	    cout << "Roomba set to Random!" << endl;
	 }
	 else if(choice == 2){
	    obj = new ZigRoomba;
	    cout << "Roomba set to Zig Zag!" << endl;
	 }
	 else if(choice == 3){
	    obj = new CircleRoomba;
	    cout << "Roomba set to Circle!" << endl;
	 }
	 else{
	    cout << "Error: Invalid choice" << endl;
	 }
      }

      //takes in the commandline arguments
      //uses loop to set attributes for Floor f/T* obj
      //f: sets row, col, floorplan
      //obj: sets battery
      void set_attributes(int argc, char* argv[]){
         if(argc == 1){
	    cout << "Remember there has to be commandline arguments!" << endl;
	 }

	 for(int i=0; i<argc; i++){
	    if(!strcmp(argv[i],"-b")){
	       cout << "Setting battery: " << argv[i+1] << endl;
	       obj->set_battery(atoi(argv[i+1]));
	    }
	    else if(!strcmp(argv[i],"-f")){
	       cout << "Setting textfile: " << argv[i+1] << endl;
	       f.set_vector(argv[i+1]);
	    }
	    else if(!strcmp(argv[i],"-r")){
	       cout << "Setting rows: " << argv[i+1] << endl;
	       f.set_obj_row(atoi(argv[i+1]));
	    }
	    else if(!strcmp(argv[i],"-c")){
	       cout << "Setting cols: " << argv[i+1] << endl;
	       f.set_obj_col(atoi(argv[i+1]));
	    }
	 }
      }

      //uses function chain to print the floorplan
      void print_floor(){
	 f.print_vector();
	 cout << "Battery left: \t\t" << obj->get_battery() << endl;
	 cout << "Total moves: \t\t" << obj->get_total_moves() << endl;
      }

      //returns the Floor object
      Floor get_floor()const{
	 return f;
      }

      //returns the templated object
      T* get_obj()const{
	 return obj;
      }

      //cleans the room
      //clean_floor polymorphs to proper obj type
      void clean_room(){
	 if(obj != NULL){
	    obj->clean_floor(f);//f passed by reference
	 }			//clean_floor(f) is part of roomba class
      }
     
      //prints out the columns and rows,
      //don't use, was checker
      void get_row_col(){
	 cout << "row: " << f.get_obj_row() << endl;
	 cout << "col: " << f.get_obj_col() << endl;
      }

      //deallocates memory allocated for pointer obj
      ~Room(){
	 cout << "destructor" << endl;
	if(obj != NULL){
	    delete [] obj;
	    obj = NULL;
	 }
      }
};


#endif
