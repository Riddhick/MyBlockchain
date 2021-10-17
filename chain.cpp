#include "chain.h"


Blockchain::Blockchain()
{
    block genesisBlock=createGenesisBlock();
    chain.push_back(genesisBlock);
}

block Blockchain::createGenesisBlock()
{
    TransctionData data;
    time_t current;
    data.senderkey="none";
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