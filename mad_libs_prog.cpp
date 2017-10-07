/****************************
 * Program Filename: assign6.cpp
 * Author: Kaitlin Hill
 * Date: 3/15/17
 * Description: This program redirects input and reads from a file. It then takes that information and sorts through it for noun, adj, and verbs. It then randomizes and prints the words
 * to the screen within the context of a story like Mad Libs. 
 * Input: Starting the program and picking the story.
 * Output: A fun Mad Libs story.
 * ****************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

using namespace std;

void make_2d_array(char [], char [][30], int &);
void sort_noun(char [], char [][30], char [][30], int &, int &);
void sort_verb(char [], char [][30], char [][30], int &, int &);
char * rand_word(int, char [][30]);
void story_1(int, char[][30], int, char [][30], int, char [][30], int, char [][30], int, char [][30]);
void story_2(int, char [][30], int, char [][30], int, char [][30], int, char [][30], int, char [][30]);
void story_3(int, char[][30], int, char[][30], int, char [][30], int, char [][30], int, char [][30]);
void read_in_words(char [], char [], char [], char [], char [][30], char [][30], int &, int &, char [][30], char [][30], int &, int &, char [][30], int &);
void clear_array(char [][30], char [][30], char [][30], char [][30], char [][30], char [], char [], char []);

/**********************************
 * Function: make_2d_array
 * Description: Puts the info from a 1D array and puts it into a 2D array.
 * Parameters: insert_holder (the 1D array) and version_2d (the 2D array)
 * Pre-conditions: insert_holder must hold a word.
 * Post-conditios: insert_holder and version_2d will hold words.
 * Return: None
 * ********************************/
void make_2d_array(char insert_holder[], char version_2d[][30], int &row_num){
   int h = strlen(insert_holder);
      for(int k=0; k<h; k++){
	 version_2d[row_num][k] = insert_holder[k];
      }
      row_num++;
}

/*********************************
 * Function: sort_noun
 * Description: Sorts the nouns into a regular noun or a plural noun.
 * Parameters: noun_holder, plural_noun, reg_noun, row_plural_noun, row_reg_noun
 * Pre-conditions: noun_holder must hold a word
 * Post-conditions: None
 * Return: None
 * ******************************/
void sort_noun(char noun_holder[], char plural_noun[][30], char reg_noun[][30], int &row_plural_noun, int &row_reg_noun){
   int x = strlen(noun_holder);
   if (noun_holder[x-1] == 's'){
      make_2d_array(noun_holder, plural_noun, row_plural_noun);   
   }
   else{
      make_2d_array(noun_holder, reg_noun, row_reg_noun);
   }
}

/*******************************
 * Function: sort_verb
 * Description: Sorts nouns based on if they are -ing or not.
 * Parameters: verb_holder, ing_verb, reg_verb, row_ing_verb, row_reg_verb
 * Pre-conditions: verb_holder must hold a word.
 * Post-condition: None
 * Return: None
 * ***************************/
void sort_verb(char verb_holder[], char ing_verb[][30], char reg_verb[][30], int &row_ing_verb, int &row_reg_verb){
   int y = strlen(verb_holder);
   if((verb_holder[y-1] == 'g') && (verb_holder[y-2] == 'n') && (verb_holder[y-3] == 'i')){
      make_2d_array(verb_holder, ing_verb, row_ing_verb);
   }
   else{
      make_2d_array(verb_holder, reg_verb, row_reg_verb);
   }
}

/****************************************
 * Function: rand_word
 * Description: Gets a random word from the array.
 * Parameters: row_num, version_2d
 * Pre-conditions: row_num must have a positive int, version_2d must have the same amount of words as row_num's value.
 * Post-conditions: None
 * Return: version_2d[t]
 * *************************************/
char * rand_word(int row_num, char version_2d[][30]){
   int t;
   t = rand() % row_num;
   return version_2d[t];
}

/*********************************
 * Function: story_1
 * Description: Prints out story 1
 * Parameters: row_plural_noun, plural_noun, row_reg_noun, reg_noun, row_ing_ver, ing_verb, row_reg_verb, reg_verb, row_adj, adj_arr
 * Pre-conditions: All the values must hold either an unsigned int or a word.
 * Post-conditions: None
 * Return: None
 * ******************************/
void story_1(int row_plural_noun, char plural_noun[][30], int row_reg_noun, char reg_noun[][30], int row_ing_verb, char ing_verb[][30], int row_reg_verb, char reg_verb[][30], 
     int row_adj, char adj_arr[][30]){
   cout << "Most doctors agree that bicycle " << rand_word(row_ing_verb, ing_verb) << " is a/an " <<rand_word(row_adj, adj_arr) << " form of exercise. " 
      << rand_word(row_ing_verb, ing_verb) << " a bicycle enables you to develop your " << rand_word(row_reg_noun, reg_noun) << " muscles as well as increase the rate of your "
      << rand_word(row_reg_noun, reg_noun) << " beat. More " << rand_word(row_plural_noun, plural_noun) << " around the world " << rand_word(row_reg_verb, reg_verb) 
      << " bicyles than drive " << rand_word(row_plural_noun, plural_noun) << ". No matter what kind of " << rand_word(row_reg_noun, reg_noun) << " you " 
      << rand_word(row_reg_verb, reg_verb) << ", always be sure to wear a/an " << rand_word(row_adj, adj_arr) << " helmet. Make sure to have " << rand_word(row_adj, adj_arr)
      << " reflectors too!" << endl;
}

/*********************************
 * Function: story_2
 * Description: Prints out story 2
 * Parameters: row_plural_noun, plural_noun, row_reg_noun, reg_noun, row_ing_ver, ing_verb, row_reg_verb, reg_verb, row_adj, adj_arr
 * Pre-conditions: All the values must hold either an unsigned int or a word.
 * Post-conditions: None
 * Return: None
 * ******************************/
void story_2(int row_plural_noun, char plural_noun[][30], int row_reg_noun, char reg_noun[][30], int row_ing_verb, char ing_verb[][30], int row_reg_verb, char reg_verb[][30], 
     int row_adj, char adj_arr[][30]){
   cout << "Yesterday, " << rand_word(row_reg_noun, reg_noun) << " and I went to the park. On our way to the " << rand_word(row_adj, adj_arr) << " park, we saw a "
      << rand_word(row_adj, adj_arr) << ' ' << rand_word(row_reg_noun, reg_noun) << " on a bike. We also saw big " << rand_word(row_adj, adj_arr) << " balloons tied to a " 
      << rand_word(row_reg_noun, reg_noun) << ". Once we got to the " << rand_word(row_adj, adj_arr) << " park, the sky turned " << rand_word(row_adj, adj_arr) << ". It started to "
      << rand_word(row_reg_verb, reg_verb) << " and " << rand_word(row_reg_verb, reg_verb) << ". " << rand_word(row_reg_noun, reg_noun) << " and I " << rand_word(row_reg_verb, reg_verb)
      << " all the way home. Tomorrow we will try to go the " << rand_word(row_adj, adj_arr) << " park again and hope it doesn't " << rand_word(row_reg_verb, reg_verb)
      << "." <<endl;
}

/*********************************
 * Function: story_3
 * Description: Prints out story 3
 * Parameters: row_plural_noun, plural_noun, row_reg_noun, reg_noun, row_ing_ver, ing_verb, row_reg_verb, reg_verb, row_adj, adj_arr
 * Pre-conditions: All the values must hold either an unsigned int or a word.
 * Post-conditions: None
 * Return: None
 * ******************************/
void story_3(int row_plural_noun, char plural_noun[][30], int row_reg_noun, char reg_noun[][30], int row_ing_verb, char ing_verb[][30], int row_reg_verb, char reg_verb[][30], 
     int row_adj, char adj_arr[][30]){
   cout << "Spring break 2017, oh how I have been waiting for you! Spring break is when you go to some " << rand_word(row_adj, adj_arr) << " place to spend time with " 
   << rand_word(row_reg_noun, reg_noun) << ". Getting to " << rand_word(row_reg_noun, reg_noun) << " is going to take " << rand_word(row_adj, adj_arr)
   << " hours. My favorite part of spring break is " << rand_word(row_ing_verb, ing_verb) << " in the " << rand_word(row_reg_noun, reg_noun) << ". During spring break, " 
   << rand_word(row_reg_noun, reg_noun) << " and I plan to " << rand_word(row_reg_verb, reg_verb) << " all the way to " << rand_word(row_reg_noun, reg_noun)
   << ". After spring break, I will be ready to return to " << rand_word(row_reg_noun, reg_noun) << " and " << rand_word(row_reg_verb, reg_verb) << " hard to finish "
   << rand_word(row_reg_noun, reg_noun) << ". Thanks spring break 2017!" << endl;
}

/*********************************
 * Function: read_in_words
 * Description: Reads in the words of the file until there is nothing else to read
 * Parameters: holder, noun_holder, verb_holder, adj_holder, plural_noun, reg_noun, row_reg_noun, row_plural_noun, ing_verrb, reg_verb, row_ing_verb, adj_arr, row_adj
 * Pre-conditions: holder, noun_holder, verb_holder, and adj_holder must hold nothing
 * Post-conditions: all the arrays will hold nothing
 * Return: None
 * ******************************/
void read_in_words(char holder[], char noun_holder[], char verb_holder[], char adj_holder[], char plural_noun[][30], char reg_noun[][30], int &row_reg_noun, int &row_plural_noun, 
      char ing_verb[][30], char reg_verb[][30], int &row_ing_verb, int &row_reg_verb, char adj_arr[][30], int &row_adj){
   memset((void *)holder, 0, 30);
   while(cin >> holder){
      if(holder[0] == 'n'){
         cin >> noun_holder;
	 sort_noun(noun_holder, plural_noun, reg_noun, row_plural_noun, row_reg_noun);
      }
      else if(holder[0] == 'v'){
         cin >> verb_holder;
	 sort_verb(verb_holder, ing_verb, reg_verb, row_ing_verb, row_reg_verb);
      }
      else if(holder[0] == 'a'){
         cin >> adj_holder;
	 make_2d_array(adj_holder, adj_arr, row_adj);
      }
     memset((void *)holder, 0, 30);
     memset((void *)noun_holder, 0, 30);
     memset((void *)verb_holder, 0, 30);
     memset((void *)adj_holder, 0, 30);
   }
}

/*********************************
 * Function: clear_array
 * Description: Initializes all arrays to hold nothing
 * Parameters: plural_noun, reg_noun, ing_verb, reg_verb, adj_arr, noun_holder, verb_holder, adj_holder
 * Pre-conditions: None
 * Post-conditions: All arrays will hold nothing
 * Return: None
 * ******************************/
void clear_array(char plural_noun[][30], char reg_noun[][30], char ing_verb[][30], char reg_verb[][30], char adj_arr[][30], char noun_holder[], char verb_holder[], char adj_holder[]){
   memset(plural_noun, 0, sizeof(plural_noun[0][0]) *25 *30);
   memset(reg_noun, 0, sizeof(reg_noun[0][0]) *25 *30);
   memset(ing_verb, 0, sizeof(ing_verb[0][0]) *25 *30);
   memset(reg_verb, 0, sizeof(reg_verb[0][0]) *25 *30);
   memset(adj_arr, 0, sizeof(adj_arr[0][0]) *25 *30);
   memset((void *)noun_holder, 0, 30);
   memset((void *)verb_holder, 0, 30);
   memset((void *)adj_holder, 0, 30);
}

/*********************************
 * Function: main
 * Description: Starts program and error checks
 * Parameters: argc, argv
 * Pre-conditions: None
 * Post-conditions: None
 * Return: 0 or 1 if bad input
 * ******************************/
int main(int argc, char *argv[]){
   char holder[30];
   char noun_holder[30];
   char verb_holder[30];
   char adj_holder[30];
   int row_plural_noun = 0;
   int row_reg_noun = 0;
   int row_ing_verb = 0;
   int row_reg_verb = 0;
   int row_adj = 0;
   char plural_noun[25][30];
   char reg_noun[25][30];
   char ing_verb[25][30];
   char reg_verb[25][30];
   char adj_arr[25][30];
   
   srand(time(NULL));
   clear_array(plural_noun, reg_noun, ing_verb, reg_verb, adj_arr, noun_holder, verb_holder, adj_holder);
   read_in_words(holder, noun_holder, verb_holder, adj_holder, plural_noun, reg_noun, row_reg_noun, row_plural_noun, ing_verb, reg_verb, row_ing_verb, row_reg_verb, adj_arr, row_adj);
   if (argc != 2){
      cout << "You did not enter in the information correctly" << endl;
      return 1;
   }
   if(strcmp(argv[1], "1") == 0){
      story_1(row_plural_noun, plural_noun, row_reg_noun, reg_noun, row_ing_verb, ing_verb, row_reg_verb, reg_verb, row_adj, adj_arr);
   }
   else if(strcmp(argv[1], "2") == 0){
      story_2(row_plural_noun, plural_noun, row_reg_noun, reg_noun, row_ing_verb, ing_verb, row_reg_verb, reg_verb, row_adj, adj_arr);
   }
   else if(strcmp(argv[1], "3") == 0){
      story_3(row_plural_noun, plural_noun, row_reg_noun, reg_noun, row_ing_verb, ing_verb, row_reg_verb, reg_verb, row_adj, adj_arr);
   }
   else {
      cout << "You did not enter in the information correctly" << endl;
      return 1;
   }
   return 0;
}
