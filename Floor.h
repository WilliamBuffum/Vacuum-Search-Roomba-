#include <vector>
#ifndef FLOOR_H
#define FLOOR_H

using namespace std;

class Floor {
   private:
      vector < vector <char> > v;
      int obj_row;
      int obj_col;
   public:
      Floor();
      Floor(int, int);
      Floor(const Floor &);
      void set_obj_row(int);
      int get_obj_row()const;
      void set_obj_col(int);
      int get_obj_col()const;
      void set_vector(char []);
      int get_vector_rsize();
      int get_vector_csize();
      void print_vector();
      bool check_clean(int);
      bool check_direction(int, int);
      void edit_vectors(int, int, int &);
};

#endif
