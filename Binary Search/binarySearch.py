def binarySearch(array, target):
    leftIdx = 0
    rightIdx = len(array) - 1
    while leftIdx <= rightIdx:
        middleIdx = (leftIdx + rightIdx) // 2
        potentialMatch = array[middleIdx]
        if target == potentialMatch:
            return middleIdx
        elif target < potentialMatch:
            rightIdx = middleIdx - 1
        else:
            leftIdx = middleIdx + 1

    return -1
