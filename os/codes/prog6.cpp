
#include <iostream>
using namespace std;

void first();
void best();
void worst();

int main()
{
    int choice;
    do
    {
        cout << "\nThis is the program for performing different menory allocation strategies:" << endl;
        cout << "1. First fit\n2. Best fit\n3. Worst fit" << endl;
        cout << "0. exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("clear");
            first();
            break;
        case 2:
            system("clear");
            best();
            break;

        case 3:
            system("clear");
            worst();
            break;

        default:
            cout << "Invalid input: Please try again" << endl;
        }
    } while (choice != 0);
    return 0;
}

void first()
{
    int bsize[10], psize[10], bno, pno, flags[10], allocation[10], i, j;
    for (i = 0; i < 10; i++)
    {
        flags[i] = 0;
        allocation[i] = -1;
    }
    cout << "Enter no. of blocks: ";
    cin >> bno;
    cout << "\nEnter size of each block: ";
    for (i = 0; i < bno; i++)
        cin >> bsize[i];
    cout << "\nEnter no. of processes: ";
    cin >> pno;
    cout << "\nEnter size of each process: ";
    for (i = 0; i < pno; i++)
    {
        cin >> psize[i];
    }
    for (i = 0; i < pno; i++)
    {
        for (j = 0; j < bno; j++)
        {
            if (flags[j] == 0 && bsize[j] >= psize[i])
            {
                allocation[j] = i;
                flags[j] = 1;
                break;
            }
        }
    }
    // display allocation details
    cout << "\nBlock no.\tsize\t\tprocess no.\t\tsize";
    for (i = 0; i < bno; i++)
    {
        cout << "\n"
             << i + 1 << "\t\t" << bsize[i] << "\t\t";
        if (flags[i] == 1)
        {
            cout << allocation[i] + 1 << "\t\t\t" << psize[allocation[i]];
        }
        else
        {
            cout << "Not allocated";
        }
    }
}

void best()
{
    int fragment[20], b[20], p[20], i, j, nb, np, temp, lowest = 9999;
    static int barray[20], parray[20];
    cout << "\n\t\t\tMemory Management Scheme - Best Fit";
    cout << "\nEnter the number of blocks:";
    cin >> nb;
    cout << "Enter the number of processes:";
    cin >> np;
    cout << "\nEnter the size of the blocks:-\n";
    for (i = 1; i <= nb; i++)
    {
        cout << "Block no." << i << ":";
        cin >> b[i];
    }
    cout << "\nEnter the size of the processes :-\n";
    for (i = 1; i <= np; i++)

    {
        cout << "Process no. " << i << ":";
        cin >> p[i];
    }
    for (i = 1; i <= np; i++)
    {
        for (j = 1; j <= nb; j++)
        {
            if (barray[j] != 1)
            {
                temp = b[j] - p[i];
                if (temp >= 0)
                {
                    if (lowest > temp)
                    {
                        parray[i] = j;
                        lowest = temp;
                    }
                }
            }
        }
        fragment[i] = lowest;
        barray[parray[i]] = 1;
        lowest = 10000;
    }
    cout << "\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment";
    for (i = 1; i <= np && parray[i] != 0; i++)
    {
        cout << "\n"
             << i << "\t\t" << p[i] << "\t\t"
             << parray[i] << "\t\t" << b[parray[i]] << "\t\t" << fragment[i];
    }
}

void worst()
{
    int nBlocks, nProcess, blockSize[20], processSize[20];
    cout << " Enter the number of blocks: ";
    cin >> nBlocks;
    cout << " Enter the number of processes: ";
    cin >> nProcess;
    cout << " Enter the size of " << nBlocks << " blocks: ";
    for (int i = 0; i < nBlocks; i++)
        cin >> blockSize[i];
    cout << " Enter the size of " << nProcess << " processes: ";
    for (int i = 0; i < nProcess; i++)
        cin >> processSize[i];
    for (int i = 0; i < nProcess; i++)
    {
        int max = blockSize[0];
        int pos = 0;
        for (int j = 0; j < nBlocks; j++)
            if (max < blockSize[j])
            {
                max = blockSize[j];
                pos = j;
            }
        if (max >= processSize[i])
        {

            cout << "\nProcess " << i + 1 << " is allocated to block " << pos + 1;
            blockSize[pos] = blockSize[pos] - processSize[i];
        }
        else
        {
            cout << "\nProcess " << i + 1 << " can't be allocated";
        }
    }
}
