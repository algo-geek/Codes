// check if string 2 is anagram (chars order diff) of string 1

// Compares pat and a substring of txt starting at index i to see if they are anagrams.
// count[pat[j]]++ :  increments count for each character in pat
// count[txt[i+j]]-- :  decrements for the corresponding character in the substring of txt
// If all values in count are zero at the end, the substring is an anagram.
// naive // O((n-m+1)*m)
#include <bits/stdc++.h> 
using namespace std; 
 
const int CHAR=256; 
bool areAnagram(string &pat, string &txt,int i) 
{ 
    int count[CHAR]={0};
    for(int j=0;j<pat.length();j++){
        count[pat[j]]++;
        count[txt[i+j]]--;
    }
    for(int j=0;j<CHAR;j++){
        if(count[j]!=0)return false;
    }
    return true;
}

bool isPresent(string &txt,string &pat){
    int n=txt.length();
    int m=pat.length();
    for(int i=0;i<=n-m;i++){
        if(areAnagram(pat,txt,i))return true;
    }
    return false;
}
 
int main() 
{ 
    string txt = "geeksforgeeks"; 
    string pat = "frog"; 
    if (isPresent(txt,pat)) 
        cout << "Anagram search found"; 
    else
        cout << "Anagram search not found"; 
        
    string txt2 = "geeksforgeeks"; 
    string pat2 = "rseek"; 
    if (isPresent(txt2,pat2)) 
        cout << "Anagram search found"; 
    else
        cout << "Anagram search not found"; 
  
    return 0; 
} 

// efficient // O(n* char) // sliding window

// take 2 freq count arrays for both strings
// Count characters of pat in CP[] and the first window of txt in CT[].
// Slide the window one character at a time:
// After each slide, compare CT and CP using areSame().
// If they match, an anagram is found.
#include <bits/stdc++.h> 
using namespace std; 
 
const int CHAR=256; 

bool areSame(int CT[],int CP[]){
    for(int i=0;i<CHAR;i++){
        if(CT[i]!=CP[i])return false;
    }
    return true;
}

bool isPresent(string &txt,string &pat){
    int CT[CHAR]={0},CP[CHAR]={0};
    for(int i=0;i<pat.length();i++){
        CT[txt[i]]++;
        CP[pat[i]]++;
    }
    for(int i=pat.length();i<txt.length();i++){
        // areSame will takes O(char) time as two arrays of char size are checked
        if(areSame(CT,CP))
        return true;

        CT[txt[i]]++;
        CT[txt[i-pat.length()]]--;
    }
    return false;
}
 
int main() 
{ 
    string txt = "geeksforgeeks"; 
    string pat = "frog"; 
    if (isPresent(txt,pat)) 
        cout << "Anagram search found"; 
    else
        cout << "Anagram search not found"; 
  
    string txt2 = "geeksforgeeks"; 
    string pat2 = "rseek"; 
    if (isPresent(txt2,pat2)) 
        cout << "Anagram search found"; 
    else
        cout << "Anagram search not found"; 
    return 0; 
} 
