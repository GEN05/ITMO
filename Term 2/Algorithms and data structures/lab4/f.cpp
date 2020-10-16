#include <iostream>
#include <vector>
#include <algorithm>

typedef long long int ll;

bool compartorF(std::pair<ll, ll> &a, std::pair<ll, ll> &b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

ll mergeSort(ll *arr, ll *temp, ll left, ll right);

ll merge(ll *arr, ll temp[], ll left, ll mid, ll right);

ll mergeSort(ll *arr, ll array_size) {
    ll temp[array_size];
    return mergeSort(arr, temp, 0, array_size - 1);
}

ll mergeSort(ll *arr, ll *temp, ll left, ll right) {
    ll mid, counter = 0;
    if (right <= left)
        return counter;
    mid = (right + left) / 2;
    counter += mergeSort(arr, temp, left, mid);
    counter += mergeSort(arr, temp, mid + 1, right);
    counter += merge(arr, temp, left, mid + 1, right);
    return counter;
}

ll merge(ll *arr, ll *temp, ll left, ll mid, ll right) {
    ll i = left, j = mid, k = left, counter = 0;
    while (right >= j && mid - 1 >= i) {
        if (arr[i] > arr[j]) {
            temp[k++] = arr[j++];
            counter = counter + (mid - i);
        } else
            temp[k++] = arr[i++];
    }
    while (mid - 1 >= i)
        temp[k++] = arr[i++];
    while (right >= j)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return counter;
}


int main() {
    freopen("john.in", "r", stdin);
    freopen("john.out", "w", stdout);
    ll n, ans;
    std::cin >> n;
    std::vector<std::pair<ll, ll>> a(n);
    for (auto &i : a)
        std::cin >> i.first >> i.second;

    std::sort(a.begin(), a.end(), compartorF);
//    for (auto &i : a)
//        std::cout << i.first << " " << i.second << '\n';
    ll b[n];
    for (ll i = 0; i < n; i++)
        b[i] = a[i].second;
    ans = mergeSort(b, n);
    std::cout << ans;
    return 0;
}