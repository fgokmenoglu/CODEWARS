/*
 * You are going to be given an array of integers. 
 * Your job is to take that array and find an index N where the sum of the integers to the left of N is equal to the sum of the integers to the right of N. 
 * If there is no index that would make this happen, return -1.
 *
 * For example:
 *
 * Let's say you are given the array {1,2,3,4,3,2,1}:
 * Your function will return the index 3, because at the 3rd position of the array, the sum of left side of the index ({1,2,3}) and the sum of the right side of the index ({3,2,1}) both equal 6.
 *
 * Let's look at another one.
 * You are given the array {20,10,-80,10,10,15,35}
 * At index 0 the left side is {}
 * The right side is {10,-80,10,10,15,35}
 * They both are equal to 0 when added. (Empty arrays are equal to 0 in this problem)
 * Index 0 is the place where the left side and right side are equal.
 * 
 * Input:
 * An integer array of length 0 < arr < 1000. The numbers in the array can be any integer positive or negative.
 * 
 * Output:
 * The lowest index N where the side to the left of N is equal to the side to the right of N. If you do not find an index that fits these rules, then you will return -1.
 * 
 * Note:
 * If you are given an array with multiple answers, return the lowest correct index.
 */
#include <vector>

using namespace std;

int find_even_index(const vector <int> numbers) {
  int leftSum = 0, rightSum = 0;
  
  for (size_t i = 0; i < numbers.size(); i++) {
    for (size_t j = 0; j < i; j++)
      leftSum += numbers[j];
    
    for (size_t k = i + 1; k < numbers.size(); k++)
      rightSum += numbers[k];
    
    if (leftSum == rightSum)
      return i;
    
    leftSum = rightSum = 0;
  }
  
  return -1;
}

// ALTERNATIVE
#include <vector>
#include <numeric> // accumulate

using namespace std;

int find_even_index(const vector<int>& numbers) {
    int totalSum = accumulate(numbers.begin(), numbers.end(), 0);
    int leftSum = 0;
    for (size_t i = 0; i < numbers.size(); i++) {
        if (leftSum == totalSum - leftSum - numbers[i]) {
            return i;
        }
        leftSum += numbers[i];
    }
    return -1;
}
