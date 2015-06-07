//This file is a class that holds 5 data members in the private
//section and contains only a constructor, a destructor and a
//class function which is the read in function. In all this
//file and the .cpp file wlil readIn from a .txt file
//Both the files (.cpp and .h) files are the read in

#include <iostream>
#include <cctype>
#include <cstring>

//this #include which is unused in most of our programs will
//read in from a file and will also read out
#include <fstream>

using namespace std;

//constant integer for the extractFile's
const int SIZE = 30;

//a class that holds each song when read in from the .txt file
//in the class holds the title of the song, the artist, the album name
//number of minutes and number of extractions in the song. 
class song
{
	public:
		//constructor :initializes all data members
		song();

		//destructor :deallocates all data members 
		~song();

		//opens the file of songs.txt and will also
		//display the the files
		int readIn(ifstream &file);

		//char * copyDataMembers(song & copy);
		char display();		
		
		//a pointer to the song name. We need to to pass in the 
		//size for the hash function
		char * copySongName(int index);

		//we need this function so it can pass the wordsInTitle
		//because our data member is private. 
		int displayWordsInTitle();

		//requres us to know how many words in the array
		//const allows us to not change the value of 
		//the data members in the whole class
		char * getTitle(int index) const; 

	private:
		//data members that will hold each of the 
		//songs members and display them. These data
		//members are ONLY here just to display the
		//.txt of the songs.txt
		char ** songName;
		char * artist;
		char * album;
		int minutes;
		int extractions;

		//we need to know how many words are in the 
		//title so we can pass tat into our 
		//has function. 
		int wordsInTitle;
};
