#include<iostream>
#include<thread>
#include<chrono>
#include<future>

using namespace std;

mutex m;

bool flag = true;
int a = 0;

void fun() {
    this_thread::sleep_for(chrono::seconds(5));
}

int main(){
    future<void> fut = async(fun);
    future_status status;
    do{
        status = fut.wait_for(chrono::milliseconds(500));
        if(status == future_status::timeout){
            flag = !flag;
            cout<<flag<<endl;
        }
    }while(status!=future_status::ready);
    return 0;
}


