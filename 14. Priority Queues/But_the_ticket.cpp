#include <iostream>
#include <vector>
using namespace std;

#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k)
{
    // Write your code here
    queue<int> q;
    priority_queue<int> pq;
    for (int i{0}; i < n; i++)
    {
        pq.push(arr[i]);
        q.push(i);
    }

    int time = 1;

    while (q.size() != 0)
    {
        if (arr[q.front()] == pq.top())
        {
            if (q.front() == k)
                break;
            time++;
            q.pop();
            pq.pop();
        }
        else
        {
            q.push(q.front());
            q.pop();
        }
    }

    return time;
}



int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << buyTicket(arr, n, k);

    delete[] arr;
}