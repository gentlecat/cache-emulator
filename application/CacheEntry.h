#pragma once

#include <stdafx.h>

#define WORDS_IN_BLOCK 4
#define BLOCK_LENGTH WORD*WORDS_IN_BLOCK

using std::bitset;

class CacheEntry
{
public:
	CacheEntry(void);
    CacheEntry(const bitset<BLOCK_LENGTH> &newBlock, const unsigned int &newFirstWordTag);
    bool contains(const unsigned int &tag);
    bitset<WORD> readWord(const unsigned int &tag);
    bitset<WORD> readWordDirectly(const unsigned int &tag);
    void writeWord(const bitset<WORD> &word, const unsigned int &tag);
	bitset<BLOCK_LENGTH> readBlock();
	unsigned int getTag();
	unsigned int getAge();
	void incrementAge();
	bool isModified();
private:
	unsigned int firstWordTag;
	bool modified;
	unsigned int age;
	bitset<BLOCK_LENGTH> block;
};
