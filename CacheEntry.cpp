#include "stdafx.h"
#include "CacheEntry.h"

CacheEntry::CacheEntry()
{
	age = 0;
}

CacheEntry::CacheEntry(bitset<BLOCK_LENGTH> newBlock, unsigned int newFirstWordTag)
{
	firstWordTag = newFirstWordTag;
	modified = false;
	age = 0;
	block = newBlock;
}

bool CacheEntry::contains(unsigned int tag)
{
	if (tag >= firstWordTag && tag < firstWordTag+WORDS_IN_BLOCK) return true;
	return false;	
}

bitset<WORD> CacheEntry::readWord(unsigned int tag)
{
	age = 0;
	bitset<WORD> output;
	unsigned int offset = WORD * (tag - firstWordTag);
	for (int bit=0; bit<WORD; bit++) output[bit] = block[offset+bit];
	return output;
}

bitset<WORD> CacheEntry::readWordDirectly(unsigned int tag)
{
    age = 0;
    bitset<WORD> output;
    unsigned int offset = WORD * tag;
    for (int bit=0; bit<WORD; bit++) output[bit] = block[offset+bit];
    return output;
}

void CacheEntry::writeWord(bitset<WORD> word, unsigned int tag)
{
	age = 0;
	unsigned int offset = WORD * (tag - firstWordTag);
	for (int bitId=0; bitId<WORD; bitId++)
		block[offset+bitId] = word[bitId];
	modified = true;
}

bitset<BLOCK_LENGTH> CacheEntry::readBlock() { return block; }

unsigned int CacheEntry::getAge() { return age; }

unsigned int CacheEntry::getTag() {	return firstWordTag; }

void CacheEntry::incrementAge() { age++; }

bool CacheEntry::isModified()
{
	if (modified) return true;
	return false;
}
