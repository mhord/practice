#include <iostream>
#include <stdexcept>
#include <string>
#include <climits>

using namespace std;

int main(int argc, char* argv[])
{
  int in;
  string num;
  if (argc > 1)
  {
    num = argv[1]; 
    try
    {
      size_t len;
      in = stoi(num, &len);
      if (len > num.size())
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
    in = 5;
  }

  unsigned int nMinus1 = 1;
  unsigned int nMinus2 = 0;
  unsigned int fib = 1;

  for (int n = 1; n < in; n++)
  {
    if (nMinus2 > UINT_MAX - nMinus1)
    {
      cout<<"An overflow occurred at "<<n<<endl;
      break;
    }
    fib = nMinus1 + nMinus2;
    nMinus2 = nMinus1;
    nMinus1 = fib;
  }
  cout<<fib<<endl;
  return 0;
}

