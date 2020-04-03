#include "Song.h"
#include <string>
using namespace std;

    Song::Song()
    {
        title = "";
        artist = "";
        memSize = 0;

    }
    Song::Song(string _artist, string _title, int _memSize)
    {
        artist = _artist;
        title = _title;
        memSize = _memSize;
    }

    string Song::getTitle() const
    {
        return title;
    }

    void Song::setTitle(string _title)
    {
        title = _title;
    }

    string Song::getArtist() const
    {
        return artist;
    }

    void Song::setArtist(string _artist)
    {
        artist = _artist;
    }

    int Song::getSize() const
    {
        return memSize;
    }

    void Song::setSize(int _memSize)
    {
        memSize = _memSize;
    }

    void Song::swap(Song &s2)
    {
        Song temp = s2;     //make copy of s2 before changing
        s2 = *this;
        *this = temp;
    }

    bool Song::operator==(Song const &rhs)
    {
        return (title == rhs.title &&
                artist == rhs.artist &&
                memSize == rhs.memSize);

    }

    bool Song::operator>(Song const &rhs)
    {
        if(artist != rhs.artist)    //if artist fields are identical, check title fields, etc.
        {
            return artist > rhs.artist;    //string compare between two artist fields
        }
        else if(title != rhs.title)
        {
            return title > rhs.title;
        }
        else if(memSize != rhs.memSize)
        {
            return memSize > rhs.memSize;
        }
        else
        {
            return true;
        }

    }


    bool Song::operator < (Song const &rhs)
    {
        if(artist != rhs.artist)
        {
            return artist < rhs.artist;
        }
        else if(title != rhs.title)
        {
            return title < rhs.title;
        }
        else if(memSize != rhs.memSize)
        {
            return memSize < rhs.memSize;
        }
        else
        {
            return true;
        }

    }

    ostream& operator<<(ostream& os, const Song& s)
    {
        os << s.title << ", " << s.artist << ", " << s.memSize;
        return os;
    }
