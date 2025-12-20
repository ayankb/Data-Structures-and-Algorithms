def binary_search(arr, key):
    low = 0
    high = len(arr)-1
    while low <= high:
        mid = (low+high) // 2
        if(arr[mid] == key):
            return mid
        elif (arr[mid] < key):
            low = mid + 1
        else:
            high = mid - 1
    return -1

arr = list(map(int, input().split()))
if(sorted(arr) != arr):
    print("Array is not soreted. Please enter a sorted array.")
else:
    key = int(input("Enter the element to be secarch: "))
    result = binary_search(arr, key)

    if result == -1:
        print("Element not found.")
    else:
        print("Element found at index:", result)    