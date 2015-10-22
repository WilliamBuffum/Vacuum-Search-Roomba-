#include "./Roomba.h"

//default constructor
Roomba::Roomba(){
   battery = 100;
   total_moves = 0;
}

//operator overload
void Roomba::operator=(const Roomba &temp){
   battery = temp.get_battery();
   total_moves = temp.get_total_moves();
}

//sets the battery, inherited by specific alg
void Roomba::set_battery(int b){
   battery = b;
}

//returns the battery
int Roomba::get_battery()const{
   return battery;
}

//sets the total moves, inherited by alg
void Roomba::set_total_moves(int stm){
   total_moves = stm;
}

//returns the total moves
int Roomba::get_total_moves()const{
   return total_moves;
}
