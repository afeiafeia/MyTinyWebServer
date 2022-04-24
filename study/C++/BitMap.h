#ifndef BITMAP_H
#define BITMAP_H

#include <vector>

class BitMap
{
private:
    std::vector<int> bitTable;
public:
    BitMap(size_t range)
    {
        bitTable.resize(range>>5+1);
    }
    void SetBit(size_t x);

    void RemoveBit(size_t x);

    bool TestBit(size_t x);



};

void BitMap::SetBit(size_t x)
{
    size_t index = x>>5;
    size_t num = x%32;

    bitTable[index]|=(1<<num);
}


void BitMap::RemoveBit(size_t x)
{
    size_t index = x>>5;
    size_t num = x%32;

    bitTable[index]&=~(1<<num);

}

bool BitMap::TestBit(size_t x)
{
    size_t index = x>>5;
    size_t num = x%32;

    return bitTable[index] & (1<<num);
}



#endif