# include <iostream>
# include <vector>
using namespace std;


// 25/DA/011
// Aman Mandal
void merge(vector<int> &arr , int st , int mid , int end){
    vector<int> temp;
    int i = st, j = mid+1; 

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx = 0 ; idx<temp.size() ; idx++){
        arr[idx+st] = temp[idx];
    }
}
void mergesort(vector<int> &arr, int st , int end ){
    if(st < end){
        int mid = st + (end - st)/2;

        mergesort(arr , st , mid); // left
        mergesort(arr , mid+1 ,end);

        merge(arr,st,mid,end);
    }
}
int main(){
    vector<int> arr = {6,2,9,7,4,1,0,6};
    mergesort(arr,0,arr.size() - 1);

    for(int val : arr){
        cout << val <<" ";
    }
    cout << endl;
    return 0;
}