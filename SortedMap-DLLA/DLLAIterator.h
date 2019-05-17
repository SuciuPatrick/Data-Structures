//
// Created by Suciu Patrick on 2019-04-21.
//

#ifndef LABORATORY4_DLLAITERATOR_H
#define LABORATORY4_DLLAITERATOR_H

#include "DLLA.h"
#include <exception>

class SortedMap;
class DLLAIterator {
protected:
    DLLA toIterate;
    int pos;
public:
    DLLAIterator(DLLA& toIterate);
    DLLAIterator(SortedMap &map);
    bool valid();

    void next();

    TElem getCurrent();

    void first();
    void previous();
    ~DLLAIterator();
};


#endif //LABORATORY4_DLLAITERATOR_H
