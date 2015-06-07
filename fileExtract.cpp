//This file is the .cpp that is related to the fileExtract.h
//file. This file contains the constructor, destructor and 
//a txt file read in function. The readIn function will read
//in from a .txt file and will also display the text in the
//the .txt file. 

#include "fileExtract.h"

//using namespace std;

song::song()
{
	//initializes songName to a new char array
	songName = new char*[SIZE];
	for(int i = 0; i < SIZE; ++i)
		songName[i] = NULL; 
	
	//initializes artist to a new char array
	artist = new char[SIZE];
	//artist = NULL;
	
	//initializes album to a new char array
	album = new char[SIZE];	
	//album = NULL; 	

	//initializes intiger minutes to 0
	minutes = 0;
	
	//initializes integer extractions to 0
	extractions = 0;

	//we need the words in the title to start at 0
	wordsInTitle = 0;
}

//the destructor for the file extracting
//class. Deallocate all the data members
//in the class
song::~song()
{
	//a for loop to destroy everything that is in the double
	//char array songName
	for(int i = 0; i < SIZE; ++i)
	{
		//if songName exists 
		if(songName[i])
		{
			//delete song name
			delete [] songName[i];
			
			//have it initialized to NULL		
			songName[i] = NULL;
		}
	}
	//deallocate the char * artist
	delete [] artist;

	//deallocate the char * album
	delete [] album;

	minutes = 0;
	extractions = 0;
	wordsInTitle = 0;		
}

//reads in from the file called song.txt 
//in the song.txt there is a list of songs,
//artist, album numbs, minutes and 
//number of extractions that the user has 
//made
int song::readIn(ifstream &file)
{
	//table tableFunctionCall;
	
	//a temp array that will later be transferred
	char songTemp[100];

	//gets the song name in which is a pointer
	//to a pointer. We are doing arrays of arrays
	//for just the song title
	file.get(songTemp, (SIZE - 1), ';');
	file.ignore(100, ';');
	
	//have the count be 1 because if it starts
	//at 0 like always, we wlil have one words
	//in the song title missing
	int count = 1;

	//going into a for loop to find how many spaces
	//there are in a song title because we want to
	//know how many words there are in a song
	//we keep a counter for that for determination
	for(int i = 0; i < strlen(songTemp); ++i)
	{
		//this is how we are going to count 
		//how many words there are in the song
		//title. If the songTemperary array
		//passes a "space", it will count 1
		if(songTemp[i] == ' ')
			count = count + 1;
	}

	//the wordsInTitle IS the count now
	wordsInTitle = count; 

	//have int i be 0
	int i = 0;
        //we need k to be 0 
	int k = 0;
	//for every wordsInTitle, it will loop around for 
	//how many words are going to be in the title
	//in which was the count that we counted
	//from the for loop going through "i"	
	for(int j = 0; j < wordsInTitle; ++j)
	{
		//a temp pointer array because every one of
		//our pointers have to be dynamically allocated
		char * temp = new char[50];
		
		//while the song array is not a space and the song
		//array that is passed in from the songs.txt is not
		//a terminating null the comparison happens between
		//our new temp pointer.
		while(songTemp[i] != ' ' && songTemp[i] != '\0')
		{
			//modulo reference it wont copy anything
			//there was a problem where I was over writing
			//the data. Compares the temporary array to
			//the song temporary array
			temp[k] = songTemp[i]; 
			//increments i to the next array
			++i;
			//increments k to the next array
			++k;
		}
		//have the temporary dyanmically allocated array
		//be a terminating null character
		temp[k] = '\0';
		//increments i
		i++;
		//have k just be 0 now because we are done with
		//the k. No segfaults will happen
		k = 0;	
		//have the songName be a new character containing a 
		//string length of temp so we can add it in
		songName[j] = new char[strlen(temp) + 1];
		
		//string copies the temp pointer into the songName
		//array which is in the song lclass
		strcpy(songName[j], temp);
	}

	//gets the artist name
	file.get(artist, (SIZE - 1), ';');
	file.ignore(100, ';');

	//gets the album name
	file.get(album,(SIZE - 1), ';');
	file.ignore(100, ';');

	//gets the number of minutes
	file >> minutes;
	file.ignore(100, ';');

	//gets the number of extractions that the user has made
	file >> extractions;
	file.ignore(100, '\n');

	//returns 1 because we dont want to quit yet
	return 1;
		
}

//displays the song name, artist, album, minutes and extractions
//for each of the songs that have been asked and for how many
//songs there are in the list. 
char song::display()
{
	//displays the song name through a for
	//loop because this is a character of arrays
	//in which we have made to look for each of the song
	//class data members
	cout << "Song name: ";
	for(int i = 0; i < wordsInTitle; ++i)
	{
		cout << songName[i] << ' ';
	}
	cout << endl;

	//display the artist, album, minutes and extracitons
	cout << "Artist : " << artist << endl;
	cout << "Album : " << album << endl;
	cout << "Minutes: " << minutes << endl;
	cout << "Extractions: " << extractions << endl;
}

//a double character function that correcsponds to the 
//index of one of the 10 song names in our songs.txt
//this function was here just to pass in the songName
//so I could get the size of it. The reason why I want
//to return the songName was because I could not grab it
//due to the fact that it was a private data member. Returned
//the songName so we can use it in our global functions
char * song::copySongName(int index)
{
	//returns the songName so I could get the size
	//if it for the hashTable
	return * songName;
}

//an integer function that will return how many words
//were in the song title. This was needed for the 
//data member wordsInTitle because since it was a private
//data member, I could not access it through main,
//and now I can
int song::displayWordsInTitle()
{
	//return the number of the words in the title
	return wordsInTitle; 
}
