def linear_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1

arr = list(map(int, input().split()))
key = int(input("Enter the element to be secarch: "))
result = linear_search(arr, key)
if result == -1:
    print("Element not found.")
else:
    print("Element found at index: ", result)

