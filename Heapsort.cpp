    
#include <iostream>
#include <vector>

using namespace std;

void Swap(std::vector<int>& vHeap, std::vector<int>::size_type i, std::vector<int>::size_type j)
{
    if(i == j)
        return;

    int temp;
    temp = vHeap[i];
    vHeap[i] = vHeap[j];
    vHeap[j] = temp;
}

void Sift(std::vector<int>& vHeap, const std::vector<int>::size_type heapSize, const std::vector<int>::size_type siftNode)
{
    std::vector<int>::size_type i, j;

    j = siftNode;
    do
    {
        i = j;
        if(((2*i + 1) < heapSize) && vHeap[j] < vHeap[2*i + 1])
            j = 2*i + 1;
        if(((2*i + 2) < heapSize) && vHeap[j] < vHeap[2*i + 2])
            j = 2*i + 2;

        Swap(vHeap, i, j);
    }
    while(i != j);
}

void MakeInitialHeap(std::vector<int>& vHeap)
{
    for(int i = vHeap.size() - 1; i >= 0; --i)
    {
        Sift(vHeap, vHeap.size(), i);
    }
}

void HeapSort(std::vector<int>& vHeap)
{
    MakeInitialHeap(vHeap);
    for(std::vector<int>::size_type i = vHeap.size()-1; i > 0; --i)
    {
        Swap(vHeap, i, 0);
        Sift(vHeap, i, 0);
    }
}

int main(int argc, char *argv[])
{
    std::vector<int>::size_type size;
    std::vector<int> vHeap;
    std::cout<<"How many numbers to be sorted?";
    std::cin>>size;

    std::cout<<"Enter the numbers to be sorted:-\n\n";

    int value;
    for(std::vector<int>::size_type i = 0; i < size; ++i)
    {
        std::cout<<"Enter number "<<i+1<<":";
        std::cin>>value;
        vHeap.push_back(value);
    }    

    HeapSort(vHeap);    
    
    for(std::vector<int>::size_type i = 0; i < vHeap.size(); ++i)
    {
        std::cout<<vHeap[i]<<"\t";
    }
    
    return 0;
}


