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

const int CHAR=256;
int nonRep(string &str) 
{
    int fI[CHAR];
    fill(fI,fI+CHAR,-1);
    
    for(int i=0;i<str.length();i++){
        if(fI[str[i]]==-1)
        fI[str[i]]=i;
        else
        fI[str[i]]=-2;
    }
    int res=INT_MAX;
    for(int i=0;i<CHAR;i++){
        if(fI[i]>=0)res=min(res,fI[i]);
    }
    return (res==INT_MAX)?-1:res;
}
 
int main() 
{ 
    string str = "geeksforgeeks";
    cout<<"Index of leftmost non-repeating element:"<<endl;
    cout<<nonRep(str)<<endl;  
    
    return 0; 
} 
