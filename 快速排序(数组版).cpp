#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int partion(int arr[], int begin, int end){
	int guard = arr[begin];
	while(begin < end){
		while(arr[end] >= guard && begin < end){
			end--;
		}
		arr[begin] = arr[end];
		
		while(arr[begin] < guard && begin < end){
			begin++;
		}
		arr[end] = arr[begin];
	}
	arr[begin] = guard;
	return begin;
}

void quick_sort(int arr[], int begin, int end){
	if(begin >= end)
		return ;
	int mid = partion(arr, begin, end);
	quick_sort(arr, begin, mid-1);
	quick_sort(arr, mid+1, end);
}

int main(){
	int arr[] = {2,4,1,6,3,5,9,10,7,8,15,12,11,13,14};
	int arr_len = sizeof(arr)/sizeof(int);
	print(arr, arr_len);
	printf("ÅÅÐòºó:\n");
	quick_sort(arr, 0, arr_len-1);
	print(arr, arr_len);
//	string s1,s2,s3;
//	cin>>s1;  //cin»á½«¿Õ°××Ö·ûÁôÓÚ»º³åÇøÖÐ 
//	getline(cin, s2); //getline»áÉáÆú \n
//	cin>>s3;
//	cout<<s1<<endl<<s2<<endl<<s3;
//	string s;
//	while(cin>>s){
//		cout<<s<<'a'<<s1<<'a'; 
//	}
	
	return 0;
}

