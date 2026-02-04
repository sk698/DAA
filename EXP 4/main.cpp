#include<iostream>
#include<vector>
using namespace std;


void insertionsort(vector<int>& top ){
    for (int i = 1; i < top.size(); i++) {
        int key = top[i];
        int j = i - 1;

        
        while (j >= 0 && top[j] < key) {
            top[j + 1] = top[j];
            j = j - 1;
        }
        top[j + 1] = key;
    }
}


void topk(int a, int k, vector<int>& top){
    if(a < top[k-1]){
        return;
    }
    for(int i = 0; i < k; i++){
        int temp;
        if(a > top[i]){
            temp = top[i];
            top[i] = a;
            topk(temp,k,top);
            break;
        }
    }
}


int OnlineExamSystem(int a, int k, int n, vector<int>& top) {
    if(top.size() < k){
        top.push_back(a);
        if(top.size() == k){
            insertionsort(top);
            return top[k-1];
        }
        return -1;
    }
    else{
        topk(a,k,top);
        return top[k-1];
    }
}




int main() {
    int k = 3;
    vector<int> arr = {10,20,5,15,25,8};
    vector<int> top;

    for(int i = 0; i < arr.size(); i++){
        int a = OnlineExamSystem(arr[i],k,arr.size(),top);
        cout << a << endl;
    }

    return 0;
}