#include<iostream>
using namespace std;
#define max 100
struct list{
 int n;
 int a[max];

}l;

void input(){
	int b = 1;
	l.n = 1;
	while(b != 0){
	 cout<<"Nhap a ["<<l.n<<"] : ";
		cin>>l.a[l.n];
		b = l.a[l.n];
		l.n++;
		if(b==0){
		l.n-=2;	
		}
	}
	cout<<endl;  
}
void output(){
	int m = l.n;
	int i;
	for(i = 1 ;i<= m ;i++){
		cout<<l.a[i]<<" ";
	}
	cout<<endl;
}
void insert(){
	int x,k;
	int i;
	cout<<"Nhap phan tu can chen : ";
	cin>>x;
	cout<<endl;
	cout<<"Nhap vi tri can chen : ";
	cin>>k;
	cout<<endl;
	l.n++;
	for(i = l.n ;i > k ;i--){
		l.a[i] = l.a[i-1];
	}
	l.a[k] = x;
	cout<<"Mang sau khi chen la : "<<endl;
	output();
}
void search(){
	int i,z;
	int c = 0;
	cout<<"Nhap phan tu can tim kiem : ";
	cin>>z;
	for(i = 1 ;i <= l.n ;i++){
		if(l.a[i] == z){
			c++;
		}
	}
	if(c==0){
		cout<<"phan tu z khong co trong danh sach ";
	}
	else{
		cout<<"cac vi tri cua phan tu z la :  ";
		for(i = 1 ;i <= l.n ;i++){
		if(l.a[i] == z){
			cout<<i<<" ";
		}
	}
}
}
void selectionSort(){
	int i,j,min;
	for(i= 1;i<l.n;i++){
		min = i;
		for(j = min ;j<=l.n;j++){
			if(l.a[j] < l.a[min]){
				min = j;
			}
		}
		swap(l.a[i],l.a[min]);
	}
}
void insertionSort(){
	int x,i ;
	int pos;
	for(i=2;i<=l.n;i++){
		x = l.a[i];
		pos = i - 1;
	while(pos>=1 && x < l.a[pos]){
			l.a[pos + 1] = l.a[pos];
			pos--;
		}
		l.a[pos + 1] = x;
	}
}
void bubleSort(){
	int i,j;
	for(i=1;i<l.n;i++){
		for(j=i+1;j<=l.n;j++){
			if(l.a[i]>l.a[j]){
				swap(l.a[i],l.a[j]);
			}
		}
	}
}
//void quickSort(){
//	
//}
//xoa khoi danh sach nhung so le
void Delete(int x){
	int i;
	for(i = x ;i<=l.n;i++){
		l.a[i] = l.a[i+1];
	}
}
void oddDelete(){
	int i;
	for(i=1;i<=l.n;i++){
		if(l.a[i]%2!=0 ){
			Delete(i);
			l.n--;
		}
	}
}
void splitList() {
    int l1[100];
    int l2[100];
    int n1 = 0;
    int n2 = 0;
    for (int i = 1; i <= l.n; i++) {
        if (l.a[i] < 0) {
            l1[n1] = l.a[i];
            n1++;
        } 
		else {
            l2[n2] = l.a[i];
            n2++;
        }
    }
    n1--;
    n2--;
    for(int i =0;i<n1;i++){
    	cout<<l1[i]<<" ";
	}
	cout<<endl;
	for(int i =0;i<n2;i++){
		cout<<l2[i]<<" ";
	}
}

void chenam(){
	int v = l.n;
	int mid = v/2 + 1 ;
	int i,x;
	l.n++;
	cout<<"Nhap so am can chen : ";
	cin>>x;
	for(i = l.n;i>mid;i--){
		l.a[i] = l.a[i-1];
	}
	l.a[mid] = x;
}
void split(){
	int l1[100];
	int n1 = 0;
	int i,j;
	for(i=1 ;i<=l.n;i++){
		if(l.a[i]%5==0&&l.a[i]%4!=0){
			l1[n1] = l.a[i];
			n1++;
		}
	}
	n1--;
	for(j=0;j<=n1;j++){
		cout<<l1[j]<<" ";
	}
}
int tongchuso(int c){
	int d = 0;
	while(c!=0){
	 d  += c % 10;
	 c/=10;
	}
	return d;
}
void chiahetba(){
	int l3[100];
	int n3 = 0;
	int i,j;
	for(i=1 ;i<=l.n;i++){
		if(tongchuso(l.a[i]) %3 == 0){
			l3[n3] = l.a[i];
			n3++;
		}
    }
    	n3--;
	for(j=0;j<=n3;j++){
		cout<<l3[j]<<" ";
	}
}
int sohoanhao(int c){
	int i;
	int d =0;
	for(i = 1; i < c;i++){
		if(c%i==0){
			d += i;
		}
	}
	if(d==c){
		return 1;
	}
	else{
		return 0;
	}
}
void xoasohh(){
	int i;
	for(i=1 ;i<=l.n;i++){
		if(sohoanhao(l.a[i])==1){
			Delete(i);
		}
}
l.n--;
output();
}
int timkiemnhiphan(){
   int x;
   int li = 1;
   int r = l.n;
   int mid;
   mid = (li + r)/2;
   
   cout<<"Nhap phan tu can tim : ";
   cin>>x;
   while(li<=r){
   	if(l.a[mid]=x){
   		return mid;
	   }
	else if(l.a[mid]<x){
		li = l.a[mid] +1;
	}
	else{
		r = l.a[mid]-1;
	}
   }
}
int songuyento(int c){
	int i;
	int d = 0;
	if(c<=1){
		return 0;
	}
	else{
	for(i =2;i*i<=c;i++){
		if(c%i==0){
			d++;
		}
	}
	if(d==0){
		return 1;
	}
	else{
		return 0;
	}
}
}
void demsnt(){
	int i;
	int d = 0;
	for(i = 1;i<=l.n;i++ ){
		if(songuyento(l.a[i])==1){
		d++;	
		}
	}
	cout<<"So so nguyen to : "<<d;
}
int main(){
	input();
	output();
//	insert();
//	search();
//	selectionSort();
//insertionSort();
//    bubleSort();
//oddDelete();

//	output();
//splitList();
// chenam();
// output();
//split();
//xoasohh();
//cout<<timkiemnhiphan();
demsnt();
}