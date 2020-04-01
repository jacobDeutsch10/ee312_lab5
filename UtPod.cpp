
#include "UtPod.h"

using namespace std;

    UtPod::UtPod()
    {
      memSize = MAX_MEMORY;
      songs = NULL;
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
        if (getRemainingMemory() > s.getSize())
        {
            sn = new SongNode;
            sn.next = songs;
            songs = &sn;
            return 0;
        }
        else
        {
            return -1
        }

    }

    int UtPod::getRemainingMemory()
    {
        SongNode *p = songs;
        int total = 0;
        while( p != NULL){
            total += p->s.getSize();
            p = p->next;
        }
        return memSize - total;
    }

    int UtPod::removeSong(Song const &s)
    {
        int ret = NOT_FOUND;
        SongNode *p = songs;
        SongNode *prev = NULL


        while( p->s != s && p != NULL)
        {
            prev = p;
            p = p->next;
        }
        if (p != NULL)
        {
            if (prev == NULL)
            {
                songs = songs->next;
                delete *p;
                ret = SUCCESS;
            }
            else
            {
                prev->next = p->next;
                delete *p;
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
            delete *prev;
            p = p->next;
        }
    }


