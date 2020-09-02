function mergeSort(array) {
  if (array.length <= 1) {
    return array;
  }

  const middleIdx = Math.floor(array.length / 2);
  const leftHalf = array.slice(0, middleIdx);
  const rightHalf = array.slice(middleIdx);

  return helperFx(mergeSort(leftHalf), mergeSort(rightHalf));
}

function helperFx(leftHalf, rightHalf) {
  const sortedArray = new Array(leftHalf.length + rightHalf.length);
  let i = 0;
  let j = 0;
  let k = 0;
  while (i < leftHalf.length && j < rightHalf.length) {
    if (leftHalf[i] <= rightHalf[j]) {
      sortedArray[k] = leftHalf[i];
      i++;
    } else {
      sortedArray[k] = rightHalf[j];
      j++;
    }
    k++;
  }

  while (i < leftHalf.length) {
    sortedArray[k] = leftHalf[i];
    i++;
    k++;
  }

  while (j < rightHalf.length) {
    sortedArray[k] = rightHalf[j];
    j++;
    k++;
  }

  return sortedArray;
}

exports.mergeSort = mergeSort;
