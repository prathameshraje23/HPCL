// CPP Program to find the minimum scalar product of two vectors (dot product)
#include<iostream>
#include<algorithm>
#include<vector>
#include<omp.h>
using namespace std;

int main()
{
  int n=1000;
  int sum=0;
  vector<int> arr1(n);
  vector<int> arr2(n);
  int i;
  //filling the vectors
  for(i = 0; i < n ; i++)
  {
    arr1[i]=(i+1)%2;
    arr2[i]=(i+1)%2;
  }
  sort(arr1.begin(),arr1.end());
  sort(arr2.begin(),arr2.end(), greater<int>());

  double itime, ftime, exec_time;
  itime = omp_get_wtime();

  for(i = 0; i < n ; i++)
  {
    sum = sum + (arr1[i] * arr2[i]);
  }

  ftime = omp_get_wtime();
  exec_time = ftime - itime;
  cout<<"Sum= "<<sum<<endl;
  printf("Time taken = %f\n",exec_time);
  return 0;

}
