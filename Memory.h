#pragma once

#define MEMORY_CAPACITY 8192    // 1 kilobyte
#define WORDS_IN_MEMORY MEMORY_CAPACITY/WORD

using std::bitset;

class Memory
{
public:
	Memory(void);
	bool getBit(unsigned int id);
	void writeBit(bool state, unsigned int id);
    bitset<WORD> getWord(unsigned int address);
	void writeWord(bitset<WORD> word, unsigned int address);
	void randomize(void);
	void randomize(unsigned int seed);
private:
    bitset<MEMORY_CAPACITY> memory;
};
