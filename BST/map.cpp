//insert
#include <iostream>
#include <map>
using namespace std;


int main() {
	
	map<int,int> m;
	m.insert({10,200});
	m[5]=100;
	m.insert({3,300});

	for(auto &x:m)
	    cout<<x.first<<" "<<x.second<<endl;
	    
	cout<<"Size: "<<m.size()<<endl;
	
	m.at(10)=300;
	
	cout<<m[20]<<endl;
	cout<<m.size()<<endl;
	    
	return 0;
}

//begin & end
#include <iostream>
#include <map>
using namespace std;


int main() {
	
	map<int,int> m;
	m.insert({10,200});
	m[5]=100;
	m.insert({3,300});

	for(auto it=m.begin();it!=m.end();it++)
	    cout<<(*it).first<<" "<<(*it).second<<endl;
	    
	m.clear();
	cout<<"Size: "<<m.size()<<endl;
	cout<<"Empty: "<<(m.empty()?"Yes":"No")<<endl;
	    
	return 0;
}

// find, lower bound
#include <iostream>
#include <map>
using namespace std;


int main() {
	
	map<int,string> m;
	m.insert({5,"gfg"});
	m.insert({2,"ide"});
	m.insert({1,"practice"});

	if(m.find(5)==m.end())
	    cout<<"Not found";
	else
	    cout<<"Found";
	    cout<<endl;
	    
	for(auto it=m.find(2); it!=m.end(); it++)
	{
	    cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	    
	if(m.count(2)==0)
	    cout<<"Not found";
	else
	    cout<<"Found";
	    cout<<endl;
	auto it=m.lower_bound(7);
	if(it!=m.end())
	    cout<<(*it).first<<" ";
	else
	    cout<<"No Equal or Greater Value";
	    
	return 0;
}

// upper bound, erase
#include <iostream>
#include <map>
using namespace std;


int main() {
	
	map<int,string> m;
	m.insert({5,"gfg"});
	m.insert({2,"ide"});
	m.insert({1,"practice"});

	auto it=m.upper_bound(2);
	if(it!=m.end())
	    cout<<(*it).first<<endl;
	else
	    cout<<"Greater Value"<<endl;
	    
	m.erase(5);
	cout<<"Size: "<<m.size()<<endl;
	
	m.erase(m.find(2),m.end());
	cout<<"Size: "<<m.size()<<endl;
	
	return 0;
}