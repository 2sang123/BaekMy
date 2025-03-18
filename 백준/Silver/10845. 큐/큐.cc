#include <iostream>
#include <deque>
#include <string>
// -------- queue 원형과 유사하게 ------------
using namespace std;

class MyQueue {
private:
    deque<int> dq;

public:
    void pushq(int a) { 
        dq.push_back(a);  // 뒤에 추가 (std::queue와 동일)
    }

    void popq() {
        if (dq.empty()) {
            cout << -1 << endl;
        } else {
            cout << dq.front() << endl;
            dq.pop_front();  // 앞에서 제거
        }
    }

    void frontq() {
        if (dq.empty()) {
            cout << -1 << endl;
        } else {
            cout << dq.front() << endl;
        }
    }

    void backq() {
        if (dq.empty()) {
            cout << -1 << endl;
        } else {
            cout << dq.back() << endl;
        }
    }

    void emptyq() {
        cout << (dq.empty() ? 1 : 0) << endl;
    }

    int sizeq() {
        return dq.size();
    }
};
int n;
int main() {
    MyQueue q;
    
    cin>>n;
    string cmd;
    while (n--)
    {
    cin >> cmd;
    if (cmd == "push")
    {
        int in;
        cin >> in;
        q.pushq(in);
    }
    else if (cmd == "pop")
    {
        q.popq();
    }
    else if (cmd == "size")
    {
       cout << q.sizeq() << endl;
    }
    else if (cmd == "front")
    {
        q.frontq();
    }
    else if (cmd == "back")
    {
        q.backq();
    }
    else if (cmd == "empty")
    {
        q.emptyq();
    }
    }
}
