#include <iostream>
#include <vector>
#include <array>
#include <cstddef> 

using namespace std;

static constexpr int NUM_BUCKETS = 7;

int buckets[100] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6
};

static size_t mapToBucket(size_t v) {
    if (v < (sizeof(buckets) / sizeof(int)))
        return buckets[v];
    return -1; // let it crash
}

array<size_t, NUM_BUCKETS> histogram(const vector<int>& values) {
    array<size_t, NUM_BUCKETS> retBuckets{0};
    for (auto v : values) {
        retBuckets[mapToBucket(v)]++;
    }
    return retBuckets;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    auto hist = histogram(values);

    cout << "Histogram:\n";
    for (size_t i = 0; i < hist.size(); ++i) {
        cout << "Bucket " << i << ": " << hist[i] << endl;
    }

    return 0;
}
