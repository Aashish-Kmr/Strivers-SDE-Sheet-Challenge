#include <vector>

std::vector<std::vector<long long int>> printPascal(int n)
{
  if (n <= 0) {
    // Invalid input, return an empty vector
    return std::vector<std::vector<long long int>>();
  }

  std::vector<std::vector<long long int>> v;
  
  for (int i = 0; i < n; i++) {
    std::vector<long long int> v1(i + 1, 1); // Initialize with 1s
    for (int j = 1; j < i; j++) {
      v1[j] = v[i - 1][j - 1] + v[i - 1][j];
    }
    v.push_back(v1);
  }
  
  return v;
}
