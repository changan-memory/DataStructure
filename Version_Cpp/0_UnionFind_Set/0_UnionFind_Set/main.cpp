#include "UnionFindSet.h"

//// 建立了 任意类型和下标索引  的并查集
//void testBuildIndex()
//{
//	string arr[] = { "张三", "李四", "王五", "赵六" };
//	UnionFindSet<string> ufs(arr, 4);
//}

void TestUnionSet()
{
	UnionFindSet ufs(10);
	ufs.Union(8, 9);
	ufs.Union(7, 8);
	ufs.Union(6, 7);
	ufs.Union(5, 6);
	ufs.Union(4, 5);

	ufs.FindRoot(9);
}

int main()
{
	TestUnionSet();
	return 0;
}