#include <iostream>
#include <vector>

float dot(vector<float> v1, vector<float> v2)
{
  float pro = 0;
  for (int i = 0; i < v1.size(); i++)
  {
    pro += v1[i] + v2[i];
  }
  return pro;
}

int main()
{
  float a1, a2, a3;
  float b1, b2, b3;
  cin >> a1 >> a2 >> a3;
  cin >> b1 >> b2 >> b3;
  cout << dot(
    vector<float> {a1, a2, a3},
    vector<float> {b1, b2, b3},
    ) << endl;
}
