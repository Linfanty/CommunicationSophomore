int binarySearch(int arr[], int left, int right, int x)
{
    if (left <= right)
    {
        int mid = (left + right)/2;
        /// int mid = left + (right-left)/2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return binarySearch(arr, left, mid-1, x);
        else return binarySearch(arr, mid+1, right, x);
    }
    return -1;
}
