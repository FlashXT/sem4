// implement SCAN disk scheduling.Program.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void scanScheduling(vector<int> &requests, int head, string direction, int disk_size)
{
    int seekCount = 0;
    vector<int> left, right;
    vector<int> seekSequence;
    if (direction == "left")
        left.push_back(0);
    else if (direction == "right")
        right.push_back(disk_size - 1);
    for (int req : requests)
    {
        if (req < head)
            left.push_back(req);
        else
            right.push_back(req);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    if (direction == "left")
    {
        for (int i = left.size() - 1; i >= 0; i--)
        {
            seekSequence.push_back(left[i]);
            seekCount += abs(head - left[i]);
            head = left[i];
        }
        for (int i = 0; i < right.size(); i++)
        {
            seekSequence.push_back(right[i]);
            seekCount += abs(head - right[i]);
            head = right[i];
        }
    }
    else if (direction == "right")
    {
        for (int i = 0; i < right.size(); i++)
        {
            seekSequence.push_back(right[i]);
            seekCount += abs(head - right[i]);
            head = right[i];
        }
        for (int i = left.size() - 1; i >= 0; i--)
        {
            seekSequence.push_back(left[i]);
            seekCount += abs(head - left[i]);
            head = left[i];
        }
    }
    cout << "\nSeek sequence:\n";
    for (int track : seekSequence)
    {
        cout << "Moved to track: " << track << endl;
    }
    cout << "\nTotal seek operations: " << seekCount << " tracks\n";
}
int main()
{
    int n, head, disk_size;
    string direction;
    vector<int> requests;
    cout << "Enter total number of disk requests: ";
    cin >> n;
    cout << "Enter the disk requests: ";
    for (int i = 0; i < n; i++)
    {
        int req;
        cin >> req;
        requests.push_back(req);
    }

    cout << "Enter initial head position: ";
    cin >> head;
    cout << "Enter disk size (number of tracks): ";
    cin >> disk_size;
    cout << "Enter initial direction (left/right): ";
    cin >> direction;
    scanScheduling(requests, head, direction, disk_size);
    return 0;
}
