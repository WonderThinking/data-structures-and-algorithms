/* �ֵ�����ǰ׺������C++ʵ��  Trie
 * ����ֻ���Сд��ĸ ,������ִ�Сд������չ
 */

#include<iostream>
#include<vector>
#include"Trie.h"
using namespace std;

void main()
{
	vector<string> arr = { "abc","abcd","abd","b","bcd","efg","hik" };
	Trie t;
	for (int i = 0; i < arr.size(); ++i)
		t.insert(arr[i]);
	t.prePrint();
	system("pause");
	return;
}
