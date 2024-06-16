#include<iostream>
using namespace std;
struct node{
	string name;
	int data;
	struct node *next;
	
};
node *makenode(int x,string name){
	node *newnode = new node;
	newnode ->name = name;
	newnode -> data = x;
	newnode -> next = NULL;
	return newnode;
}

 void duyet(node *head){
 	while(head != NULL){
 		cout<<head->data<<" "<<endl;
 		cout<<head->name<<" "<<endl;
 		head = head -> next;
	 }
 }
 void pushFront(node *&head , int x,string ten){
 	node *newnode = makenode(x,ten);
 	newnode -> next = head;
 	head = newnode;
 }
 void pushBack(node *&head , int x ,string ten){
 	node *temp = head;
 	node *newnode = makenode(x,ten);
 	if(head == NULL){
 		head = newnode;
 		return;
	 }
	 while(temp->next !=NULL){
	 	temp = temp->next;
	 }
	 temp->next = newnode;
 }
 int size(node *&head){
 	int d = 0;
 	node *temp = head;
 	while(temp !=NULL){
 		d++;
 		temp = temp ->next;
	 }
	 return d;
 }
 void input(node *&head){
 	int i,c,n;
 	string ten;
 	cout<<"Nhap so luong phan tu cua day : ";
 	cin>>n;
 	for(i = 0;i<n;i++){
 		cout<<"pt"<<i<<" : ";
 		cin>>c;
 		cout<<"Ten"<<i<<" : ";
 		cin>>ten;
 		pushBack(head,c,ten);
	 }
	
 }
 void insert(node *&head){
 	 
 	int k,x,i;
 	string ten;
 	int n = size(head);
 	cout<<"Nhap vi tri can chen : ";
 	cin>>k;
 	cout<<"Nhap so can chen : ";
 	cin>>x;
 	if(k<1&&k>n+1){
 		return;
	 }
	 if(k==1){
	 	pushFront(head,x,ten);
	 }
	 if(k>1&&k<n){
	node *temp = head;
	for(i=1;i<=k-2;i++){
		temp = temp->next;
	}
	node *newnode = makenode(x,ten);
	newnode->next = temp->next;
	temp->next = newnode;
}
 }
 void popFront(node *&head){
 	if(head == NULL){
 		return;
	 }
	 node *temp = head;
	 head = head -> next ;
	 delete temp;
 }
 void popBack(node *&head){
 	if(head == NULL){
 		return;
	 }
	 node *temp =head;
	 if(temp ->next == NULL){
	 	head =NULL ;
	 	delete temp;
	 }
	 while(temp->next->next !=NULL){
	 	temp = temp ->next;
	 }
	 node *last = temp ->next;
	 temp -> next =NULL;
	 delete last;
 }
 void popmid(node *&head){
 	int i,k;
 	cout<<"Nhap vi tri can xoa : ";
 	cin>>k;
 	if(head == NULL){
 		return;
	 }
	 node *temp =head;
	 if(temp ->next == NULL){
	 	head =NULL ;
	 	delete temp;
	 }
	 for(i=1;i<=k-2;i++){
	 	temp = temp ->next;}
	 	node *mid = temp->next;
	 	temp->next = mid ->next;
	 	delete mid;
 }
 void bubleSort(node *&head){

 	for( node *i = head;i!=NULL;i=i->next){
 		for(node *j=i->next;j!=NULL;j=j->next){
 			if(i->data>j->data){
 			swap(i->data,j->data);
 			swap(i->name,j->name);
 		}
		 }
	 }
 }
int main(){
	node *head = NULL ;
	input(head);
//	duyet(head);
//	cout<<endl;
//	insert(head);
//   popBack(head);
//popmid(head);
bubleSort(head);
	duyet(head);
   
}