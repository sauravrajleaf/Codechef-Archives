#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    
	    if(n == 4){
	        if(a[0] + a[1] == a[2] + a[3]){
	            cout << "NO" << endl;
	        }
	        else{
	            cout << "YES" << endl;
	        }
	    }
	    else{
	        bool allsame = true;
	        int temp = a[0];
	        
	        for(int i = 1;i<n;i++){
	            if(a[i] != temp){
	                allsame = false;
	                break;
	            }
	        }
	        
	        if(allsame){
	            cout << "NO" << endl;
	        }
	        else{
	            cout << "YES" << endl;
	        }
	    }
	}
	return 0;
}