#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

unsigned long int primeFind(vector<char> v, 
                            unsigned long int n);

int main(int argc, char* argv[])
{
  unsigned long int n = 0;
  if (argc > 1)
  {
    string in = argv[1]; 
    try
    {
      size_t len;
      n = stoi(in, &len);
      if (len > in.size())
      {
        cout<<"Trailing characters after number."<<endl;
      }
    } catch (invalid_argument const &ex)
    {
      cout<<"Invalid argument!"<<endl;
      return -1;
    }
  }
  else
  {
    n = 5;
  }
  cout<<"Looking for prime index "<<n<<endl;

  char s = 5;
  unsigned long int prime = 0;
  vector<char> v(s*n, 1);
  unsigned long int offset = 2;
  int limit = 0;
  do
  {
    prime = primeFind(v, n);
    if (prime == 0)
    {
      cout<<"Prime not found for numbers less than "<<v.size()<<endl;
      v.resize(++s*n + v.size(), 1);
    } 
    if (++limit > 20) break;
  } while (prime == 0);
  cout<<prime<<endl;
  return 0;
}

unsigned long int primeFind(vector<char> v, 
                            unsigned long int n)
 
{
  unsigned long primeCnt = 0;
  for (unsigned long int i = 2; i<v.size(); i++)
  {
    if (v.at(i) == 1)
    {
      for (unsigned long int j = 2; j*i<v.size(); j++)
      {
        v.at(i*j) = 0;
      }
      primeCnt++;
    }
    if (primeCnt == n)
    {
      return i;
    }
  }
  return 0;
}

