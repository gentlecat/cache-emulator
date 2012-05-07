#pragma once

#include "CacheEntry.h"
#include "Memory.h"

#define ENTRIES_IN_CACHE 8
#define BLOCKS_IN_MEMORY NUM_OF_WORDS/WORDS_IN_BLOCK

using std::bitset;

class Cache
{
public:
	Cache(Memory &linkedMemory);
    bitset<WORD> read(const unsigned int &address, bool &hitChecker);
    bool write(const bitset<WORD> &word, const unsigned int &address, bool &hitChecker);
    unsigned int getTag(const unsigned int &entryId);
    bitset<WORD> getEntryData(const unsigned int &entryId, const unsigned int &offset);
    void randomizeMemory();
private:
	Cache(void);
	Memory *memory;
	CacheEntry entries[ENTRIES_IN_CACHE];
    void fillCache();
	void updateAge();
	CacheEntry* getOldestEntry();	
    void replace(const bitset<WORD> &newWord, const unsigned int &newAddress);
    void flush(CacheEntry &entry);
};
