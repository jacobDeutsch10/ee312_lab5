#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
using namespace std;

//Song class declaration
class Song
{
    private:
        string title;
        string artist;
        int memSize;
        static const int MAX_HANDICAP = 99;

    public:

        //default constructor
        //set title and artist to empty string, memSize to 0
        Song();

        //constructor with all song parameters
        //fills in private fields of Song s with input parameters
        //input parms - string artist, string title, int memSize
        //output parms - none
        Song(string _artist, string _title, int _memSize);

        //function getTitle
        //input parms - none
        //output parms - title of Song
        string getTitle() const;

        //function setTitle
        //input parms - new string title of Song
        //output parms - none
        void setTitle(string title);

        //function getArtist
        //input parms - none
        //output parms - artist of Song
        string getArtist() const;

        //function setArtist
        //input parms - new artist of Song
        //output parms - none
        void setArtist(string Artist);

        //function getSize
        //input parms - none
        //output parms - int memSize
        int getSize() const;

        //function setSize
        //input parms - new memSize of Song
        //output parms - none
        void setSize(int memSize);

        //function swap
        //swaps current Song with another Song
        //input parms - 2nd Song argument
        void swap(Song &p);

        //== operator overload
        //will return true if all private fields of both songs are identical, otherwise false
        //input parms - 2nd Song argument
        //output parms - boolean true/false
        bool operator == (Song const &rhs);

        //> operator overload
        //will compare if *this is greater than 2nd Song
        //compare titles if artists are identical, memSize if artists and titles are identical
        //input parms - 2nd Song argument
        //output parms - boolean true/false
        bool operator > (Song const &rhs);

        //< operator overload
        //will compare if *this is less than 2nd Song
        //compare titles if artists are identical, memSize if artists and titles are identical
        //input parms - 2nd Song argument
        //output parms - boolean true/false
        bool operator < (Song const &rhs);
        friend std::ostream& operator<<(std::ostream& os, const Song& s);

};




#endif