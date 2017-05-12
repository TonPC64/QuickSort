#include<iomanip>
#include<iostream>
#include<vector>
#include<string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>

using namespace std;
int n=0;
bool flag=true; 

template<class Comparable>
int insertionSort(vector<Comparable> & a,int left,int right){
	for(int p=left+1;p<=right;p++){
		Comparable tmp=a[p];
		int j;
		for(j=p;j>left&&tmp<a[j-1];j--){
			a[j]=a[j-1];
		}
		a[j]=tmp;
	}
	return 0;
}

template<class Comparable>
const Comparable &median3(vector<Comparable> &a,int left,int right){
	int center=(left+right)/2;
	if(a[center]<a[left])
		swap(a[left],a[center]);
	if(a[right]<a[left])
		swap(a[left],a[right]);
	if(a[right]<a[center])
		swap(a[right],a[center]);
	swap(a[center],a[right-1]);
	return a[right-1];
}

template<class Comparable>
int quicksort(vector<Comparable> &a,int left,int right){
	++n;
	if(left+3<=right){
		Comparable pivot=median3(a,left,right);
		int i=left,j=right-1;
		for(;;){
			while(a[++i]<pivot){}
			while(a[--j]>pivot){}
			if(i<j)
				swap(a[i],a[j]);
			
			else{
				break;
				}
		}
		swap(a[i],a[right-1]);
				cout<<"\n  Round "<<n;
		for(int i=0;i<a.size();i++)
			cout<<"    "<<a[i];
			cout<<"   Pivot : " <<pivot;
		quicksort(a,left,i-1);
		quicksort(a,i+1,right);
	}
	else {insertionSort(a,left,right);		
	cout<<"\n  Round "<<n;
		for(int i=0;i<a.size();i++)
			cout<<"    "<<a[i];}
	return 0;
}

template<class Comparable>
int swap(int &num1,int &num2){
	int tmp=num1;
	num1=num2;
	num2=tmp;
	return 0;
}

int randvalue (int block[]) {
	for(int i = 0 ; i < 10 ;i++ ){
		block[i] = -1;
	}
		
	bool flag ;
	int count;
	for(int i = 0 ; i < 10 ;i++ ){
		flag = true;
		do {
			count = rand()%10;
			
			if (block [count ] == -1 ){
				block [count] = (100+(i+1)*89);
				block [count] = block [count] / 10;
				flag = false;
			}
		} while(flag); 
	}
	return 0;
}

int main(){
	srand (time(NULL));
	vector<int> x(1);
	string choice;
	bool exit = true;
	bool create = false;
	x.resize(10);
	int number[10];
	randvalue(number);
	for (int i=0;i<10;i++) {
		cout<<number[i]<<" ";
	}
	for (int i=0;i<10;i++) {
		x[i] = number[i];
	}
	cout<<endl;
	string pass = "";
	char ch;
	do {
		cout<<"Enter Password : ";
	    ch = _getch();
	   while(ch != 13){//character 13 is enter
	      pass.push_back(ch);
	      cout << '*';
	      ch = _getch();
	   }
	   cout<<endl;
	   if(pass != "1150") {
	   	pass = "";
	   }
	} while(pass != "1150");
	int num = 10;
	system("cls");
	cout<<"  QuickSort Lower to Higher\n";
	cout<<"  Original   ";
	for(int i=0;i<num;i++)
		cout<<x[i]<<"    ";
	cout<<"\n   ------------------------------";
	quicksort(x,0,num-1);
	cout<<"\n   ------------------------------";
	cout<<"\n  final      ";
	for(int i=0;i<num;i++)
		cout<<x[i]<<"    ";
	cout<<endl;
	system("PAUSE");

//	do{
////		system("cls");
//		cout << "\n\t\t\t===============================\n";
//		cout << "\t\t\t.:: Assignment4 [ QuickSort ] ::.\n";
//		cout << "\t\t\t===============================\n";
//		cout << "\t\t\t1.) Create Input";
//		cout << "\n\t\t\t2.) Quick Sort";
//		cout << "\n\t\t\t3.) Exit";
//		cout << "\n\t\t\t===============================";
//		cout <<"\n\n\t\t\tEnter Choice : ";
//		cin >> choice;
//		switch (choice[0])
//		{	
//		case '1':
//			system("cls");
//				int num;
//				cout<<"      How many for input : ";
//				cin>>num;
//				 x.resize(num);
//				for(int i=0;i<num;i++){
//					cout<<"   Input Data ["<<i<<"] : ";
//					cin>>x[i];
//				}
//				create = !create;
//				system("pause");
//			break;
//
//		case '2':
//			system("cls");
//			if (create)
//			{	
//				cout<<"         QuickSort Lower to Higher\n";
//				cout<<"  Original   ";
//				for(int i=0;i<num;i++)
//					cout<<x[i]<<"    ";
//				cout<<"\n   ------------------------------";
//				quicksort(x,0,num-1);
//				cout<<"\n   ------------------------------";
//				cout<<"\n  final      ";
//				for(int i=0;i<num;i++)
//					cout<<x[i]<<"    ";
//				system("PAUSE");
//			}
//			else
//			{
//				cout << "\n\t\t\t!!!Must Insert before sort!!!\n\n";
//				system("pause");
//			}
//			break;
//
//		case '3':exit=false;
//		}
//	} while (exit);
	return 0;
}
