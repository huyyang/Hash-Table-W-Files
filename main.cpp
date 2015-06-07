//this is the main function that will read in from a .txt file
//and the user can pick any song out of the text file and that will
//display it. The user can pick from 4-5 choices. To display all
//of the songs that are in the hash table, 

#include "table.h"

using namespace std;

//prototypes: Global functions
//This function reads in a song from//
void readSong(table & tableObject);

int main()
{
	//a function call for the hash table class
	table tableFunctionCall;
	
	//reads in the songs from a file and displays it
	readSong(tableFunctionCall);
	
	//user response integer
	int response;
	
	//user response yes or no
	char userResponse = 'Y';
	
	//a do while loop to ask the user if they would like to do this all over again
	do{
		//introduction for the user. See what the user wants to do.
		cout << "You are the user" << endl;
		cout << '\n' << endl;
		cout << "You are trying to look through the songs in the list and see which one" << endl;
		cout << "you want to choose from the list" << endl;
		cout << "Here are your options" << endl;
		cout << '\n' << endl;	

		//the 4 options the user can choose from
		cout << "Would you like to (display), (retrieve), (delete) or (exit) the program?" << endl;
		cout << "(1) is display" << endl;
		cout << "(2) is retrieve" << endl;
		cout << "(3) is delete something" << endl;
		cout << "(4) is to exit" << endl;
		cin >> response;
		cin.ignore(100, '\n');
	
		//if the response is 1, we will display the list of song items in the hash table
		//if there are three words in the title of the song, the song class data members
		//will display 3 instances of the song class data members, if there are 4, then 
		//there will be 4 displayed, and so on. 
		if(response == 1)
		{
			cout << "Here are your list of song items in the hash table" << endl;
			tableFunctionCall.displayTable();
		}
		//if the user response is 2, we will retrieve something the user wants
		else if(response == 2)
		{
			char * songTitleEnter;
			songTitleEnter = new char[50];
			cout << "Enter in the first word of the title to search for" << endl;
			cin.get(songTitleEnter, 50, '\n');

			tableFunctionCall.retrieve(songTitleEnter);
		}
		//if the user response is 3, the program will delete everything in the 
		//linear linked list of arrays
		else if(response == 3)
		{
				
		}
		//if the user response is 4, the program will exit
		else if(response == 4)
		{
			cout << "You have exited out of the program" << endl;
			cout << "Goodbye" << endl;
		
			//return 0 will exit out of the program
			return 0;
		}
		cout << "Would you like to select another option?" << endl;
		cout << "(y) for yes or (n) for no" << endl;
		cin >> userResponse;
		cin.ignore(100, '\n');

	}while(toupper(userResponse) == 'Y');
	return 0;
	
}

//a global function that will read in all the songs in the 
//.txt file and display it. Also passes in the hash table
//class by reference so we can use it in this function 
void readSong(table & tableObject)
{

	//opens up a new file using ifstream from fstream
	//ifstream is ALWAYS used to initialize a file to
	//open, close or manipulate a file
	ifstream file;

	//opens up the file songs.txt in your files in the local folder
	file.open("songs.txt");

	//using a for loop to go through the songs in your list
	cout << '\n' << endl;
	for(int i = 0; i < 10; ++i)
	{
		cout << "Here are your set of songs" << endl;
		
		//calling an instance of the class and putting that into a temp
		//making a new class
		song * temp = new song;
		
		//putting the variables into the class
		temp -> readIn(file);
	
		//displays each of the song objects such as the title, artist name, 
		//album name, minutes and extractions
		temp -> display(); 
	
		//using the table object passed in as the argument, each display will
		//insert into the corresponding node according to the hash function
		//because the hash function will determine where the node of the class "song"
		//will go into. 	
	
		tableObject.insertIntoTable(temp);
		
		//makes a new line to make it cleaner. 
		cout << '\n' << endl;
	
	}	
	
	//closes the file because that is required when you open up a file
	file.close();
}

