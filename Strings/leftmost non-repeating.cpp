// naive // o(n^2)
int nonRep(string &str) 
{
    for(int i=0;i<str.length();i++){
        bool flag=false;
        for(int j=0;j<str.length();j++){
            if(i!=j&&str[i]==str[j]){
                flag=true;
                break;
            }
        }
        if(flag==false)return i;
    }
    return -1;
}
 return 0; 
} 

// O(n) and O(256)
// Maintain a visited array of size 256 initialized to -1
// If a char is seen for first time, its index is stored in vis array. 
// If the char is found again then its array value is set to -2 (repeating). 
// Now, traverse vis array and check if value in the array is not equal to -1 or -2 
// (means, this character is not repeating)

const int MAX_CHAR = 26;  

char nonRep(const string& s) {
    vector<int> vis(MAX_CHAR, -1);
    for (int i = 0; i < s.length(); ++i) {
        int index = s[i] - 'a';
        if (vis[index] == -1) {
            // Store the index when character is first seen
            vis[index] = i;  
        } else {
            // Mark character as repeated
            vis[index] = -2; 
        }
    }

    int idx = -1;

    // Find the smallest index of the non-repeating characters
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (vis[i] >= 0 && (idx == -1 || vis[i] < vis[idx])) {
            idx = i;
        }
    }
    return (idx == -1) ? '$' : s[vis[idx]];
}
