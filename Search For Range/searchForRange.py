def searchForRange(array, target):
    finalRange = [-1, -1]
    helperFx(array, target, 0, len(array) - 1, finalRange, True)
    helperFx(array, target, 0, len(array) - 1, finalRange, False)
    return finalRange

# Variation of Binary Search Algorithm


def helperFx(array, target, leftIdx, rightIdx, finalRange, goLeft):
    while leftIdx <= rightIdx:
        midIdx = (leftIdx + rightIdx) // 2
        if array[midIdx] < target:
            leftIdx = midIdx + 1
        elif array[midIdx] > target:
            rightIdx = midIdx - 1
        else:
            if goLeft:
                if midIdx == 0 or array[midIdx - 1] != target:
                    finalRange[0] = midIdx
                    return
                else:
                    rightIdx = midIdx - 1
            else:
                if midIdx == len(array) - 1 or array[midIdx + 1] != target:
                    finalRange[1] = midIdx
                    return
                else:
                    leftIdx = midIdx + 1
