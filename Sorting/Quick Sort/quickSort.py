def quickSort(array):
    helperFx(array, 0, len(array) - 1)
    return array


def helperFx(array, startIdx, endIdx):
    if startIdx >= endIdx:
        return

    pivotIdx = startIdx
    leftIdx = startIdx + 1
    rightIdx = endIdx
    while rightIdx >= leftIdx:
        if (array[leftIdx] > array[pivotIdx]) and (array[rightIdx] < array[pivotIdx]):
            swap(leftIdx, rightIdx, array)
        if (array[leftIdx] <= array[pivotIdx]):
            leftIdx += 1
        if (array[rightIdx] >= array[pivotIdx]):
            rightIdx -= 1

    swap(pivotIdx, rightIdx, array)

    leftSubarrayIsSmaller = (rightIdx - 1 - startIdx) < (endIdx - rightIdx + 1)
    if leftSubarrayIsSmaller:
        helperFx(array, startIdx, rightIdx - 1)
        helperFx(array, rightIdx + 1, endIdx)
    else:
        helperFx(array, rightIdx + 1, endIdx)
        helperFx(array, startIdx, rightIdx - 1)


def swap(i, j, array):
    array[i], array[j] = array[j], array[i]
