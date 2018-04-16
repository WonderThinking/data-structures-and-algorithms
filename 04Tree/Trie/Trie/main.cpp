/* 字典树（前缀树）的C++实现  Trie
 * 这里只存的小写字母 ,如果区分大小写可以扩展
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
