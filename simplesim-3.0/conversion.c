#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int getIndex(unsigned addr);
void decTobinary (unsigned addr, int addr_binary[]); 
int binary32To12(int addr_binary[]); 

int getIndex (unsigned addr)
{
int addr_binary[32];
int bypassbuff_index;

decTobinary(addr, addr_binary);
bypassbuff_index = binary32To12(addr_binary);
}

void decTobinary (unsigned addr, int addr_binary[]) 
{
const int SHIFT = 8 * sizeof( unsigned) - 1;
const unsigned MASK = 1<<SHIFT;
int i;
unsigned c;

for (c = 1; c <= SHIFT + 1; c = c+1) 
{
i = c - 1;
addr_binary[i] = addr & MASK ? 1 : 0;
addr = addr << 1;
}
}

int binary32To12(int addr_binary[]) 
{
int i;
int new_bit;
int index = 0;
int bit[36];
char *str2;

for (i = 0; i < 36; i = i + 1)
{
if (i < 4)
bit[i] = 0;
else
bit[i] = addr_binary[i-4];
}

str2 = (char *) malloc (13 *sizeof(char));
assert (str2 != NULL);
for (i = 0; i < 12; i = i + 1) 
{
new_bit = bit[0+i] ^ bit[12+i] ^ bit[24+i];
index = index + new_bit * pow((double)2, (double)(11-i));

if (new_bit == 0)
str2[i] = '0';
else
str2[i] = '1';
}
str2[i] = '/0';

return index;
}
