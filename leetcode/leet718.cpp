#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

class Solution
{
  public:
  int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
  {
    int index_left = 0, index_right, length = nums1.size();

    while(length > 0)
    {
      index_right = index_left + length;
      std::vector<int> sub1(nums1.begin()+index_left, nums1.begin()+index_right);

      for(int i = 0, j = length; j <= nums1.size(); i++, j++)
      {
        std::vector<int> sub2(nums2.begin()+i, nums2.begin()+j);
        if(sub1 == sub2)
          return length;
      }

      index_left++;
      if(index_left + length > nums1.size())
      {
        index_left = 0;
        length--;
      }
    }
    return 0;
  }
};

int main()
{
  int n;
  Solution sol;
  std::stringstream ss;
  std::string inputNum;
  std::vector<int> nums1, nums2;

  while(1)
  {
    std::getline(std::cin, inputNum);

    if(inputNum == "")
     break;
    ss << inputNum;

    while(ss >> n)
      nums1.push_back(n); 
    ss.clear();

    std::getline(std::cin, inputNum);
    
    if(inputNum == "")
     break;
    ss << inputNum;

    while(ss >> n)
      nums2.push_back(n); 
    ss.clear();

    std::cout << sol.findLength(nums1, nums2) << std::endl;

    nums1.clear();
    nums2.clear();
  }
  return 0;
}
