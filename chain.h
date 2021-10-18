#ifndef Blockchain_h
#define Blockchain_h
#include"block.h"

#include<vector>

using namespace std;

class Blockchain{
    private:
    block createGenesisBlock();

    public:
    vector<block> chain;

    Blockchain();
    
    void addBlock(TransctionData data);
    bool isChainVaild();

    void printChain();


    //for testing 
    block *getLatestBlock();

};


#endif
