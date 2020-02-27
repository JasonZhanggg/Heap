#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

void heapify (int[], int, int);
void buildHeap(int []);
void heapSort(int [], int, int);
void printTree(int [], int);
void heapify(int arr[],int len, int in){
	int largest = in;
	int l = 2*in+1;
	int r = 2*in+2;
	if(l<len && arr[l]>arr[largest])
		largest = l;
	if(r<len && arr[r]>arr[largest])
		largest = r;
	if (largest != in){
		swap(arr[in], arr[largest]);
		heapify(arr, len, largest);
	}
}
void buildHeap(int arr[], int len){
	for(int i = len/2-1; i>=0; i--){
		heapify(arr, len, i);
	}
}
void heapSort(int arr[], int len){
	buildHeap(arr, len);
	for(int i = len-1; i>= 0; i--){
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
void printTree(int arr[], int len){
	for(int i=0;i<len;i++){
		for(int j=0;j<pow(2,i)&&j+pow(2,i)<10;j++){
			cout<<arr[j+(int)pow(2,i)-1]<<" ";

		}
		cout<<endl;
	}
}
int main(){
	//char input [80];
	//char delim[] = " ";
	//cin.getline(input, sizeof(input));
	//strtok(input, delim)
	//while(input != NULL){	
	//}
	int arr[] = {1, 5, 6, 1, 2, 5};
	int len = sizeof(arr)/sizeof(arr[0]);
	heapSort(arr, len);
	printTree(arr, len);
	for(int i = 0; i<len; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}
