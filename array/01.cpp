#include<iostream>
#include<string>
using namespace std;

int main(){

	// arr+(size)*index 

	int ar1[] = {1,2,3,4,5,6,7,8,9};

	// int* br1 = ar1
	
	int arr[][2][1] ={
		{{1},{2}}
		,{{4},{6}}
		};

	int a = 10;
	int* b = &a; 
	
	
	// char s[] ={'H','e','l','l','o','\0'};
	// char* st = s;
	// string s = {'H','e','l','l','o'};

	

	// printf("%c",s[0]);


	// cout<<a;  



	

	
	
	// *b = 2; 
	// cout<<a<<'\n';
	// cout<<*b;
	// cout<<*(*(*(arr+0)+1)+0);
        //         0     1    2
	// 0 [    1     2    3       ]
	// 1 [     4    6    7       ]
	// cout<<arr[1][1];
	// cout<<*(*(arr+1)+1);

	// cout<<sizeof arr/sizeof(int);





	// cout<<(arr+4)<<'\n';
	
	return  0;
}
