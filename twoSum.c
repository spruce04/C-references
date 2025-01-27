/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = malloc(2 * sizeof(int));

    //iterate through the array of ints
    for(int i = 0; i < numsSize; i++) {
        //test each number with all other numbers
        for(int j = 0; j < numsSize; j++) {
            if(j == i) {//cant have the same index twice
                continue;
            }

            //if the two numbers sum to the target add them to the result array
            else if(nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    return result;

}
