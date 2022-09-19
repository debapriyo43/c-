#include <iostram>
#include <bits/stdc++.h>
using namespace std;
class kQueues
{
public:
    int n;
    int freespot;
    int k;
    int *front; //-1 -1
    int *rear;  // -1
    int *arr;   // values will be stored here
    int *next;  // it will store the value of the next freespot or the first freespot
public:
    kQueues(int n, int k)
    {
        this->n = n;
        this->k = k;
        front = new int[k]; // it will store the first/ front indexes of the k queues
        rear = new int[k];  // it will store the last/rear indexes of the k queues
        for (int i = 0; i < k; i++)
        {
            front[i] = -1; // initily store -1 at all elements
            reat[i] = -1;
        }
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        arr = new int[n];
        freespot = 0;
    }
    void enqueue(int data, int qn)
    {
        if (freespot == -1)
        {
            cout << "No freespot available" << endl;
            return;
        }
        // find index
        int index = freespot;
        // update freespot
        freespot = next[freespot];
        // check wheather it is first element or not
        if (front[qn - 1] == -1)
        {
            front[qn - 1] = index;
        }
        // if other elements present in the queue
        else
        {
            next[rear[qn - 1]] = index;
        }
        // update next
        next[index] = -1;
        // update rear
        rear[qn - 1] = index;
        // insert value to the array
        arr[index] = data;
    }
    int dequeue(int qn)
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        // find index to pop
        int index = front[qn - 1];
        // free slot ko aage badhao
        front[qn - 1] = next[index];
        // free slot ko manage karo
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
int main()
{
    kQueues(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 1);
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;
}