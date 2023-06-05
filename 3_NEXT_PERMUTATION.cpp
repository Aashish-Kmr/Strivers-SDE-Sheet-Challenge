#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
vector<int> nextPermutation(vector<int> &arr, int n)
{
    int infpt= -1;
    for(int i=n-1; i>0; i--){
      if (arr[i - 1] < arr[i]) {
        infpt = i;
        break;
      }
    }
    if(infpt==-1){
        sort(arr.begin(),arr.end());
        return arr;
    }
    int min=INT_MAX;
    int toswap=infpt-1;
    int minind=-1;
    for(int i = infpt; i < n ; i++){
        if(arr[i]>arr[toswap]){
            int en=arr[i]-arr[toswap];
            if (en < min) {
                minind=i;
              min = en;
            }
        }
    }
    int temp =arr[toswap];
    arr[toswap] = arr[minind];
    arr[minind]=temp;

    sort(arr.begin()+infpt , arr.end());
    return arr;
}