#include <iostream>
#include <vector>
using namespace std;
class MaxHeap{
  public:
  vector<int> heap;
  void heapifyup(int i)
  {
      while(i>0)
      {
          int dad = (i-1)/2;
          if(heap[i]>heap[dad])
          {
              swap(heap[i],heap[dad]);
              i = dad;
          }
          else break;
      }
  }
  void heapifydown(int i)
  {
      int size = heap.size();
      while(i < size)
      {
          int left = 2*i+1;
          int right = 2*1+2;
          int large = i;
          if(left < size && heap[left]>heap[large])
          large = left;
          if(right < size && heap[right]>heap[large])
          large = right;
          if(large != i)
          {
              swap(heap[large],heap[i]);
              i = large;
          }
          else break;
      }
  }
  void insert(int a)
  {
      heap.push_back(a);
      heapifyup(heap.size()-1);
  }
  void deleteMax()
  {
      if(heap.empty())
      {
          cout << "Empty";
          return;
      }
      cout << "Deleting max: " << heap[0] << endl;
      heap[0] = heap.back();
      heap.pop_back();
      heapifydown(0);
  }
  void display()
  {
      for(int i: heap)
      {
          cout << i << " ";
      }
  }
};
int main()
{
    MaxHeap m;
    m.insert(5);
    m.insert(53);
    m.insert(69);
    m.insert(49);
    m.insert(11);
    
    cout << "Heap after insertions: ";
    m.display();
    m.deleteMax();
    cout << "Heap after deleting max: ";
    m.display();

    return 0;
}