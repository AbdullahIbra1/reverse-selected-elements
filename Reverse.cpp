#include <iostream>
#define SIZE 100
using namespace std;
int array1[SIZE] ;
int top = -1;
int front = -1;
int rear = -1;
int c = 0;

void push(int arr[], int item) {
    array1[++top] = item;
}

int pop(int arr[]) {    
    return array1[top--];
}          
void enqueue(int item, int size,int start,int end) {  // enqueue take the size and the item and starting - ending points
    if (c == 0) { front = rear = start-end; }     // add the starting point after calling enqueue for the first time            
    else rear++;                            // any other case we add it to the rear

    array1[rear] = item;
    c++;
}

int dequeue(int size,int start,int end) {

    int item = array1[front];
    c--;
    if (c == 0) front = rear = start-end;           
    else front++;
    return item;
}

int main()
{
    int N, startingP, endingP, item;

    cout << "How many number of inputs: ";         //select number of elements to take as input
    cin >> N;
    int* arr = new int[N];                //dynamic arrar to store the element's

    cout << "Initial input -> ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];                    //take the element's from the user
    }
    cout << "Starting point -> ";
    cin >> startingP;                     //specify the starting point and ending point for the elements we want to reverse
    cout << "Ending point -> ";
    cin >> endingP;

    for (int i = 0; i < N; i++) {
        if (i >= startingP  && i <= endingP ) {  // check to only push the elements from starting to ending  
            push(arr, arr[i]);                         // push the array and the item         
        }
    }

    for (int i = 0; i < N; i++) {
        if (i >= startingP  && i <= endingP ) {  // check to only pop the elements from starting to ending
            item = pop(arr);
            enqueue(item, N,startingP,endingP);         // and to enqueue them
            arr[i] = dequeue(N, startingP, endingP); //dequeue the selected indexes to reverse the element from starting to ending
        }
    }

    cout << "Final Output -> ";                 // print the final output
    for (int i = 0; i < N; i++) {
        cout << arr[i]<<" ";
    }
    cout << endl;
    return 0;
}