#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void reverseSentence(string & str)
{
  vector<string> v;
  string temp;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] != ' ')
    {
      temp.append(str, i, 1);
    }
    else
    {
      v.push_back(temp);
      v.push_back(" ");
      temp.clear();
    }
  }
  v.push_back(temp);
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++)
  {
    cout<<v[i];
  }
}

int main()
{
  string str = "The quick red fox jumped over the lazy brown dog.";
  reverseSentence(str);
}
