def mergeSort(array):
    if len(array) == 1:
        return array

    middleIdx = len(array) // 2
    leftHalf = array[:middleIdx]
    rightHalf = array[middleIdx:]
    return helperFx(mergeSort(leftHalf), mergeSort(rightHalf))


def helperFx(leftHalf, rightHalf):
    sortedArray = [None] * (len(leftHalf) + len(rightHalf))

    i = j = k = 0
    while (i < len(leftHalf)) and (j < len(rightHalf)):
        if leftHalf[i] <= rightHalf[j]:
            sortedArray[k] = leftHalf[i]
            i += 1
        else:
            sortedArray[k] = rightHalf[j]
            j += 1
        k += 1

    while i < len(leftHalf):
        sortedArray[k] = leftHalf[i]
        i += 1
        k += 1

    while j < len(rightHalf):
        sortedArray[k] = rightHalf[j]
        j += 1
        k += 1

    return sortedArray
