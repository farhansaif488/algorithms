#include <bits/stdc++>
using namespace std;

#define ll long long

int partition(int arr[],int low , int high)
{
    int pivot = arr[low];
    int i = low - 1 , j = high + 1;
    while(1)
    {
        while(arr[i]<pivot)
        {
            i++;

        }
    
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i>=j)
        {
            return j;
        }
        swap(arr[p],arr[j]);
    }

    
}

int main()
{

}