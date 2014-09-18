#include <stdio.h>
#include "def.h"
ull factor[2] = {1007, 103};
ull hashval(char* ch, int v){
	ull f = factor[v], res = 0;
	for(; *ch != '\0'; ch++){
		res = res * f + (ull)(*ch);
	}
	return res;
}
