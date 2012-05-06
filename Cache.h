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
	bitset<WORD> read(unsigned int address, bool &hitChecker);
	bool write(bitset<WORD> word, unsigned int address, bool &hitChecker);
    unsigned int getTag(unsigned int entryId);
    bitset<WORD> getEntryData(unsigned int entryId, unsigned int offset);
private:
	Cache(void);
	Memory *memory;
	CacheEntry entries[ENTRIES_IN_CACHE];
	void updateAge();
	CacheEntry* getOldestEntry();	
	void replace(bitset<WORD> newWord, unsigned int newAddress);
	void flush(CacheEntry &entry);
};
