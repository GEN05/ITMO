package md2html;

import java.util.Arrays;

class myStack {

    private int size = 0;
    private int[] arr = new int[3];

    void add(int value) {
        if (size == arr.length) {
            arr = Arrays.copyOf(arr, arr.length * 2);
        }
        arr[size++] = value;
    }

    void pop() {
        size--;
    }

    int getSize() {
        return size;
    }
}