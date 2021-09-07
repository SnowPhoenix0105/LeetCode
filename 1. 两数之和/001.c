 /**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i,j;
    int* returnArry = (int*)malloc(2*sizeof(int));
    for(i=0; i<numsSize-1; i++){
        for(j=i+1; j<numsSize; j++){
            if(nums[i]+nums[j]==target){
                returnArry[0] = i;
                returnArry[1] = j;
            }
        }
    }
    *returnSize = 2;
    return returnArry;
}