#include<bits/stdc++.h>
using namespace std;

void incrementVector(vector<int> &a)
{
  int n = a.size();
  a[n-1]+=1;
  int carry = a[n-1]/10;
  a[n-1] = a[n-1]%10;
  for(int i=n-2;i>=0;i--)
  {
    if(carry==1)
    {
      a[i]+=1;
      carry = a[i]/10;
      a[i] = a[i]%10;

    }
  }
  if(carry == 1)
  a.insert(a.begin(),1);
}
int main() {
  vector<int> vect{1,7,8,9};
  incrementVector(vect);
  for(int i=0;i<vect.size;i++)
  cout<<vect[i]<<" ";
  return 0;
}
