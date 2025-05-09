// Write a program to implement and compare various page replacement algorithm.

#include <iostream>
using namespace std;
int main()
{
    int incomingStream[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1};
    int pageFaults = 0;
    int frames = 3;
    int m, n, s, pages;
    pages = sizeof(incomingStream) / sizeof(incomingStream[0]);
    cout << "\nIncoming \t\tFrame 1 \t\tFrame 2 \t\tFrame 3";
    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }

    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;

        if ((pageFaults <= frames) && (s == 0))
        {
            temp[m] = incomingStream[m];
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = incomingStream[m];
        }

        cout << "\n";
        cout << incomingStream[m] << "\t\t\t";
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
            {
                cout << temp[n] << "\t\t\t";
            }
            else
            {
                cout << "- \t\t\t";
            }
        }
    }
    cout << "\n\nTotal Page Faults:\t" << pageFaults;
    cout << "\nTotal Hits :\t" << (pages - pageFaults);
    return 0;
}
