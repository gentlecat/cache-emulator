#include "stdafx.h"
#include "Cache.h"

Cache::Cache(Memory &linkedMemory)
{
    memory = &linkedMemory;
    fillCache();
}

bitset<WORD> Cache::read(const unsigned int &address, bool &hitChecker)
{
	if (address >= WORDS_IN_MEMORY) return NULL;
	updateAge();
	bitset<WORD> output;
	bool found = false;
	int curEntry = 0;
	for (int current=0; current<ENTRIES_IN_CACHE; current++)
	{
		curEntry++;
		if (entries[current].contains(address))
		{
			found = true;
			output = entries[current].readWord(address);
			break;
		}
	}
	if (!found)
	{
		output = memory->getWord(address);
		replace(output, address);
	}
	hitChecker = found;
	return output;
}

bool Cache::write(const bitset<WORD> &word, const unsigned int &address, bool &hitChecker)
{
	if (address >= WORDS_IN_MEMORY) return false;
	updateAge();
	bool found = false;
	int curEntry = 0;
	for (int current=0; current<ENTRIES_IN_CACHE; current++)
	{
		curEntry++;
		if (entries[current].contains(address))
		{
			found = true;
			entries[current].writeWord(word, address);
			break;
		}
	}
	if (!found) replace(word, address);
	hitChecker = found;
	return true;
}

unsigned int Cache::getTag(const unsigned int &entryId)
{
    if (entryId > ENTRIES_IN_CACHE) return NULL;
    return entries[entryId].getTag();
}

bitset<WORD> Cache::getEntryData(const unsigned int &entryId, const unsigned int &offset)
{
    if (entryId > ENTRIES_IN_CACHE) return NULL;
    if (offset > WORDS_IN_BLOCK) return NULL;
    return entries[entryId].readWordDirectly(offset);
}

void Cache::randomizeMemory()
{
    memory->randomize();
    fillCache();
}

void Cache::replace(const bitset<WORD> &newWord, const unsigned int &newAddress)
{
	// Finding beginning of the block
	unsigned int firstWordId = newAddress;
	while (firstWordId % WORDS_IN_BLOCK) firstWordId--;
	unsigned int memoryOffset = newAddress * WORD;

	// Finding oldest entry and flushing it to memory	
	CacheEntry *oldest = getOldestEntry();
	if (oldest->isModified()) flush(*oldest);

	// Copying block from memory
	bitset<BLOCK_LENGTH> newBlock;
	for (int bit=0; bit<BLOCK_LENGTH; bit++)
		newBlock[bit] = memory->getBit(memoryOffset+bit);
	CacheEntry newEntry(newBlock, firstWordId);

	// Writing new word
	newEntry.writeWord(newWord, newAddress);

	// Replacing oldest cache entry
	*oldest = newEntry;
}

CacheEntry* Cache::getOldestEntry()
{
	CacheEntry *oldest = &entries[0];
	for (int entryId=1; entryId<ENTRIES_IN_CACHE; entryId++)
		if (oldest->getAge() > entries[entryId].getAge())
			oldest = &entries[entryId];
	return oldest;
}

void Cache::fillCache()
{
    for (int entryId=0, tag=0, offset=0; entryId<ENTRIES_IN_CACHE;
        entryId++, tag=entryId*WORDS_IN_BLOCK, offset=entryId*BLOCK_LENGTH)
    {
        bitset<BLOCK_LENGTH> newBlock;
        for (int bit=0; bit<BLOCK_LENGTH; bit++)
            newBlock[bit] = memory->getBit(offset+bit);
        entries[entryId] = CacheEntry(newBlock, tag);
    }
}

void Cache::updateAge()
{
	for (int current=0; current<ENTRIES_IN_CACHE; current++)
		entries[current].incrementAge();
}

void Cache::flush(CacheEntry &entry)
{
	bitset<BLOCK_LENGTH> block = entry.readBlock();
	unsigned int offset = BLOCK_LENGTH*entry.getTag();
	for (int bit=0; bit<WORDS_IN_BLOCK; bit++)
		memory->writeBit(block[bit], offset+bit);
}
