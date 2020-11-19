#include <stdio.h>
//cont does not relate to the data but what it points to so i can change the data i just cannot change its reference????

int max(int n, int* pData)
//take in integer n and integer pointer pData
{
    int* endOfData = &pData[n];
// endofdata points to the address at the end of pdata
    int big = *pData++;
//initialising the largest number to maximum
    for(; pData < endOfData; pData++) {
        //count from pdata to the address at the end of pdata
        //we are comparing 2 pointers so while address at pdata is less than address of endofdata, run code and increment pdata address by 1 each time
        if(*pData > big) {

            big = *pData;
        }
    }
    return big;
}

int main(void)
{
    int nums[] = {10, 20, 30};
    int* p = NULL;

    p = &nums[0];
    printf("%p %p\n", p, nums);
    printf("Biggest = %d\n", max(3, nums));
}
