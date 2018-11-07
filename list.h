   // Victor Ochia, Karla Fant, CS 163 program #4, list.h
   //Purpose of file is to list prototypes of ADT and define private data
   //in the ADT's as well as give struct definitions



   #include <cctype>
   #include <cstring>
   #include <iostream>


   struct node //contains each nominee, their votes, a left and right pointer, and a constructor and destructor
   {
       char * nominee; //nominee
       int votes; //amount of votes
       node * right; //right pointer 
       node * left; //left pointer
       node(); //node destructor
       ~node(); //node constructor
   };




   class Nominee //The nominee class. Contains functions that correspond to the tree of nominees 
   {
       public:
          Nominee(); //the class constructor
          ~Nominee(); //the class destructor
          int add(char * to_add, int votes); //function adds a nominee to the tree
          int display(); //function displays all nominees
          int delete_all(); //function deletes the tree
          int find_nominee(char * to_find); //function finds a nominee if they are in the tree
          int remove_nominee(char * to_remove); //function removes a nominee if they are in the tree
          int change_votes(int new_vote, char * to_change);  //function changes a nominees votes if they are in the tree
       private:
          node * root; //root pointer
          int display(node * root);  //function displays all nominees
          int add(char * to_add, int votes,  node * & root); //function adds a nominee to the tree
          int delete_all(node * & root); //function deletes the tree
          int copy_data(char * to_add, int votes, node * & root); //function copies data from user into node
          int find_nominee(node * root, char * to_find); //function finds a nominee if they are in the tree
          int remove_nominee(char * to_remove, node * &root); //function removes a nominee if they are in the tree
          int change_votes(int new_vote, char * to_change, node * & root); //function changes a nominees votes if they are in the tree

   };

