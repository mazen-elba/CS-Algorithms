function searchForRange(array, target){
    const finalRange = [-1, -1];
    helperFx(array, target, 0, array.length - 1, finalRange, true);
    helperFx(array, target, 0, array.length - 1, finalRange, false);
    return finalRange;
}

// Variation of Binary Search Algorithm
function helperFx(array, target, leftIdx, rightIdx, finalRange, goLeft){
    while (leftIdx <= rightIdx){
        const midIdx = Math.floor((leftIdx + rightIdx) / 2);
        if (array[midIdx] < target){
            leftIdx = midIdx + 1;
        } else if (array[midIdx] > target){
            rightIdx = midIdx - 1;
        } else {
            if (goLeft){
                if (midIdx === 0 || array[midIdx - 1] !== target){
                    finalRange[0] = midIdx;
                    return;
                } else {
                    rightIdx = midIdx - 1;
                }
            } else {
                if (midIdx === array.length - 1 || array[midIdx + 1] !== target){
                    finalRange[1] = midIdx;
                    return;
                } else {
                    leftIdx = midIdx + 1;
                }
            }
        }
    }
}