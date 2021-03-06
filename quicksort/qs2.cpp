/**
 * @file qs2.cpp
 * @author your name (you@domain.com)
 * @brief 
    here we call part_r to randomly find the pivot and we sort on basis of it
 * @version 0.1
 * @date 2020-12-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

 #include <bits/stdc++.h>

 using namespace std;

 #define ll long long

 vector<ll> v;
/**
 * @brief 
 * basic partitioning and sort the sub array 
 * @param arr 
 * @param low 
 * @param high 
 * @return int 
 */
 ll partition(ll low , ll high)
 {
     ll pivot = v[low];
     // the reason we taking low as pivot is because 
     //in hoare partitioning system low is the way .
     //in part_L we see the rand-th element is exchanged with low and pivot
     //with low
     ll i = low -1;
     ll j =  high+1;

    while(true)
    {
        //cout<<"jjjj";
          do {
            i++;
        } while (v[i] < pivot);
        do {
            j--;
        } while (v[j] > pivot);
        if(i>=j)
        {
            return j;
        }
        swap(v[i],v[j]);
    }
 }

/**
 * @brief rand j selection cause this j desc from high and j will be used as
        pi in quicksort to randomly find the value in mid scale
 *      swaps pivot with end element .
        Hoare low element 
 * @param arr 
 * @param low 
 * @param high 
 * @return int 
 */
ll partition_r(ll low , ll high)
{
    srand(time(NULL));
    ll random = low + rand()%(high-low);

    swap(v[random],v[low]);//we want pivot to become the lowest element 


    return partition(low,high);
}

/**
 * @brief 
 * recursive function to sort 
    it finds pi from partition-r and then uses this to finds the pivot sorts it by swapping 
 * @param arr 
 * @param low 
 * @param high 
 */

void quickSort(ll low,ll high)
{
    //debug
    //cout<<"d";
    if(low < high)
    {
        int pi = partition_r(low , high);
        quickSort(low,pi);
        quickSort(pi+1,high);
    }
}


int main()
{
    vector<vector<ll>> ans;
    ll n;
    
        v.clear();
       
        cin>>n;
        
        for(ll i = 0;i<n;i++)
        {
            ll x;
            cin>>x;
            v.push_back(x);
        }
        random_shuffle(v.begin(),v.end());

        quickSort(0,n-1);

        for(auto l : v)
        {
            cout<<l<<" ";
        }
        cout<<"\n";
        //ans.push_back(v);
        
    

    /*for(auto b : ans)
    {
        for(auto q : b)
        {
            cout<<q<<" ";
        }
        cout<<"\n";
    }*/
}