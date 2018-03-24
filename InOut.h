#ifndef MOSTY_INOUT_H
#define MOSTY_INOUT_H

#include <vector>
#include <iostream>
#include "graf.h"




class InOut {
    Graf graf;

public:

    InOut()
    {
        size_t newSize = readSize();
        graf.resize(newSize);
    }

    ~InOut()
    {

    }

    void printBridges ()
    {
        size_t first;
        readVertices();
        auto vec = graf.hasBridges();

        for( auto it =0,i=0;it <vec.size();++i,it++)
        {
            if(i%2==0)
                first = vec[it];
            if(i%2 ==1)
                std::cout<<first<<" " << vec[it]<< std::endl;

        }

    }


    size_t readSize()
    {
        size_t i;
        std::cin>>i;
        return i;
    }

    void readVertices()
    {
        size_t x, y;
        while(std::cin>>x>>y)
        {

            graf.addVertices(x,y);
        }


    }

};


#endif //MOSTY_INOUT_H
