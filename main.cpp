    // Victor Ochia, Karla Fant, CS 163 program #4, main.cpp
   //Purpose of file is to test program


   #include "list.h"  
   using namespace std;
   






   void menu(); //displays the menu
  
   const int SIZE = 100;

   int main()
   {
       int j = 0; //keeps track of menu item picked
       int q = 0; // keeps track of which tree we are working with
       Nominee my_nominee; //nominee for best actor     
       Nominee second_nominee; //nominee for best actress
       char response; //keeps track of user choice in repeating parts of program
   
       

     
       do
       {


            menu();
            cin >> j; //takes in option from menu
            cin.ignore(100, '\n');

            cout << "\n\nEnter the number corresponding with which category of nominees you would like to perform this operation for:\n\n ";
            cout << "1. Acadamey Award For Best Actor       2. Academy Award For Best Actress\n\n";
            cin >> q; //takes in option from menu
            cin.ignore(100, '\n');
 
           if(j == 1) //if we are adding to the tree
           {

               do
               {
                   char add[SIZE]; //nominee user is adding
                   int votes; //votes the nominee has          

                   cout << "\n\nenter the name of the nominee you would like to add\n\n"; 
                   cin.get(add, SIZE, '\n');
                   cin.ignore(100, '\n');
                   add[0] = toupper(add[0]);       

                   cout << "\n\nEnter the number of votes this nominee has\n\n";
                   cin >> votes;
                   cin.ignore(100, '\n');
           
                   if(q == 1) //if we are entering in best actor
                      my_nominee.add(add, votes);
       
                   if(q == 2) //if we are entering in best actress
                      second_nominee.add(add, votes);

                   cout << "\n\nAgain?(Y or N)\n\n";
                   cin >> response;
                   cin.ignore(100, '\n');
               
                   response = toupper(response);

                   }while(response == 'Y');


           }

           if(j == 2) //if we are displaying all nominees in the tree
           {
                            
               if(q == 1) //if we are entering in best actor         
                  my_nominee.display();
               
               if(q == 2) //if we are entering in best actress
                  second_nominee.display();
   
           } 


           if(j == 3) //if we are finding an actor or actress
           {
               char to_find[SIZE]; //nominee we are trying to find
                            
               cout << "\n\nEnter the name of a nominee\n\n";
               cin.get(to_find, 100, '\n');
               cin.ignore(100, '\n');
               int votes = 0;
 
               if(q == 1) ////if we are entering in best actor
                  votes = my_nominee.find_nominee(to_find);
               
               if(q == 2) //if we are entering in best actress
                  votes = second_nominee.find_nominee(to_find);
           
               if(votes != 0) //if match is found
               {
                   cout << "\n\nYour nominee is: " << to_find << endl; 
                   cout << "Votes received: " << votes << endl << endl;

               }
     
               else //if match is not found
                 cout << "\n\nNo match found\n\n";


            }

            if(j == 4) //if we are removing an actor or actress
            {
                char to_remove[SIZE]; //nominee we are removing
                 
                cout << "\n\nEnter the name of the nominee you would like to remove:\n\n";
                cin.get(to_remove, 100, '\n');
                cin.ignore(100, '\n');
                to_remove[0] = toupper(to_remove[0]);
             
                if(q == 1)   //if we are entering in best actor
                {
                    if(!my_nominee.remove_nominee(to_remove))
                       cout << "\n\nnominee not found\n\n";
                }

                if(q == 2) //if we are entering in best actress
                {
                    if(!second_nominee.remove_nominee(to_remove))
                       cout << "\n\nnominee not found\n\n";
                }

            } 

             if(j == 5) //if we are changing a nominees votes
             {
                 int new_vote = 0; //votes we wish to give nominee
                 char to_change[SIZE]; // nominee we wish to change their votes
  
                 cout << "\n\nplease enter a nominee which you would like to have their amount of votes changed\n\n";
                 cin.get(to_change, SIZE, '\n'); 
                 cin.ignore(100, '\n');
                 to_change[0] = toupper(to_change[0]);

                 if(q == 1) //if we are entering in best actor 
                 {
                     if(!my_nominee.find_nominee(to_change)) //if there is no match
                        cout << "\n\nnominee does not exsist\n\n";


                     else //replace vote with new vote
                     {
                         cout << "\n\nPlease enter the votes you would now like this nominee to have\n\n";
                         cin >> new_vote;
                         cin.ignore(100, '\n');
                        
                         my_nominee.change_votes(new_vote, to_change);
                     
                     }



                 }
 
                 if(q == 2) //if we are entering in best actress
                 {
                     if(!second_nominee.find_nominee(to_change)) //if there is no match
                        cout << "\n\nnominee does not exsist\n\n"; 
                

                
                     else // replace old vote with new vote
                     {
                         cout << "\n\nPlease enter the votes you would now like this nominee to have\n\n";
                         cin >> new_vote;
                         cin.ignore(100, '\n');
                    
                         second_nominee.change_votes(new_vote, to_change);

                     }

              
                 }

             }

           cout << "\n\nReturn to main menu?(Y or N)\n\n";
           cin >> response;
           cin.ignore(100, '\n');
       
           response = toupper(response);

           }while(response == 'Y');



           return 0;    


   }



   void menu() //function displays the menu
   {
       cout << "\n\nWelcome to the oscars. In this program you are allowed to add, remove, and vote for a oscar nominee\n";
       cout << "of your choice. Use the interactive menu below and enter a number corresponding with the choices\n\n";
       cout << "1. add a new nominee                 2. display all nominees\n";
       cout << "3. find a nominee (name & votes)     4. remove a nominee\n";
       cout << "5. change a nominees votes\n\n";


   }  
     



