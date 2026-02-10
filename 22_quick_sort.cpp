/*
Idea of Quick Sort (Divide & Conquer)

Choose a pivot element

Place pivot at its correct position

Elements smaller than pivot → left

Elements greater than pivot → right

Recursively sort left and right parts
*/
int partition(int arr[], int low, int high){
    int pivot = arr[high];   // choose last element as pivot
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;   // pivot index
}

// QuickSort function
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
