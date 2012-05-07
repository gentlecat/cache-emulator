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

bool CacheEntry::contains(const unsigned int &tag)
{
	if (tag >= firstWordTag && tag < firstWordTag+WORDS_IN_BLOCK) return true;
	return false;	
}

bitset<WORD> CacheEntry::readWord(const unsigned int &tag)
{
	age = 0;
	bitset<WORD> output;
	unsigned int offset = WORD * (tag - firstWordTag);
	for (int bit=0; bit<WORD; bit++) output[bit] = block[offset+bit];
	return output;
}

bitset<WORD> CacheEntry::readWordDirectly(const unsigned int &tag)
{
    age = 0;
    bitset<WORD> output;
    unsigned int offset = WORD * tag;
    for (int bit=0; bit<WORD; bit++) output[bit] = block[offset+bit];
    return output;
}

void CacheEntry::writeWord(const bitset<WORD> &word, const unsigned int &tag)
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
