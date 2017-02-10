#include <iostream>
#include "UnionFind1.h"
#include "UnionFind2.h"
#include "UnionFind3.h"
#include "UnionFind4.h"
#include "UnionFindTestHelper.h"

#define N 500000

using namespace std;



int main(){

	//UnionFindTestHelper::testUF1(N);
	//UnionFindTestHelper::testUF2(N);
	UnionFindTestHelper::testUF3(N);
	UnionFindTestHelper::testUF4(N);

	return 0;
}