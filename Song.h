#ifndef
#define SONG_H

#include <string>

class Song
{
    private:
        string title;
        string artist;
        int memSize;
        static const int MAX_HANDICAP = 99;
    public:
    Song();
    Song(string _title, string _eMail, int _memSize);

    string getTitle() const;
    string setTitle(string title);
    string getArtist() const;
    string setArtist(string Artist);
    string getSize() const;
    string setSize(int memSize);

    void swap(Song &p)
    bool operator == (Song const &rhs)
    bool operator > (Song const &rhs)
    bool operator < (Song const &rhs)




    ~Song();
};

#endif