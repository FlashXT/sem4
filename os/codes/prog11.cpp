// implement Look disk scheduling.Program.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void lookScheduling(vector<int> &requests, int head, string direction)
{
    int seekCount = 0;
    vector<int> left, right;
    vector<int> seekSequence;

    for (int req : requests)
    {
        if (req < head)
            left.push_back(req);
        else if (req > head)
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
    int n, head;
    string direction;
    vector<int> requests;
    cout << "Enter number of disk requests: ";
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
    cout << "Enter initial direction (left/right): ";
    cin >> direction;
    lookScheduling(requests, head, direction);

    return 0;
}
