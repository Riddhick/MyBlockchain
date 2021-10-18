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
    newData.senderkey="sender1";
    newData.receiverKey="receiver1";
    newData.timestamp=time(&currTime);

    MyCoin.addBlock(newData);


    MyCoin.printChain();
}