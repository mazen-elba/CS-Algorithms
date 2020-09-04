function hasSingleCycle(array) {
  let elementsVisited = 0;
  let startingIdx = 0;
  while (elementsVisited < array.length) {
    if (elementsVisited > 0 && startingIdx === 0) {
      return false;
    }

    elementsVisited++;
    startingIdx = nextIdx(startingIdx, array);
  }

  return startingIdx === 0;
}

function nextIdx(startingIdx, array) {
  const jump = array[startingIdx];
  const nextIdx = (startingIdx + jump) % array.length;
  return nextIdx >= 0 ? nextIdx : nextIdx + array.length;
}

exports.hasSingleCycle = hasSingleCycle;
