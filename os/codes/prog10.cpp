// implement C-look disk scheduling

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void clookScheduling(vector<int> &requests, int head, int diskSize)
{
    int totalSeekCount = 0;
    int distance, curTrack;
    vector<int> left, right;
    for (int i = 0; i < requests.size(); i++)
    {
        if (requests[i] < head)
        {
            left.push_back(requests[i]);
        }
        else
        {
            right.push_back(requests[i]);
        }
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for (int i = 0; i < right.size(); i++)
    {
        curTrack = right[i];
        distance = abs(curTrack - head);
        totalSeekCount += distance;
        head = curTrack;
        cout << "Moved to track: " << head << endl;
    }

    head = left.back();
    totalSeekCount += abs(head - right.back());
    cout << "Moved to track: " << head << endl;
    for (int i = left.size() - 1; i >= 0; i--)
    {
        curTrack = left[i];
        distance = abs(curTrack - head);
        totalSeekCount += distance;
        head = curTrack;
        cout << "Moved to track: " << head << endl;
    }
    cout << "Total seek time = " << totalSeekCount << " tracks" << endl;
}
int main()
{
    int diskSize = 200;
    int head;
    int n;
    vector<int> requests;
    cout << "Enter the number of disk requests: ";
    cin >> n;
    cout << "Enter the disk requests: ";
    for (int i = 0; i < n; i++)
    {
        int request;
        cin >> request;
        requests.push_back(request);
    }
    cout << "Enter the initial head position: ";
    cin >> head;
    clookScheduling(requests, head, diskSize);
    return 0;
}
