//find the max sum of a strictly ascending subarray from an array of ints
//approach: iterate through the array and keep track of the sum of each subarray - if the sum is greater than the max sum
//we have found, make it the new max.

int maxAscendingSum(int* nums, int numsSize) {
    int max = 0;
    int current = 0;
    for(int i = 0; i < numsSize; i++) {
        if(i == numsSize-1) {//if we are at the end of the array, compare to the previous index
            current += nums[i];
            //then test if our current is greater than max
            if(current > max) {
                max = current;
            }
        }
        else if(nums[i+1] > nums[i]) {//if the next int is greater than the current int we are in an ascending subarray
            current += nums[i];
        }
        else {//if the next int is less than or equal to the current int the current subarray ends
            current += nums[i];
            if(current > max) {
                max = current;
            }
            current = 0;//reset the current variable
        }
    }   
    return max;
}
