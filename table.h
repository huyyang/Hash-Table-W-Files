//Huy Yang (HUy Yanhs), Karla Fant, COmputer SCience 163, 10/30/2014

//This file is the hash table files 
//The hash table is going to be a linear linked list of arrays
//We send in values from the extract file song.txt into each arrays
//and we send each of the values into an array. 
//The hashFunction takes in a character from the song.txt and returns
//an integer to be found for later for the user to enter in and look
//for in the has function. We also have an insert function where we
//can take out a song and insert another on in it.
//The display function will display all of the manipulated songs in the list
//whether the user has removed or added anything in the hash table linear 
//linked list. The destroy function will destroy all of the linear linked list
//first, then will destroy the array after that.     

//homework3_table.h file

#include "fileExtract.h"
 

//a struct node that is made for our linear linked list
//this will then connect with our hash table to make it
//an array of linear linked list
struct node
{
	//song will pass in an object by pointer
	song * songObject;

	char * key;

	//a next pointer to point to the next node
	//in the list if needed
	node * next;
};

class table
{
	public:
		//a prime number because youre gonna reduce the amount of collisions you're going to have 
		//should be assigned in your constructor. 
		//My constructor initializes all of the variables and I feel this is the key to make
		//my hash table because this is where you initialize all your values and in this case
		//I initialized my double pointer node all to NULL to start my linera linked list
		//inside of each array. One linear linked list for an array. 
		table();

		//This is our destructor. At the end of our program it will delete our WHOLE linear linked
		//list of arrays. Even though this is one line of code, it is because it is calling a
		//function. There are two functions that accompany with the destructor. One function will
		//deallocate our whole linear linked list and then will destroy all of our array.
		~table();

		//this is the hash table function
		//key is the index to our hash function
		int hashFunction(char * keyValue);

		//inserts a node into the corresponding section of the array in which was worked
		//out by the hash table
		int insertIntoTable(song * toAdd);

		//The user will enter in a character they want in the song title and 
		//it will display that song onto their terminal. When a song title is
		//passed in, the hash table will return an integer and that determines
		//where in the hash table where that song name is. 
		int retrieve(char * & name);
	
		int stringCompare(char * & name, char * & songNameTemp);
	
		//we're going to return an array of songs, and thats gonna be the
		//this is the part we're doing our search. What we're going to do
		//is that it will perform on the hash of the argument that we called
		//it will go into the linked list and it will make a comparison
		//that the argument that we passed in thats in one of the songs
		//and if thats wwrong then we will keep searching
		//makes an array of our song class in which it will be returned
		int displayTable();

		//destroys everything in the array along with the linear linked list
		//because the destroyList is called inside of this function.
		int destroy();

		//destroys everything in the linear linked list but NOT array
		int destroyList(node * & head);

	
	private:
		//a double pointer for a hashTable because this is what hashTables need
		//The reason why there is a double pointer is because it basically means
		//there is a node, that is pointing to another node, in which points to
		//a whole set of nodes in which is in the array. 
		node ** hashTable;

		//determines the size of the hashTable which is determined in the 
		//constructor of the .cpp file
		int hashTableSize;
};
