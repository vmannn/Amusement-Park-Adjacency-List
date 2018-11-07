   // Victor Ochia, Karla Fant, CS 163 program #4, list.cpp
   //Purpose of file is to list all the Table ADT functions


   #include "list.h"

   using namespace std;   



   node::node() //Node constructure
   {
       nominee = NULL; //initalizes nominee
       votes = 0; //initializes votes
       right = NULL; // sets right pointer to NULL
       left = NULL; //sets left pointer to NULL

   }


   node::~node() //node destructor
   {
     
       if(nominee) //if there is a nominee
       {
           delete [] nominee; //delete the nominee and set it to NULL
           nominee = NULL;
       }
         
       votes = 0;

      
       
   }



   int Nominee::change_votes(int new_vote, char * to_change, node * & root) // function changes an exsisting nominees votes
   {
       if(!root) //if there are no nominees
          return 0;

      

       if(strcmp(to_change, root -> nominee) == 0) //compares the nominee with the the nominee entered 
       {
           root -> votes = new_vote; //  changes the nomineews votes to desired value
           return 1;
       }
       

       return change_votes(new_vote, to_change, root -> right) + change_votes(new_vote, to_change, root -> left); //goes through function recursively
       

   } 



   int Nominee::change_votes(int new_vote, char * to_change) //wrapper function
   {
       return change_votes(new_vote, to_change, root); 

   } 



   int Nominee::remove_nominee(char * to_remove) // wrapper function
   {
       return remove_nominee(to_remove, root);

   }



   int Nominee::remove_nominee(char * to_remove, node * &root) //function removes a nominee. takes a desired nominee and root pointer as args
   {

       node * current; // current pointer traversal
       node * previous; // previous pointer for traversal
       node * head; //head pointer to hold on to parts of tree
         

       if(!root) //if tree or subtree is empty
          return 0;

       if(strcmp(to_remove, root -> nominee) == 0) //if there is a match with node we want to remove from the tree
       {  
           
            if(!root -> right && !root -> left) //if left and right side of tree are NULL
            {
                delete root;
                root = NULL;
                return 1;
            }

 
            if(!root -> right && root -> left) //if only right side of tree is NULL
            {
                current = root -> left;
                delete root;
                root = current;
                return 1;
            }
    

            if(root -> right && !root -> left) //if only left side of tree is NULL
            {
                current = root -> right; //delete root and reconnect the tree
                delete root;
                root = current;
                return 1;
 
            }

            if(root -> right && root -> left) //if left and right side of tree are not NULL
            {
                head = root -> right; //set head to right side of root
                current = head;  //set current equal to head;
                previous = current; // set previous equal to current

                while(current -> left) //while the left side of tree isnt null, travel to the inorder successor
                {
                    previous = current;
                    current = current -> left;
                    
                }
               
                
           
                delete [] root -> nominee; //roots nominee and votes
                root -> nominee = NULL;

                root -> nominee = new char[strlen(current -> nominee) + 1]; //put the inorder successors nominee in root and delete the inorder successor
                strcpy(root -> nominee, current -> nominee);

                root -> votes = current -> votes;

                if(current == previous) //if the sucessor has no left pointer
                {

                    if(current -> right) //if the inorder sucessor has a right pointer to an node
                    {
                        previous = current -> right;
                        delete current;
                        root -> right = previous;
                        return 1;

                    }

                    delete root-> right;  //else just delete the inorder sucessor
                    root -> right = NULL;
             
                     return 1;

                }

                if(current -> right) //if the successor has a right pointer to other nodes
                {
                    previous -> left = current -> right; //set previous' left to cureents right pointer
                    delete current; //delete current
                    current = NULL; //set current to NULL
                    return 1;     
                }
           
                
                else //if there is no right pointer to the successor
                {
                   
                    delete current; //delete the successor
                    previous -> left = NULL; //set previous' left to NULL
                    return 1; 
                }
           
                return 1;
             }

                   

       }

       return remove_nominee(to_remove, root -> right) + remove_nominee(to_remove, root -> left); //goes through the tree recursively  
   }



   Nominee::Nominee() //Nominee Constructor
   {
       
       root = NULL; //set root to NULL

   }



   Nominee::~Nominee() //Nominee Destructor
   {

       delete_all(); //calls a function that will delete the tree
  
   }



   int Nominee::display() //wrapper function
   {
       return display(root); //calls function that will display the tree
   }


   int Nominee::delete_all() //wrapper function
   { 
       return delete_all(root); //calls function that will delete tree
   }



   int Nominee::delete_all(node * & root) //function deletes all nodes. Takes root pointer as arg
   {

       if(!root) //if tree or subtree is empty
          return 0;

       return delete_all(root -> right) + delete_all(root -> left); //recursive call

 

      delete root; //delete the root
      root = NULL;

   }

 
   int Nominee::find_nominee(node * root, char * to_find) //function finds a nominee. takes root and a desired nominee as args
   {
       if(!root) //if tree or subtree is empty
          return 0;

       find_nominee(root -> right, to_find) + find_nominee(root -> left, to_find); //recursive call

       if(strcmp(to_find, root -> nominee) == 0) //comapares desired nominee with nominees in tree
          return root -> votes; //returns their number of votes


       return find_nominee(root -> right, to_find) + find_nominee(root -> left, to_find);
   }

   int Nominee::find_nominee(char * to_find) //wrapper function takes a nominee as arg
   {
       return find_nominee(root, to_find); //calls function
   }



   
   int Nominee::add(char * to_add, int votes) //wrapper function takes a nominee and votes as arg
   {
       return add(to_add, votes, root); //calls function

   }



   int Nominee::add(char * to_add, int votes, node* & root) //function adds a nominee to the tree. takes a desired nominee, votes, and root pointer as args
   {
       if(!root) // if tree is empty
       {
           root = new node;   //create new node
           copy_data(to_add, votes, root); //copy data 
         
          return 1;
       }


       if(strcmp(root -> nominee, to_add) < 0) //if nominee being added is less than roots nominee
          add(to_add, votes, root -> right); //add on the right side of the tree
 
       else
          add(to_add, votes, root -> left); //else add on the left side of the tree

          return 1;
   }  



   int Nominee::copy_data(char * to_add, int votes, node * & root) // function copies users data and puts it in node being added to tree
   {
       if(!to_add) //if there is no nominee to add
          return 0;
   
       root -> nominee = new char[strlen(to_add) + 1]; //allocate new memory for nominee in node and put desired nominee
       strcpy(root -> nominee, to_add);

       root -> votes = votes; //add users desired votes for nominee
       return 1;  
   } 


   int Nominee::display(node * root) //function displays tree. Takes in a root pointer as arg
   {

       if(!root)  // if root is NULL
          return 0;
       
       display(root -> left);  //recursive call to go to the left side of the tree

       cout << "Your Nominee is: " << root -> nominee << endl; //display nominees
       cout << "Votes:" << root -> votes << endl << endl;

      
       display(root -> right); //recursive call to travel to right side of the tree

       return 1;
   }



