#include "stdafx.h"
#include "Memory.h"
#include <time.h>
#include <stdlib.h>

Memory::Memory(void) {
    randomize();
}

bool Memory::getBit(const unsigned int &id) {
    if (id < MEMORY_CAPACITY) {
        return memory[id];
    }
    return NULL;
}

void Memory::writeBit(const bool &state, const unsigned int &id)
{
    if (id < MEMORY_CAPACITY) {
        memory[id] = state;
    }
}

bitset<WORD> Memory::getWord(const unsigned int &address) {
    if (address < WORDS_IN_MEMORY) {
        bitset<WORD> word;
        unsigned int offset = WORD * address;
        for (int bit=0; bit<WORD; bit++) {
            word[bit] = memory[offset+bit];
        }
        return word;
    }
    return NULL;
}

void Memory::writeWord(const bitset<WORD> &word, const unsigned int &address) {
    if (address < WORDS_IN_MEMORY) {
        unsigned int offset = WORD * address;
        for (int bit=0; bit<WORD; bit++) {
            memory[offset+bit] = word[bit];
        }
    }
}

void Memory::randomize(void) {
    srand(time(NULL));
    for (int bit=0; bit<MEMORY_CAPACITY; bit++) {
        memory[bit] = rand() % 2;
    }
}
