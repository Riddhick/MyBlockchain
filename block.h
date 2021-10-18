#ifndef Block_h
#define Block_h
#include <ctime>
#include <string>



using namespace std;

struct TransctionData{
    string senderkey;
    string receiverKey;
    time_t timestamp;
};

class block{
    private:
    int index;
    size_t blockHash;
    size_t previousHash;
    size_t generateHash();

    public:
    block(int index, TransctionData d, size_t prevHash);
    TransctionData data;
    size_t getHash();
    size_t getPreviousHash();
    bool isValidHash();
};


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
#endif
