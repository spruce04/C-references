int reverse(int x) {
    //approach: put the digits of x in an array of ints and then iterate backwards through that array
    int* intArr = malloc(100 * sizeof(int));
    int column = 0;

    //extract the current digit and put it in our array of ints
    while (x != 0) {
        intArr[column] = x % 10;//remainder when dividing by 10 gets the last digit
        x = x / 10;//get rid of the last digit and keep going
        column++;
    }

    int returnNum = 0;
    //now that our array is done, iterate through it again and add the numbers together
    for (int i = column - 1; i >= 0; i--) {
        //make sure we don't go over 32 bits
        if (returnNum >= (2147483647 / 10) || returnNum <= (-2147483648 / 10)) {
            return 0;//return 0 if overflow occurs
        }
        //make sure there isn't an overflow in addition or subtraction
        if ((long) returnNum + (intArr[i] * (long)pow(10, column - 1 - i)) > 2147483647 || (long) returnNum + ((long)intArr[i] * (long)pow(10, column - 1 - i)) < -2147483648) {
            return 0;
        }
        //if there isn't, add the numbers
        returnNum += (intArr[i] * (int)pow(10, column - 1 - i));
    }

    return returnNum;
}
