/*Jason Zhang
 *Heap:
 *THis program takes in inputs from an file or consol and prints out a visual representation of a max heap, and sorts the data from max to min
 *3/5/2020
 */
#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

void heapify (int[], int);
void heapSort(int [], int, int);
void printTree(int [], int, int, int);
void heapifyDown(int[], int, int);
//heapify from top down for deletion
void heapifyDown(int arr[],int len, int in){
	int largest = in;
	int l = 2*in+1;
	int r = 2*in+2;
	//find the largest out of the parent, left child, and right child
	if(l<len && arr[l]>arr[largest])
		largest = l;
	if(r<len && arr[r]>arr[largest])
		largest = r;
	//if the largest is not the parent
	if (largest != in){
		//swap the parent with the largest
		swap(arr[in], arr[largest]);
		//recursivly run
		heapifyDown(arr, len, largest);
	}
}

//heapify from bottem up
void heapify(int arr[], int len){
	int parent = len/2;
	//check if the parent is larger then child
	if(arr[len]>arr[parent] && len>0){
		//if so swap parent and child
		swap(arr[len], arr[parent]);
		heapify(arr, parent);	
	}
}
//deletion of heap
void heapSort(int arr[], int len){
	//preserve length
	int origLen = len;
	for(int i = 0; i<origLen; i++){
		//print out spot 0 on array
		cout<<arr[0]<<" ";
		//set the head to the last value
		int last = arr[len-1];
		arr[0] = last;
		//decrease length by 1
		len--;
		//recursivly run
		heapifyDown(arr, len, 0);
	}
}
void printTree(int arr[], int len, int depth, int ind){
	//recursivly go to the left branch
	if(ind*2+1< len) printTree(arr, len, depth+1, ind*2+1);
	//print out spaces for formating depth number of times
	for (int i = 0; i < depth; i++) cout << "      ";
	//print out the actual value
	cout << arr[ind] << endl;
	//recursivly go to the right branch
	if(ind*2+2 < len) printTree(arr, len, depth+1, ind*2+2);
}

int main(){
	char inType;
	char input[100];
	cout<<"Type 1 for file input and 2 for manual input"<<endl;
	cin>>inType;
	cin.ignore();
	//file input
	if(inType == '1'){
		//get file name
		cout<<"Input the file name"<<endl;
		char fileName[100];
		cin.getline(fileName, sizeof(fileName));
		ifstream fileStream;
		fileStream.open(fileName);
		if(fileStream){
			fileStream.getline(input, sizeof(input));
		}
		else{
			cout<<"File does not exist"<<endl;
		}
	}	
	//manual input
	else if(inType == '2'){
		cout<<"Enter the array split by spaces"<<endl;
		cin.getline(input, 100);
	}
	//split list by space
	char* list = strtok(input, " ");
	int heap[100];
	int len = 0;
	while(list){
		heap[len] = atoi(list);
		//add 1 element in, they heapify
		heapify(heap, len);	
		list = strtok(NULL, " ");
		len++;
	}
	//print visual tree
	cout<<"________________________________________"<<endl<<endl;
	cout<<"Visual representation:"<<endl;
	printTree(heap, len, 0, 0);
	cout<<"________________________________________"<<endl<<endl;
	//print sorted list
	cout<<"Max to min:"<<endl;
	heapSort(heap, len);
	cout<<endl;
	return 0;
}
