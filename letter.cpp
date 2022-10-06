#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
  string str = "the quick red fox jumps over the lazy brown dog";

  unordered_set<char> dict;
  locale loc;

  for (string::iterator i = str.begin(); i != str.end(); i++)
  {
    if (isalpha(*i, loc))
    {
      dict.insert(tolower(*i));
    }
  }

  if (dict.size() == 26)
  {
    cout<<"True"<<endl;
  }
  else
  {
    cout<<"False"<<endl;
  }
  return 0;
}
