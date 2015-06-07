//this file is associate with the table.h file. This file is where
//the hashfunction and hash table is implemented. The hash table which
//is this whole file is supposed to be an array of linear linked list.
//The hash function will return an integer value when a character is
//passed in. Using the module reference, it will assign that 
//certain character that is passed in as an index of that new array.
//Then the new node will be added to the linear linked list. The 
//hash table can then display all that is in the hash table and 
//also destroy it. The user can then decide if they want to delete
//a certain song or add a song that they want if they wanted to.

//include the table.h
#include "table.h"

using namespace std;

//the constructor for our table. Initializes all the data members
//to a certain size which is declared inside of our class backbone
//which is in the .h file
//also sets everything in a hashTable to 0
table::table()
{
	//have the table size be equal to the argument size
	hashTableSize = 53;	
	
	//the double pointer hashTable now points to multiple pointers
	hashTable = new node*[hashTableSize];

	//initialize all pointers to NULL
	for(int i = 0; i < hashTableSize; ++i)
		hashTable[i] = NULL;
}

//the destructor
table::~table()
{
	//the function deallocates all the linear linked list
	//in the array and then deallocates everything in the 
	//array. 
	destroy(); 
}

//the hashTable that a user will neter in a key value and 
//it will return an integer
int table::hashFunction(char * keyValue)
{
	//obtain the length of the characters in keyValue
	int length = strlen(keyValue);

	//initialize a new variable key to 0
	int key = 0;

	//goes through the length of keyValue and turns that into key
	for(int i = 0; i < length; ++i)
		key += keyValue[i];
	
	//gets the hashing value through the modulo operation
	key = key % hashTableSize;

	//will return the the integer
	return key;
}

//inserts a node of the song class into the array 
//and this will make it a linear linked list
int table::insertIntoTable(song * toAdd)
{
	//have the words be equal to the number of the words
	//in the title of the song that is being added
	int words = toAdd -> displayWordsInTitle();

	//for how many words there are in the current title
	//that is being pointed at, loop that many times
	for(int i = 0; i < words; ++i)
	{
		//have the size be equal to the hashFunction input size
		//the hash function will return an integer and we need
		//that integer to determine where we want to store our
		//node as a linear linked list
		int size = hashFunction(toAdd -> copySongName(i));
	
		//if the list is empty
		if(!hashTable[size]) 
		{
			//make a new node in the hashTable size
			hashTable[size] = new node;
	
			//add in the node into the hash table
			hashTable[size] -> songObject = toAdd;
	
			//have it be equal to null so there will be
			//no segfaults
			hashTable[size] -> next = NULL;
		
			//make a tempporary pointer for hashTable[size] 
			//just as a pointer
			node * temp = hashTable[size];

			//store in the title name into the temporary array
			temp -> key = new char[strlen(toAdd -> copySongName(i)) + 1];

			//then string copy the name into the node which is the 
			//key
			strcpy(temp -> key, toAdd -> copySongName(i));

		}
	
		else
		{		
			//if there is nothing in the list of the linear linked list
			//temp is equal to a new node
			node * temp = new node;
			
			//makes a new temp pointer if the list
			//is not empty and will add in a song class
			//into a linear linked list which is set
			//into the array
			temp -> songObject = toAdd;
		
			//put that temp variable into the has table index
			temp -> next = hashTable[size];

			//have hashTable be temp
			hashTable[size] = temp;

			//we are going to now store the song title into the char
			temp -> key = new char[strlen(toAdd -> copySongName(i)) + 1];
	
			//string copy the given title name into the char key which
			//is in the struct
			strcpy(temp -> key, toAdd -> copySongName(i)); 


		}
	
	}
	return 1;
}

//My attempt on the retrieve function. This function is spuposed to
//retrieve a song depending on what the character inputted
int table::retrieve(char * & name)
{
	//have the size be the user input name
	int size = hashFunction(name);
	
	//if hashTable is not empty  
	if(hashTable[size])
	{
		//have the current be the hashTable[size]
		node * current = hashTable[size];
		//while current exists
		while(current)
		{
			//string compares the key with the name
			if(strcmp(current -> key, name) == 0)
			{
				current -> songObject -> display();	
				current = current -> next; 
			}
			//string compares the key with the name
			else if(strcmp(current -> key, name) != 0)
			{
				return 1;
			}
		}
	}
	
}

//this displays the whole hash table (linear linked list of arrays)
//will display all of the nodes which is in the array
int table::displayTable()
{
	//a for loop looping to each array 23 times because
	//hashTableSize is equivalent to 23
	for(int i = 0; i < hashTableSize; ++i)
	{
		//if the hashTable is NOT empty will no nodes
		//we would want to loop throug the hashTableSIZE
		//to look for a spot that is not empty because
		//in that array exists a node if it is not NULL
		if(hashTable[i] != NULL)
		{
			//have a current pointer be equal to the
			//hashTable index in where we are in the 
			//for loop
			node * current = hashTable[i];
			
			//while current is traversing through the
			//linear linked list
			while(current)
			{
				//current pointing to songObject (struct
				//song class declaration) pointing to its own
				//public function display, will display it
				current -> songObject -> display();

				//traverses through the linear linked list
				current = current -> next;

				//makes a new line
				cout << '\n' << endl;
			}
		}
	}
}

int table::retrieve(char * getName){

	if(!head)
		return 0;

	else{
		

	}
}

//destroys everything in an the array
int table::destroy()
{
	//if the hashTable exists
	if(hashTable)
	{
		//going through the loop of the array
		for(int i = 0; i < hashTableSize; ++i)
		{
			//if multiple hashTables Exists
			if(hashTable[i])
			{
				//call the destroy function in which
				//destroys all of the linear linked list
				//and since we're going through a for loop	
				//we destroy all of the array
				destroyList(hashTable[i]);	
			}
		}
		//delete our node**hashTable
		delete hashTable;
		hashTable = NULL;
	}
	 
	
}

//destroys everything in the linear linked list but NOT arrays yet
//because we are in a linear linked list of arrays
//this is a recursive function
int table::destroyList(node * & head)
{
	//if head is NULL get out of here!
	if(!head)
		return 0;

	//goes through the list all the way at the end of the list recursively
	//this is a recursive call
	destroyList(head -> next);
	
	//goes down the list and deletes head
	delete head;

	//initiate head to NULL or else we get a segfault
	head = NULL; 

	return 1; 
	
}

