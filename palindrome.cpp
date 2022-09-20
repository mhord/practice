#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void findPalindromes(string & str)
{
  int total = 0;
  for (int i = 0; i < str.size()-1; i++)
  {
    for (int k = 2; k <= str.size() - i; k++)
    {
      string sub = str.substr(i,k);
      reverse(sub.begin(), sub.end());
      if (sub == str.substr(i,k))
      {
        if (sub.size() > 1)
        {
          cout<<"Found "<<sub<<endl;
          total++;
        }
      }
    }
  }
  cout<<"Found "<<total<<" palindromes."<<endl;
}

int main()
{
  string str0 = "aabbbaa";
  findPalindromes(str0);
}
