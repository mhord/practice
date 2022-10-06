#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
  vector<int> v = {-4,2,-5,1,2,3,6,-5,1};

  int localMax = 0;
  int globalMax = 0;
  int startIndex = 0;
  int endIndex = 0;

  vector<int>::iterator i;
  vector<int>::iterator j;
  for (i = v.begin(); i < v.end(); i++)
  {
    for (j = i; j < v.end(); j++)
    {
      int subsum = accumulate(i, j, 0);
      if (subsum > globalMax)
      {
        globalMax = subsum;
        startIndex = distance(v.begin(), i);
        endIndex = distance(v.begin(), j) - 1;
      }
    }
  }
  cout<<"Max: "<<globalMax<<" Starts at "<<startIndex<<", ends at "<<endIndex<<endl;
  return 0;
}

