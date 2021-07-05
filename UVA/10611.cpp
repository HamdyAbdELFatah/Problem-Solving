//============================================================================
// Author      : Hamdy Abd El Fattah
// Code is like humor. When you have to explain it, it’s bad.
//============================================================================
#include <bits/stdc++.h>
#define FIO cin.tie(0), cin.sync_with_stdio(0)
#define ll long long
#define INF 0x3f3f3f3f
#define INFL LLONG_MAX
using namespace std;
int answer = -1,size;
void search_upper(int arr[],int l , int r, int x){
	if(x >= arr[size]){
		answer = -1;
		return;
	}
	int mid = ( l + r ) / 2;
	if(arr[mid] > x){
		r = mid - 1;
		answer = mid;
	}else
		l = mid + 1 ;
	if(l <= r)
		search_upper(arr , l, r , x);

}
void search_lower(int arr[],int l , int r, int x){
	if(x <= arr[0]){
		answer = -1;
		return;
	}
	int mid = ( l + r ) / 2;
	if(arr[mid] < x){
		l = mid + 1;
		answer = mid;
	}else
		r = mid -1 ;
	if(l <= r)
		search_lower(arr , l, r , x);
}
int main() {
	FIO;
	int n, m , q;
	cin>>n;
	size =n-1;
	int arr[n];
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];

	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> q;
		search_lower(arr , 0, n - 1 , q);
		if(answer != -1)
			cout<<arr[answer]<<" ";
		else
			cout<<"X ";
		search_upper(arr , 0, n - 1 , q);
		if(answer != -1)
			cout<<arr[answer]<<endl;
		else
			cout<<"X\n";
	}

	return 0;
}
