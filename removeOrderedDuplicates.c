//2 vector approach, i to read and j to write

int removeDuplicates(int* nums, int numsSize) {
    int j = 1;
    //for each element in the array
    for(int i = 1; i < numsSize; i++) {
        //if the current element is NOT equal to the previous element
         if (nums[i] != nums[i - 1]) {
            //make the write index the current element, then increment the write index
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}
