#include <iostream>
#include "./ZigRoomba.h"
#include "./RandomRoomba.h"
#include "./CircleRoomba.h"
#include "./Room.hpp"
#include "./Roomba.h"

#ifndef SIM_ROOMBA_H
#define SIM_ROOMBA_H

using namespace std;
//begins simulation
void simulate_roomba(int argc, char* argv[]){
   srand(time(NULL));//needed for RandomRoomba roomba alg.

   Room <Roomba> r;
   int v=0,i=0;

   for(i = 0; i < argc; i++){
      if(!strcmp(argv[i],"-v")){
	    cout << "Setting views: " << argv[i+1] << endl;
	    v = atoi(argv[i+1]);
      }
   }

   r.choose_obj();//allows user to select type of roomba
   r.set_attributes(argc, argv);//sets all the commandline info
   i = 0;
   do{
      r.clean_room();
      if((i%v) == 0){//prints floor only when desired view (v)
         r.print_floor();
      }
      i++;
   }while(r.get_obj()->get_battery());//runs the program until battery runs out
   //each algorithm auto-quits when all spaces are clean

   //prints the final board only if battery runs out
   cout << "Final:\n" << endl;
   cout << "Battery left:\t" << r.get_obj()->get_battery() << endl;
   cout << "Total Moves: \t" << r.get_obj()->get_total_moves() << endl;
   r.print_floor();

}

#endif
