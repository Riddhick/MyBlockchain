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

#endif
