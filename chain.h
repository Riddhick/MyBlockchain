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

Blockchain::Blockchain()
{
    block genesisBlock=createGenesisBlock();
    chain.push_back(genesisBlock);
}

block Blockchain::createGenesisBlock()
{
    TransctionData data;
    time_t current;
    data.senderkey="This is Genesis";
    data.receiverKey="none";
    data.timestamp=time(&current);


    hash<int> hash1;

    block genesis(0,data,hash1(0));
    return genesis;
}


block *Blockchain::getLatestBlock()
{
    return &chain.back();
}

void Blockchain::addBlock(TransctionData data)
{
    int index=(int)chain.size()-1;
    block newblock(index,data,getLatestBlock()->getHash());
}

bool Blockchain::isChainVaild()
{
    vector<block>::iterator it;
    int chaiLength=(int)chain.size();

    for(it=chain.begin();it!=chain.end();it++)
    {
        block currentBlock=*it;
        if(!currentBlock.isValidHash())
        {
            return false;
        }
        if(chaiLength>1)
        {
            block previousBlock=*(it-1);
            if(currentBlock.getPreviousHash()!=previousBlock.getHash())
            {
                return false;
            }
        }
    }
    return true;
}

void Blockchain::printChain()
{
    vector<block>::iterator it;
    int chaiLength=(int)chain.size();

    for(it=chain.begin();it!=chain.end();it++)
    {
        block currentBlock=*it;
        printf("\n Index:%d",chaiLength-1);
        printf("\n Sender:%s",currentBlock.data.senderkey.c_str());
        printf("\n Receiver:%s",currentBlock.data.receiverKey.c_str());
        printf("\n Time:%ld",currentBlock.data.timestamp);
        printf("\n Block Hash:%zu",currentBlock.getHash());
        printf("\n Previous Block Hash:%zu",currentBlock.getPreviousHash());
    }
}



#endif
