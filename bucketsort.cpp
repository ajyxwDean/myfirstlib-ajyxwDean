#include <bits/stdc++.h>
using namespace std;
 
void bucketSort(int data[], int len)
{
    //find minx max value of the array data
    int min = data[0];
    int max = min;
    for(int i = 1; i < len; i++)
    {
        if(data[i] < min)
            min = data[i];
 
        if(data[i] > max)
            max = data[i];
    }
 
    //get the bucket counts;
    int bucketCounts = (max-min)/len + 1;
 
    vector<vector<int>> bucketArrays;
    for(int i = 0; i < bucketCounts; i++)
    {
        //position 0 used to keep the data count store in this bucket
        vector<int> bucket;
        bucketArrays.push_back(bucket);
    }
 
    //assign each value to bucket arrays.
    for(int j = 0; j < len; j++)
    {
        int num = (data[j]-min)/len;
        bucketArrays[num].push_back(data[j]);
    }
 
    //sort each bucket
    for(int i = 0; i < bucketCounts; i++)
    {
        sort(bucketArrays[i].begin(),bucketArrays[i].end());
    }
 
    int index = 0;
    //collect value from radix arrays to data
    for(int k = 0; k < bucketCounts; k++)
    {
        for(int s = 0; s < bucketArrays[k].size(); s++)
        {
            data[index++] = bucketArrays[k][s];
        }
    }
}