#include <stdio.h>
#include "LoopIndexer.hpp"


int main()
{

	LoopIndex<3> indexer = 0;

	for ( int i = 0; i < 30; i++ )
	{
		size_t idx = (size_t)( --indexer );
		printf("%d\n", idx);
	}



	return 0;
}