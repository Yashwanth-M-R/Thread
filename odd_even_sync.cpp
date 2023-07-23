#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m;
void toEven()
{
    for (int i = 2; i <= 20; i += 2)
    {
        unique_lock<mutex> lock(m);
        cout << i << ' ';
        lock.unlock();
    }
    cout << endl;
}
void toOdd()
{
    for (int i = 1; i <= 20; i += 2)
    {
        unique_lock<mutex> lock(m);
        cout << i << ' ';
        lock.unlock();
    }
    cout << endl;
}
int main()
{
    thread even(toEven);
    thread odd(toOdd);
    even.join();
    odd.join();
    return 0;
}