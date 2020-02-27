#include <iostream>
#include <cstring>

using namespace std;

void heapify (int[], int, int);
void buildHeap(int []);
void heapSort(int [], int);

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
int main(){
	//char input [80];
	//char delim[] = " ";
	//cin.getline(input, sizeof(input));
	//strtok(input, delim)
	//while(input != NULL){	
	//}
	int arr[] = {1, 5, 6, 1, 2, 5};
	heapSort(arr, sizeof(arr)/sizeof(arr[0]));
	for(int i = 0; i<sizeof(arr)/sizeof(arr[0]); i++){
		cout<<arr[i] + " ";
	}
	cout<<endl;
	return 0;
}
