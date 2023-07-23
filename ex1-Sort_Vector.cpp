#include<iostream>
#include<thread>
#include<mutex>
#include<vector>
#include<algorithm>

using namespace std;

mutex m;

vector<int> v1;

void sortA(){
    m.lock();
    sort(v1.begin(), v1.end());
    cout<<"Printing the values of vector sorted in Ascending Order"<<endl;
    for(auto a:v1){
        cout<<a<<" ";
    }
    cout<<endl;
    m.unlock();
}

void sortD(){
    m.lock();
    sort(v1.begin(), v1.end(), greater<int>());
    cout<<"Printing the values of vector sorted in Descending Order"<<endl;
    for(auto a:v1){
        cout<<a<<" ";
    }
    m.unlock();
}

int main(){
    v1 = {10, 13, 2, 67, 2, 25, 19, 15};
    thread th1(sortA);
    thread th2(sortD);

    th1.join();
    th2.join();

    return 0;
}

