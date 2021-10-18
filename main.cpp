#include"chain.h"
#include"block.h"

#include <iostream>
#include <string>
#include<ctime>

int main()
{
    Blockchain MyCoin;
    TransctionData newData;
    time_t currTime;
    newData.senderkey="riddhick";
    newData.receiverKey="suchetan";
    newData.timestamp=time(&currTime);

    MyCoin.addBlock(newData);

    MyCoin.printChain();
}