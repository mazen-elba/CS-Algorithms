def hasSingleCycle(array):
    elementsVisited = 0
    startingIdx = 0
    while elementsVisited < len(array):
        if (elementsVisited > 0) and (startingIdx == 0):
            return False
        elementsVisited += 1
        startingIdx = nextIdx(startingIdx, array)
    return startingIdx == 0


def nextIdx(startingIdx, array):
    jump = array[startingIdx]  # home indices to jump back(-) or forward (+)
    nextIdx = (startingIdx + jump) % len(array)
    return nextIdx if nextIdx >= 0 else nextIdx + len(array)
