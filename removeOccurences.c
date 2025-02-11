#include <stdio.h>
#include <string.h>


//helper function: returns -1 if the substring isn't present, if it is it returns the first index of the substring
//s: string, part: substring, len: length of substring
int in(char* s, char* part, int subLen, int strLen) {
    for(int i = 0; i <= strLen-subLen; i++) {
        //if our current index matches the substring, return the index
        //note we have to iterate through the length of the whole substring
        for(int j = 0; j < subLen; j++) {
            if(i + j > strLen) {
                return -1;
            }
            if(s[i+j] != part[j]) {
                break;
            }
            if(j == subLen-1) {//(return the index if we make it to the end)
                return i;
            }
        }
    }
    return -1;
}

//general approach: keep deleting the leftmost substring until there is none left
char* removeOccurrences(char* s, char* part) {
    int subLen = strlen(part);//the length of the substring(we calculate it once)
    int len = strlen(s);
    int index;

    while((index = in(s, part, subLen, len)) != -1) {
        //if index isn't -1, remove that index and the corresponding substring
        char* newStr = malloc(len-subLen + 1 * sizeof(char));
        int j = 0;
        for(int i = 0; i < len; i++) {
            if(i >= index && i < index + subLen) {//if we are in one of the index characters
                continue;
            }
            else {//if not put it in the newStr
                newStr[j] = s[i];
                j++;
            }
        }
        newStr[j] = '\0';
        free(s);
        s = newStr; 
        len -= subLen;
    }
    return s;
}
