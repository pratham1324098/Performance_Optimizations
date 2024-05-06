#include <iostream>
#include <vector>
#include <immintrin.h> 

using namespace std;

void prefetch(const float* addr) {
    _mm_prefetch((const char*)addr, _MM_HINT_T0); 
}

int main() {
    const int size = 1000000;
    vector<float> arr(size, 0.0);

    for (int i = 0; i < size; ++i) {
        prefetch(&arr[i]);
    }

    float sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }

    cout << "Sum: " << sum << endl;

    return 0;
}
