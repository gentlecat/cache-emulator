#ifndef CORE_MEMORY_H_
#define CORE_MEMORY_H_

#define MEMORY_CAPACITY 8192 // 1 kilobyte
#define WORDS_IN_MEMORY MEMORY_CAPACITY / WORD

using std::bitset;

class Memory
{
public:
    Memory(void);

    bool getBit(const unsigned int &id);
    void writeBit(const bool &state, const unsigned int &id);
    bitset<WORD> getWord(const unsigned int &address);
    void writeWord(const bitset<WORD> &word, const unsigned int &address);
    void randomize(void);

private:
    bitset<MEMORY_CAPACITY> memory;
};

#endif // CORE_MEMORY_H_
