#include <iostream>
#include "Vector.h"
#include <cstdlib>
const int N=10;
using namespace std;


template <typename Item>
class BinaryHeap{
    public:
    
    BinaryHeap(){
        Item sentinel=Item();
        vec.push_back(sentinel);
        setsize();
    }

    bool isEmpty(){
        return currentSize==0;
    }

    int getsize(){
        return currentSize;
    }

    void setsize(){
        currentSize=0;
    }

    void insert(Item v){
        vec.push_back(v);
        currentSize++;
        swim(currentSize);
    }


    Item delMax(){
        Item temp=vec[1];
        exch(1,currentSize--);
        sink(1);
        return temp;
    }

    void show(){
        for(int i=1;i<=currentSize;i++){
            cout<<" "<<vec[i];
        }
        cout<<endl;
    }

    private:

    Vector<Item> vec;

    int    currentSize;


    bool Less(Item v,Item w){
        return v<w;
    }


    void exch(int i,int j){
        Item tmp=vec[i];
        vec[i]=vec[j];
        vec[j]=tmp;
    }


    void swim(int k){
        while(k>1&&Less(vec[k/2],vec[k])){
            exch(k,k/2);
            k=k/2;
        }
    }

    void sink(int k){
        while(2*k<=currentSize){
            int j=2*k;
            if(j<currentSize&&Less(vec[j],vec[j+1]))
            j++;
            if(!Less(vec[k],vec[j]))
            break;
            exch(k,j);
            k=j;
        }
    }

};



