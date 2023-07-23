#include<iostream>
#include<thread>
#include<vector>
#include<future>

using namespace std;

int fact(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}


int main(){
    future<int> fut1 = async(launch::async, fact, 4);
    future<int> fut2 = async(launch::async, fact, 5);

    vector<vector<int>> matrixA = {{1, 2}, {3, 4}};
    vector<vector<int>> matrixB = {{5, 6}, {7, 8}};

    int rows_A = matrixA.size();
    int cols_A = matrixA[0].size();
    int cols_B = matrixB[0].size();

    vector<vector<int>> result(rows_A, vector<int>(cols_B, 0));

    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < cols_B; ++j) {
            for (int k = 0; k < cols_A; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    cout<<"Result of Matrix Multiplication:" <<endl;
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout<<endl;
    }
    fut1.wait();
    fut2.wait();
    cout<<"The factorial of 4 is "<<fut1.get()<<endl;
    cout<<"The factorial of 5 is "<<fut2.get()<<endl;
    return 0;
}

