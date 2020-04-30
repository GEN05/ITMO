#include <iostream>
#include <vector>

std::vector<int> heap;

void siftUp(int i) {
    while (heap[i] > heap[(i - 1) / 2] && i >= 1) {
        std::swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insertA(int a) {
    heap.push_back(a);
    siftUp(heap.size() - 1);
}

void siftDown(int i) {
    while (2 * i + 1 < heap.size()) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int j = left;
        if (right < heap.size() && heap[right] > heap[left]) {
            j = right;
        }
        if (heap[i] >= heap[j]) {
            break;
        }
        std::swap(heap[i], heap[j]);
        i = j;
    }
}

int remove_max() {
    int max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    siftDown(0);
    return max;
}

int main() {
    int k;
    std::cin >> k;
    int *a = new int[2 * k];
    for (int i = 0; i < 2 * k; i += 2) {
        std::cin >> a[i];
        if (a[i] == 0) {
            std::cin >> a[i + 1];
        }
    }
    for (int i = 0; i < 2 * k; i += 2) {
        if (a[i] == 0) {
            insertA(a[i + 1]);
        }
        if (a[i] == 1) {
            std::cout << remove_max() << std::endl;
        }
    }
    return 0;
}