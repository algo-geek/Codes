// Handles base cases:
// If n == 1, return "1"
// If n == 2, return "11"

// Starts from "11" (which is the 2nd term)
// For each term from 3 up to n:
// It goes through the current string (str)
// It counts how many times a digit repeats
// When the digit changes, it adds the count and the digit to the result string (ans)
// After each iteration, it updates str = ans, so the next loop builds the next term

string countAndSay(int n) {
         
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        
        string str= "11";
        string ans="";
        for(int i=3;i<=n;i++)
        {
            ans="";
            int count=1;
            int j;
            for(j=1;j<str.size();j++)
            {
                
                if(str[j]!=str[j-1]){
                    ans += count + '0';
                    ans += str[j-1];
                    count=1;
                    
                }
                else count++;

            }
        ans += count + '0';
        ans += str[j-1];
            
            
        str=ans;    
        }
        return str;
        
    }
