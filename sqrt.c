int mySqrt(int x) {
    int i = 0;
    int previous = 0;
    //loop through all numbers
    while(true) {
        //if x is less than i * i, return the previous number
        //basically the first time i * i is greater than x, we know sqrt x will be the previous int (floored)

        //we have to cast to a long long to avoid errors with big values
        if ((long long)i * i > x) {
            return previous;
        }
        previous = i;
        i++;
    }
}
