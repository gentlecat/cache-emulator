#include "stdafx.h"
#include "CacheEntry.h"

CacheEntry::CacheEntry()
{
    age = 0;
}

CacheEntry::CacheEntry(const bitset<BLOCK_LENGTH> &newBlock, const unsigned int &newFirstWordTag)
{
    firstWordTag = newFirstWordTag;
    modified = false;
    age = 0;
    block = newBlock;
}

bitset<WORD> CacheEntry::readWord(const unsigned int &tag) {
    age = 0;
    bitset<WORD> output;
    unsigned int offset = WORD * (tag - firstWordTag);
    for (int bit=0; bit<WORD; bit++) output[bit] = block[offset+bit];
    return output;
}

bitset<WORD> CacheEntry::readWordDirectly(const unsigned int &tag) {
    bitset<WORD> output;
    unsigned int offset = WORD * tag;
    for (int bit=0; bit<WORD; bit++) output[bit] = block[offset+bit];
    return output;
}

void CacheEntry::writeWord(const bitset<WORD> &word, const unsigned int &tag) {
    age = 1;
    unsigned int offset = WORD * (tag - firstWordTag);
    for (int bitId=0; bitId<WORD; bitId++) block[offset+bitId] = word[bitId];
    modified = true;
}
