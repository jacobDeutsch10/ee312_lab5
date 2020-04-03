
#include "UtPod.h"

using namespace std;

    UtPod::UtPod()
    {
      memSize = MAX_MEMORY;
      songs = NULL;
      srand((unsigned)time(0));
    }

    UtPod::UtPod(int size)
    {
        if (size >= MAX_MEMORY || size < 0)
        {
            memSize = 512;
        }
        else
        {
            memSize = size;
        }
        songs = NULL;
    }

    int UtPod::addSong(Song const &s)
    {
        int rem = getRemainingMemory();
        int size = s.getSize();
        if (rem > size)
        {
            SongNode* sn = new SongNode;
            sn->s = s;
            sn->next = songs;
            songs = sn;
            return 0;
        }
        else
        {
            return -1;
        }

    }

    int UtPod::getRemainingMemory()
    {
        SongNode *p = songs;
        int total = 0;
        while( p != NULL){
            total += (int) p->s.getSize();
            p = p->next;
        }
        return memSize - total;
    }

    int UtPod::removeSong(Song const &s)
    {
        int ret = NOT_FOUND;
        SongNode *p = songs;
        SongNode *prev = NULL;


        while( !(p->s == s) && p != NULL)
        {
            prev = p;
            p = p->next;
        }
        if (p != NULL)
        {
            if (prev == NULL)
            {
                songs = songs->next;
                delete p;
                ret = SUCCESS;
            }
            else
            {
                prev->next = p->next;
                delete p;
                ret = SUCCESS;
            }
        }
        return ret;
    }


    void UtPod::clearMemory()
    {
        SongNode *p = songs;
        SongNode *prev = NULL;

        while( p != NULL){
            prev = p;
            delete prev;
            p = p->next;
        }
    }

    void UtPod::shuffle()
    {
        SongNode* p = songs;
        int size = countSongs() - 1;
        while(p != NULL)
        {
            int n = rand() % size;
            p->s.swap(getNthSong(n)->s);
            p = p->next;
        }
    }


    void UtPod::showSongList()
    {
        SongNode* p = songs;

        while(p != NULL)
        {
            cout << p->s << endl;
            p = p->next;
        }
    }

    void UtPod::sortSongList()
    {
        for(UtPod::SongNode *i = songs; i->next != nullptr; i = i->next)
        {
            for(UtPod::SongNode *j = i->next; j != nullptr; j = j->next)
            {
                if(i->s > j->s)
                {
                    SongNode temp = *i;
                    i->s = j->s;
                    j->s = temp.s;
                }
            }
        }
    }


UtPod::SongNode* UtPod::getNthSong(int n)
    {
        int count = 0;
        if(n > countSongs())
        {
            return NULL;
        }

        SongNode* p = songs;

        while(p != NULL && count != n)
        {
            p =  p->next;
            count++;
        }
        return p;
    }

    int UtPod::countSongs()
    {
        int count = 0;

        SongNode* p = songs;

        while(p != NULL)
        {
            p =  p->next;
            count++;
        }
        return count;
    }

    UtPod::~UtPod()
    {
        clearMemory();
    }



