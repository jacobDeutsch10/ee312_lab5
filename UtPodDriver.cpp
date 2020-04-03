/* utPod_driver.cpp
        Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    //sort shuffle and show on empty list
      t.showSongList();
      t.sortSongList();
      t.shuffle();
    //get remaining memory on empty UTPod
    cout<<"remaining mem: "<<t.getRemainingMemory()<<endl;

    //creating a song, removing from empty UtPod and then adding
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.removeSong(s1);
    cout << "result = " << result << endl;

    result = t.addSong(s1);
    cout << "result = " << result << endl;
    //show song list
    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    t.showSongList();

    //repeatedly shuffling and sorting list
    cout<< endl;
    cout<< "SHUFFLED:"<<endl;
    t.shuffle();
    t.showSongList();

    t.sortSongList();
    cout<< endl;
    cout<< "SORTED:"<<endl;
    t.showSongList();


    cout<< endl;
    cout<< "SHUFFLED:"<<endl;
    t.shuffle();
    t.showSongList();

    cout<< endl;
    cout<< "SHUFFLED:"<<endl;
    t.shuffle();

    t.showSongList();
    cout<< endl;
    cout<< "SHUFFLED:"<<endl;
    t.shuffle();

    t.showSongList();

    t.sortSongList();
    cout<< endl;
    cout<< "SORTED:"<<endl;
    t.showSongList();

    cout<< endl;
    cout<< "SHUFFLED:"<<endl;
    t.shuffle();
    t.showSongList();

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    //attempting to overflow memory
    Song s6("Beatles", "Hey Jude6", 272);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;
    t.clearMemory();
    t.showSongList();

    cout << "memory = " << t.getRemainingMemory() << endl;

    //creating smaller UTPod
    UtPod x = UtPod(100);
    cout << "memory = " << t.getRemainingMemory() << endl;

    Song sx1 = Song("Song", "Dude", 1);
    x.addSong(sx1);
    Song sx2 = Song("Song", "Dude", 2);
    x.addSong(sx2);
    Song sx3 = Song("Song", "Dude", 3);
    x.addSong(sx3);
    //shuffle and show list then sort based on memSize
    x.showSongList();
    cout<< endl;
    cout<< "SHUFFLED:"<<endl;

    x.shuffle();


    x.showSongList();

    x.sortSongList();
    cout<< endl;
    cout<< "SORTED:"<<endl;
    x.showSongList();

   // return 0;

}