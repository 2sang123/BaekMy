#include <iostream>
#include <vector>
#include <string>
using namespace std;

int* arr = nullptr;
int s = 0;

void pushq(int a)
{
    int nSize = s + 1;
    int* newArr = new int[nSize];

    if (arr != nullptr)
    {
        for (int i = 0; i < s; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
    }
    newArr[s] = a;
    arr = newArr;
    s = nSize;
}

void popq()
{
    if (s <= 0 || arr == nullptr)
    {
        cout << -1 << endl;
        return;
    }
    cout << arr[0] << endl;
    int nSize = s -1;
    if (nSize == 0)
    {
        delete[] arr;
        arr = nullptr;
        s = 0;
        return;
    }
    
    int* newArr = new int[nSize];
    for (int i = 0; i < nSize; i++)
    {
        newArr[i] = arr[i+1];
    }
    delete[] arr;
    arr = newArr;
    s = nSize;
}

void frontq()
{
    if (s <= 0)
    {
        cout << -1 << endl;
        return;
    }
    cout << arr[0] << endl;
}

void backq()
{
    if (s <= 0)
    {
        cout << -1 << endl;
        return;
    }
    else cout << arr[s-1] << endl;
}

void emptyq()
{
    if (s <= 0)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}

int sizeq()
{
    return s;
}
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    string cmd;
    while (n--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            int in;
            cin >> in;
            pushq(in);
        }
        else if (cmd == "pop")
        {
            popq();
        }
        else if (cmd == "size")
        {
            cout << sizeq() << endl;
        }
        else if (cmd == "front")
        {
            frontq();
        }
        else if (cmd == "back")
        {
            backq();
        }
        else if (cmd == "empty")
        {
            emptyq();
        }
    }
}
