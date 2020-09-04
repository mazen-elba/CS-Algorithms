Product Sum

Write a function that takes in a "special" array and returns its product sum.

A "special" array is a non-empty array that contains either integers or other "special" arrays. The product sum of a "special" array is the sum of its elements, where "special" arrays inside it are summer themselves and then multiplied by their level of depth.

The depth of a "special" array is how far nested it is(eg, depth of [] is 1; depth of the inner array in [[]] is 2; depth of the innermost array in [[[]]] is 3).

The product sum of [x, y] is x + y; product sum of [x, [y, z]] is x + 2(y + z); product sum of [x, [y, [z]]] is x = 2(y + 3(z)).

INPUT
array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]]

OUTPUT
12 // 5 + 2 + 2(7 - 1) + 3 + 2(6 + 3(-13 + 8) + 4)
