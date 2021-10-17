#include "block.h"

block::block(int index, TransctionData d, size_t prevHash)
{
    index=index;
    data=d;
    previousHash=prevHash;
    blockHash= generateHash();
}

size_t block::generateHash()
{
    hash<string> hash1;
    hash<size_t> hash2;
    hash<size_t> finalHash;
    
    string toHash=data.senderkey+data.receiverKey+to_string(data.timestamp);
    return finalHash(hash1(toHash)+hash2(previousHash));
}

size_t block::getHash()
{
    return blockHash;
}

size_t block::getPreviousHash()
{
    return previousHash;
}

bool block::isValidHash()
{
    return generateHash()==blockHash;
}
