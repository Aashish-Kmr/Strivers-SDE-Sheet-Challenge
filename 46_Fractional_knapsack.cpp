#include <bits/stdc++.h> 
bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
    double ratioA = static_cast<double>(a.second) / a.first;
    double ratioB = static_cast<double>(b.second) / b.first;
    return ratioA > ratioB;
}

double maximumValue(vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), compare);

    double currentWeight = 0.0;
    double maximumValue = 0.0;

    for (int i = 0; i < n; ++i)
    {
        if (currentWeight + items[i].first <= w)
        {
            maximumValue += items[i].second;
            currentWeight += items[i].first;
        }
        else
        {
            double remainingWeight = w - currentWeight;
            maximumValue += (static_cast<double>(items[i].second) / items[i].first) * remainingWeight;
            break;
        }
    }

    return maximumValue;
}