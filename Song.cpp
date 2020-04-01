
#include "Song.h"

using namespace std;

    Song::Song()
    {
        title = "";
        artist = "";
        memSize = 0;

    }
    Song::Song(string _title, string _eMail, int _memSize)
    {
        title = _title;
        artist = _eMail;
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

    string Song::getSize() const
    {
        return memSize;
    }

    void Song::setSize(int _memSize)
    {
        memSize = _memSize;
    }

    void Song::swap(Song &s2)
    {
        Song temp = s2;
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
        if(artist != rhs.artist)
        {
            return artist > rhs.artist;
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
