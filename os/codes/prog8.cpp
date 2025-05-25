// implementation of FIFO page replacement algorithm in C++

#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void fifoPageReplacement(const vector<int> &pages, int frameCount)
{
    unordered_set<int> memory;
    queue<int> pageQueue;

    int pageFaults = 0;

    for (int page : pages)
    {
        if (memory.find(page) == memory.end())
        {
            if (memory.size() == frameCount)
            {
                int oldestPage = pageQueue.front();
                pageQueue.pop();
                memory.erase(oldestPage);
            }
            memory.insert(page);
            pageQueue.push(page);
            pageFaults++;
            cout << "Page " << page << " caused a page fault." << endl;
        }
        else
        {
            cout << "Page " << page << " is already in memory." << endl;
        }
    }
    cout << "Total page faults: " << pageFaults << endl;
}

int main()
{
    int n, frames;
    cout << "Enter the number of pages: ";
    cin >> n;
    vector<int> pages(n);
    cout << "Enter the page reference string: ";

    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> frames;
    fifoPageReplacement(pages, frames);
    return 0;
}
