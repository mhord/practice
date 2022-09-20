#include <iostream>
#include <vector>

using namespace std;

class Pair
{
  public:
    Pair(int x, int y);
    int first();
    int second();
    void setSecond(int x);
  private:
    int _first;
    int _second;
};

Pair::Pair(int x, int y)
{
  _first = x;
  _second = y;
}

int Pair::first()
{
  return _first;
}

int Pair::second()
{
  return _second;
}

void Pair::setSecond(int x)
{
  _second = x;
}

vector<Pair> mergeIntervals(vector<Pair>& v)
{
  vector<Pair> result;
  result.push_back(v[0]);
  for (int  i = 1; i < v.size(); i++)
  {
    if (result.back().second() >= v[i].first())
    {
      result.back().setSecond(v[i].second());
    }
    else
    {
      result.push_back(v[i]);
    }
  }
  return result;
}

int main() {
  vector<Pair> v {
                  Pair(1, 5),
                  Pair(3, 7),
                  Pair(4, 6),
                  Pair(6, 8),
                  Pair(10, 12),
                  Pair(11, 15)
                  };

  vector<Pair> result = mergeIntervals(v);
  
  for(int i = 0; i < result.size(); i++){
    cout << "[" << result[i].first() << ", " << result[i].second() << "] ";
  }
}
