/* À≥–Ú≤È’“ Sequence Search
 * 
 *
 */

#include<vector>
using namespace std;

int sequenceSearch(vector<int> arr, int value)
{
	int n = arr.size();
	for (int i = 0; i < n; ++i)
		if (arr[i] == value)
			return i;
	return -1;
}