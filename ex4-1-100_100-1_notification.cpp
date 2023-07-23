#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<chrono>

using namespace std;

mutex m;
condition_variable cv;
bool ready = false;

void counter(int i, int j){
    unique_lock<mutex> lock(m);
    cv.wait(lock, []{return ready;});
    if(i>j){
        for(int a=i; a>=j; a--){
            cout<<a<<" ";
        }
    }
    else{
        for(int a=i; a<=j; a++){
            cout<<a<<" ";
        }
    }
    cout<<endl;
}

int main(){
    thread worker1(counter, 1, 100);
    thread worker2(counter, 100, 1);

    this_thread::sleep_for(chrono::seconds(2));
    {
        lock_guard<mutex> lock(m);
        ready = true;
    }
    cv.notify_all();
    worker1.join();
    worker2.join();
    return 0;
}

