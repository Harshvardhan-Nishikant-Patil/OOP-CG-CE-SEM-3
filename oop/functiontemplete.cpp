#include <iostream>
using namespace std;

template<typename t> void insertsort(t arr[] , t n){
float  key;
int j , i;
   for ( i = 1; i < n; i++) {
       key = arr[i];
       j = i - 1;

   while (j >= 0 && arr[j] > key) {
       arr[j + 1] = arr[j];
       j = j - 1;
   }
   arr[j + 1] = key; 
   }
}

template<typename t> void selectsort(t arr[] , t n){
int i, j;
int min_idx;


   for (i = 0; i < n - 1; i++) {

       min_idx = i;
       for (j = i + 1; j < n; j++) {
           if (arr[j] < arr[min_idx])
               min_idx = j;
       }

       if (min_idx != i)
           swap(arr[min_idx], arr[i]);
   }
}

template<typename t> void printarray(t arr[] ,t n){
for(int i = 0 ; i < n ; i++){
cout<<arr[i]<<" ";
}
cout<<endl;
}

int main() {
int n;
cout<<"Enter Size"<<endl;
cin>>n;
int arr[n];
cout<<"Enter Array Int Elements"<<endl;
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

float arr2[5]={1.3,5.4,3.4,7.1,0.3};
cout<<"INSERTION SORTING"<<endl;
insertsort <int> (arr,n);
printarray <int> (arr,n);
insertsort <float> (arr2,5);
printarray <float> (arr2,5);


cout<<"SELECTION SORTING"<<endl;
selectsort <int> (arr,n);
printarray <int> (arr,n);
selectsort <float> (arr2,5);
printarray <float> (arr2,5);
}
