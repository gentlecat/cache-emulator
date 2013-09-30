#ifndef CORE_CACHE_ENTRY_H_
#define CORE_CACHE_ENTRY_H_

#include "stdafx.h"

#define WORDS_IN_BLOCK 4
#define BLOCK_LENGTH WORD * WORDS_IN_BLOCK

using std::bitset;

class CacheEntry
{
public:
    CacheEntry(void);
    CacheEntry(const bitset<BLOCK_LENGTH> &newBlock, const unsigned int &newFirstWordTag);

    bitset<WORD> CacheEntry::readWord(const unsigned int &tag);
    bitset<WORD> CacheEntry::readWordDirectly(const unsigned int &tag);
    void CacheEntry::writeWord(const bitset<WORD> &word, const unsigned int &tag);

    bool CacheEntry::contains(const unsigned int &tag) {
        if (tag >= firstWordTag && tag < firstWordTag+WORDS_IN_BLOCK) return true;
        return false;
    }

    inline bitset<BLOCK_LENGTH> CacheEntry::readBlock() { return block; }

    inline unsigned int CacheEntry::getTag() {	return firstWordTag; }

    inline unsigned int CacheEntry::getAge() { return age; }

    inline void CacheEntry::incrementAge() { age++; }

    inline bool CacheEntry::isModified() {
        if (modified) return true;
        return false;
    }

private:
    unsigned int firstWordTag;
    bool modified;
    unsigned int age;
    bitset<BLOCK_LENGTH> block;
};

#endif // CORE_CACHE_ENTRY_H_
