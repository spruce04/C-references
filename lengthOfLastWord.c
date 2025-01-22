//general approach - loop through the string from the end to the front

int lengthOfLastWord(char* s) {
    int lastLength = 0;
    int length = strlen(s);
    printf("%d", length);
    int index = 0;
    int word = 0;
    char current = ' ';
    char next = ' ';

    //if it is a one character string
    if(length == 1) {
        if(s[0] != ' ') {
            return 1;
        }
        else {
            return 0;
        }
    }

    for(int i = length - 1; i > 0; i--) {
        current = s[i];
        next = s[i-1];
        //if we come to the start of a word, increment length and set word to true
        if(current != ' ' && word == 0) {
            lastLength++;
            word = 1;
            //this covers 1 letter words
            if (next == ' ') {
                return lastLength;
            }
        }

        //if we're in the word and its not ending next character, increment length
        else if (word == 1 && next != ' ') {
            lastLength++;
            //if we are at the second last character, we have to add one because the loop can't go to i = 0.
            if(i == 1 && next != ' ') {
                lastLength++;
            }
        }

        //if we're at the end of the word (in the word and next is a space of at our last index), increment lastLength and return it
        else if(word == 1 && next == ' ' || (i == 1 && next != ' ')) {
            lastLength++;
            return lastLength;

        }
    }
    return lastLength;
}
