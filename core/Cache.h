#ifndef CORE_CACHE_H_
#define CORE_CACHE_H_

#include "CacheEntry.h"
#include "Memory.h"

#define ENTRIES_IN_CACHE 8
#define BLOCKS_IN_MEMORY NUM_OF_WORDS / WORDS_IN_BLOCK

using std::bitset;

class Cache
{
public:
    Cache(Memory &linkedMemory);

    bitset<WORD> read(const unsigned int &address, bool &hitChecker);
    bool write(const bitset<WORD> &word, const unsigned int &address, bool &hitChecker);

    inline unsigned int Cache::getTag(const unsigned int &entryId) {
        if (entryId > ENTRIES_IN_CACHE) return NULL;
        else return entries[entryId].getTag();
    }

    inline unsigned int Cache::getAge(const unsigned int &entryId) {
        if (entryId > ENTRIES_IN_CACHE) return NULL;
        return entries[entryId].getAge();
    }

    inline bitset<WORD> Cache::getEntryData(const unsigned int &entryId, const unsigned int &offset) {
        if (entryId > ENTRIES_IN_CACHE) return NULL;
        if (offset > WORDS_IN_BLOCK) return NULL;
        return entries[entryId].readWordDirectly(offset);
    }

    inline void Cache::randomizeMemory() {
        memory->randomize();
        fillCache();
    }

private:
    Cache(void);

    void fillCache();
    void updateAge();
    CacheEntry* Cache::getOldestEntry();
    void replace(const bitset<WORD> &newWord, const unsigned int &newAddress);
    void flush(CacheEntry &entry);

    Memory *memory;
    CacheEntry entries[ENTRIES_IN_CACHE];
};

#endif // CORE_CACHE_H_
