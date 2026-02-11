bool isSorted(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1]) {
            return false;   // not sorted
        }
    }
    return true; // sorted
}

// logic - piche waale se aage waala bda hona chayiye 
