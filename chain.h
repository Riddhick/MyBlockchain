#pragma once
#include <iostream>
#include <string>
#include<vector>
#include "block.h"
using namespace std;

class Blockchain{
    private:
    block createGenesisBlock();

    public:
    vector<block> chain;

    Blockchain();
    
    void addBlock(TransctionData data);
    bool isChainVaild();


    //for testing 
    block *getLatestBlock();

};