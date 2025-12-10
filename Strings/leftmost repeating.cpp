// index of lefmost first repeating character
// naive // O(n^2)
int leftMost(string &str) 
{
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length();j++){
            if(str[i]==str[j])return i;
        }
    }
    return -1;
}


// O(n) and O(256)
// take a vis array initialized to -1
// if char not seen before, update vis to store idx 
// else, calc min idx
int firstRepeating(string& str)
{
    // Initialize leftmost index of every
    // character as -1.
    int firstIndex[NO_OF_CHARS];
    for (int i = 0; i < NO_OF_CHARS; i++)
        firstIndex[i] = -1;

    // Traverse from left and update result
    // if we see a repeating character whose
    // first index is smaller than current
    // result.
    int res = INT_MAX;
    for (int i = 0; i < str.length(); i++) {
        if (firstIndex[str[i]] == -1)
           firstIndex[str[i]] = i;
        else
           res = min(res, firstIndex[str[i]]);
    }

    return (res == INT_MAX) ? -1 : res;
}
