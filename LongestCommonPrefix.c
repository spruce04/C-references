//Write a function to find the longest common prefix string amongst an array of strings.
//If there is no common prefix, return an empty string "".

char* longestCommonPrefix(char** strs, int strsSize) {
    //if there are no items, we return an empty string
    if (strsSize == 0) {
        return "";
    }

    //character array (string) to be the prefix and eventually returned
    char* prefix = malloc(200 * sizeof(char));
    //if there is only 1 item, return it
    if (strsSize == 1) {
        return strs[0];
    }

    //if not then loop through the first list item as a reference
    int length = strlen(strs[0]);
    for(int i = 0; i <= length; i++) {
        //loop through each other string in the list to see if they match up to this character/index

        for(int j = 1; j < strsSize; j++) {
            //if they don't match, return out prefix as it is
            if(strs[j][i] != strs[0][i]) {
                prefix[i] = '\0';
                return prefix;
            }
            //if they do match, AND we're at the last item in our strs array, then add the character to its respective spot in prefix
            if(j == strsSize-1) {
                prefix[i] = strs[0][i];
            }
        }

        //if we are at the end of the iterations, return the finished prefix
        if(i == length) {
            prefix[i] = '\0';
            return prefix;
        }
    }
    
    //placeholder so it compiles (have to return a char*)
    return "";
}
