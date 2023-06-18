// not optimal solution :( 
    std::string s1;
    std::vector<int> arr;
    for (int i = 1; i <= n; i++) {
        arr.push_back(i);
    }
    if (k == 1) {
        for (int i = 0; i < n; i++) {
            s1 += std::to_string(arr[i]);
        }
        return s1;
    }
    k--;
    int inf, toswap;
    while (k--) {
        for (int i = n - 1; i > 0; i--) {
            if (arr[i] > arr[i - 1]) {
                inf = i;
                toswap = i - 1;
                break;
            }
        }
        int min = inf;
        for (int i = inf; i < n; i++) {
            if (arr[i] < arr[inf] && arr[i] > arr[toswap]) {
                min = i;
            }
        }
        int temp = arr[min];
        arr[min] = arr[toswap];
        arr[toswap] = temp;

        std::sort(arr.begin() + inf, arr.end());
    }
    for (int i = 0; i < n; i++) {
        s1 += std::to_string(arr[i]);
    }
    return s1;  