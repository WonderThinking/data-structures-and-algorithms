/* Huffman树、编码、解码 */

#include<iostream>
#include<string>
#include<vector>
#include"Huffman.h"
using namespace std;

int main()
{
	/* test1 普通ASCII码范围内的字符，字符种类大于1 */
	string file = "This is the Huffman test file.Author:Wang Xinqi";
	Huffman hfTree;
	hfTree.HuffmanTree(file);
	hfTree.HuffmanCode();
	string code = hfTree.HuffmanCompress(file);
	string decode = hfTree.HuffmanDecode(code);
	cout << "原始文件：\n" << file << endl;
	cout << "Huffman编码压缩后的文件:\n" << code << endl;
	cout << "Huffman解码后的文件:\n" << decode << '\n' << endl;

	/* 只有一种字符的情况 */
	file = "TTTT";
	hfTree.HuffmanTree(file);
	hfTree.HuffmanCode();
	code = hfTree.HuffmanCompress(file);
	decode = hfTree.HuffmanDecode(code);
	cout << "原始文件：" << file << endl;
	cout << "Huffman编码压缩后的文件:" << code << endl;
	cout << "Huffman解码后的文件:" << decode << '\n' << endl;

	/* 空文件 */
	file = "";
	hfTree.HuffmanTree(file);
	hfTree.HuffmanCode();
	code = hfTree.HuffmanCompress(file);
	decode = hfTree.HuffmanDecode(code);
	cout << "原始文件：" << file << endl;
	cout << "Huffman编码压缩后的文件:" << code << endl;
	cout << "Huffman解码后的文件:" << decode << '\n' << endl;

	system("pause");
	return 0;
}
