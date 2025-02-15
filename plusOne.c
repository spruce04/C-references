/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    //set up the array that we will eventually return
    int* returnArray = malloc((digitsSize + 1) * sizeof(int));
    for(int i = 0; i < digitsSize; i++) {
        returnArray[i] = digits[i]; 
    }
    //if it is simple (no numbers to be carride)
    if(returnArray[digitsSize-1] != 9) {
        returnArray[digitsSize-1]++;
        *returnSize = digitsSize;
        return returnArray;
    }
    //carry for as many 9's as there are
    else {
        //as long as we have 9's make them 0's. then if we get to a non-9 digit, increment it and break the loop
        for(int i = digitsSize-1; i >= 0; i--) {
            if(returnArray[i] == 9) {
                returnArray[i] = 0;
            }
            else {
                returnArray[i]++;
                break;
            }
        }
        //if all digits were 9, we need to add a 1 at the front
        if(returnArray[0] == 0) {
            returnArray[0] = 1;
            returnArray[digitsSize] = 0;//the previously undefined extra value must be used (at the arrays end)
            *returnSize = digitsSize + 1; 
        }
        else {
            *returnSize = digitsSize;
        }
        return returnArray;
    }
}
