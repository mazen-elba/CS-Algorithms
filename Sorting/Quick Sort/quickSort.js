function quickSort(array) {
  helperFx(array, 0, array.length - 1);
  return array;
}

function helperFx(array, startIdx, endIdx) {
  if (startIdx >= endIdx) {
    return;
  }

  const pivotIdx = startIdx;
  let leftIdx = startIdx + 1;
  let rightIdx = endIdx;
  while (rightIdx >= leftIdx) {
    if (array[leftIdx] > array[pivotIdx] && array[rightIdx] < array[pivotIdx]) {
      swap(leftIdx, rightIdx, array);
    }
    if (array[leftIdx] <= array[pivotIdx]) {
      leftIdx++;
    }
    if (array[rightIdx] >= array[pivotIdx]) {
      rightIdx--;
    }
  }

  swap(pivotIdx, rightIdx, array);
  let leftSubarrayIsSmaller = leftIdx - 1 - startIdx < endIdx - rightIdx + 1;
  if (leftSubarrayIsSmaller) {
    helperFx(array, startIdx, rightIdx - 1);
    helperFx(array, rightIdx + 1, endIdx);
  } else {
    helperFx(array, rightIdx + 1, endIdx);
    helperFx(array, startIdx, rightIdx - 1);
  }
}

function swap(i, j, array) {
  let temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}
