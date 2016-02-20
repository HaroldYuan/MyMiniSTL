#include "BinaryHeap.h"

int main(){
    BinaryHeap<int> bp;
    srand((unsigned)time(NULL));
    for(int i=0;i<N;i++){
        int num=rand()%100;
        bp.insert(num);
    }
    bp.show();
    bp.delMax();
    bp.show();
}

