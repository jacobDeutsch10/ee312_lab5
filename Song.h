#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
using namespace std;
class Song
{
    private:
        string title;
        string artist;
        int memSize;
        static const int MAX_HANDICAP = 99;
    public:
    Song();
    Song(string _artist, string _title, int _memSize);

    string getTitle() const;
    void setTitle(string title);
    string getArtist() const;
    void setArtist(string Artist);
    int getSize() const;
    void setSize(int memSize);

    void swap(Song &p);
    bool operator == (Song const &rhs);
    bool operator > (Song const &rhs);
    bool operator < (Song const &rhs);
    friend std::ostream& operator<<(std::ostream& os, const Song& s);


};




#endif