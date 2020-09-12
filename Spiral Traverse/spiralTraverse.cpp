#include <vector>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array)
{
    if (array.size() == 0)
    {
        return {};
    }

    vector<int> result = {};
    int startRow = 0;
    int endRow = array.size() - 1;
    int startCol = 0;
    int endCol = array[0].size() - 1;

    while (startRow <= endRow && startCol <= endCol)
    {
        for (int col = startCol; col <= endCol; col++)
        {
            result.push_back(array[startRow][col]);
        }

        for (int row = startRow + 1; row <= endRow; row++)
        {
            result.push_back(array[row][endCol]);
        }

        for (int col = endCol - 1; col >= startCol; col--)
        {
            if (startRow == endRow)
            {
                break;
            }
            result.push_back(array[endRow][col]);
        }

        for (int row = endRow - 1; row > startRow; row--)
        {
            c if (startCol == endCol)
            {
                break;
            }
            result.push_back(array[row][startCol]);
        }

        startRow++;
        endRow--;
        startCol++;
        endCol--;
    }
    return result;
}
