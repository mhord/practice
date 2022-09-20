#include <iostream>
#include <vector>

using namespace std;

bool findSumOfThree(vector<int> v, int target)
{
  for (int i = 0; i < v.size(); i++)
  {
    for (int j = i+1; j < v.size(); j++)
    {
      for (int k = j+1; k < v.size(); k++)
      {
        if (v[i] + v[j] + v[k] == target)
        {
          cout<<"Found a match! "<<v[i]<<" + "<<v[j]<<" + "<<v[k]<<endl;
          return true;
        }
      }
    } 
  }
  return false;
}

int main(){
    vector<int> arr = {-25, -10, -7, -3, 2, 4, 8, 10};
  
    cout<<boolalpha;
    cout<<"-8: " <<findSumOfThree(arr, -8)<<endl; 
    cout<<"-25: "<<findSumOfThree(arr, -25)<<endl;
    cout<<"0: " <<findSumOfThree(arr, 0)<<endl;
    cout<<"-42: " <<findSumOfThree(arr, -42)<<endl; 
    cout<<"22: " <<findSumOfThree(arr, 22)<<endl; 
    cout<<"-7: " <<findSumOfThree(arr, -7)<<endl;
    cout<<"-3: " <<findSumOfThree(arr, -3)<<endl; 
    cout<<"2: " <<findSumOfThree(arr, 2)<<endl; 
    cout<<"4: " <<findSumOfThree(arr, 4)<<endl; 
    cout<<"8: " <<findSumOfThree(arr, 8)<<endl; 
    cout<<"7: " <<findSumOfThree(arr, 7)<<endl; 
    cout<<"1: " <<findSumOfThree(arr, 1)<<endl;
  
    return 0;
}
