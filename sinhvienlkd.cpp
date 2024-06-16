#include<iostream>
#include<iomanip>
using namespace std;
struct sinhvien{
	string msv;
	string hovaten;
	double diemtb;
};
struct node{
	sinhvien data;
	struct node *next;
};
 node *makenode(sinhvien s){
 	node *newnode = new node;
 	newnode->data = s;
 	newnode-> next = NULL;
 	return newnode;
 }
 void output(node *&head){
 	node *temp = head;
 	while(temp != NULL){
 		cout<<temp->data.msv<<" "<<temp->data.hovaten<<" "<<temp->data.diemtb<<endl;
 		temp = temp ->next;
	 }
 }
  void pushBack(node *&head,sinhvien s){
 	node *newnode = makenode(s);
 	if(head == NULL){
 		head = newnode;return;
	 }
	 node *temp = head;
	 while(temp->next !=NULL){
	     temp = temp->next;
	 }
	 temp -> next = newnode;
 }
 void pushFront(node *&head,sinhvien s){
 	node *newnode = makenode(s);
 	if(head == NULL){
 		head = newnode;return;
	 }
	 
	 newnode->next = head;
	 head = newnode;
 }
 void input(node *&head,sinhvien s){
 	int n,i;
 	cout<<"Nhap so luong sinh vien : ";
 	cin>>n;
 	for(i=0;i<n;i++){
 		cout<<"Nhap msv cua sv "<<i<<" : ";cin>>s.msv;
 		cout<<"Nhap hovaten cua sv "<<i<<" : ";cin>>s.hovaten;
 		cout<<"Nhap diemtb cua sv "<<i<<" : ";cin>>s.diemtb;
 		pushBack(head,s);
	 }	 
 }
void bubleSort(node *head){
 for(node *i = head;i!=NULL;i=i->next){
 	for(node *j = i->next;j!=NULL;j=j->next){
 		if(i->data.diemtb<j->data.diemtb){
 			swap(i->data.diemtb,j->data.diemtb);
 			swap(i->data.hovaten,j->data.hovaten);
 			swap(i->data.msv,j->data.msv);
		 }
	 }
 }
}
void popmid(node *head,int k){
	int i;
	node *temp = head;
  if(temp ==NULL){
  	return;
  }
  
  else if(temp->next == NULL){
  	head = NULL;
  	delete temp;
  }
  else{
  	for(i=1;i<=k-2;i++){
  	temp =	temp->next;
	  }
	  node *mid = temp->next;
	  temp->next = mid->next;
	  delete mid;
  }
}
void deleteLowScoreStudents(node*& head) {
	if (head == NULL) return;
    while (head != NULL && head->data.diemtb < 5) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
}
 int main(){
 	node *head =NULL;
 	sinhvien s;
 	input(head,s);
// 	bubleSort(head);
deleteLowScoreStudents(head);
 	output(head);
 	
 }