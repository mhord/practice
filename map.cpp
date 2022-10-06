#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
  map<int, vector<string>> roster;
  int grade = 2;
  const string name = "Aimee";
  roster.insert({grade, {name}});
  cout<<roster.size()<<endl;
  cout<<roster[2][0];

}

