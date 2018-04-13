/* Huffman�������롢���� */

#include<iostream>
#include<string>
#include<vector>
#include"Huffman.h"
using namespace std;

int main()
{
	/* test1 ��ͨASCII�뷶Χ�ڵ��ַ����ַ��������1 */
	string file = "This is the Huffman test file.Author:Wang Xinqi";
	Huffman hfTree;
	hfTree.HuffmanTree(file);
	hfTree.HuffmanCode();
	string code = hfTree.HuffmanCompress(file);
	string decode = hfTree.HuffmanDecode(code);
	cout << "ԭʼ�ļ���\n" << file << endl;
	cout << "Huffman����ѹ������ļ�:\n" << code << endl;
	cout << "Huffman�������ļ�:\n" << decode << '\n' << endl;

	/* ֻ��һ���ַ������ */
	file = "TTTT";
	hfTree.HuffmanTree(file);
	hfTree.HuffmanCode();
	code = hfTree.HuffmanCompress(file);
	decode = hfTree.HuffmanDecode(code);
	cout << "ԭʼ�ļ���" << file << endl;
	cout << "Huffman����ѹ������ļ�:" << code << endl;
	cout << "Huffman�������ļ�:" << decode << '\n' << endl;

	/* ���ļ� */
	file = "";
	hfTree.HuffmanTree(file);
	hfTree.HuffmanCode();
	code = hfTree.HuffmanCompress(file);
	decode = hfTree.HuffmanDecode(code);
	cout << "ԭʼ�ļ���" << file << endl;
	cout << "Huffman����ѹ������ļ�:" << code << endl;
	cout << "Huffman�������ļ�:" << decode << '\n' << endl;

	system("pause");
	return 0;
}
