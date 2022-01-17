#include <iostream>
#include <vector>

class Solution {
  public:
  int maxDistToClosest(std::vector<int>& seats)
  {
    int hasperson_index_left = 0, hasperson_index_right = 0, maxLength = 0, length;
    for(int i = 0; i < seats.size(); i++)
    {
      if(seats[i] == 1)
      {
        hasperson_index_left = hasperson_index_right;
        hasperson_index_right = i;
      }
      else if(i == seats.size()-1)
      {
        hasperson_index_left = hasperson_index_right;
        hasperson_index_right = i;
      }

      length = hasperson_index_right - hasperson_index_left;

      if(seats[hasperson_index_left] == 1 && seats[hasperson_index_right] == 1)
        length % 2 == 0 ? length /= 2 : length = (length-1) / 2;

      if(length > maxLength)
        maxLength = length; 
    }
    return maxLength;
  }
};

int main()
{
  short n;
  std::vector<int> seats;
  
  while(std::cin >> n)
    seats.push_back(n);
  
  Solution sol;
  int maxLength = sol.maxDistToClosest(seats);

  std::cout << maxLength << std::endl;
  return 0;
}
