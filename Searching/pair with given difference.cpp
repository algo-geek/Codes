bool findPair(int a[], int n, int d){
    //code
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    {
        if((s.find(abs(d-a[i]))!=s.end()) || (s.find(d+a[i])!=s.end()))
        {
            return true;
        }
        s.insert(a[i]);
    }
    return false;
}