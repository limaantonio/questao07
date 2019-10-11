#include<iostream>
#include<algorithm>

using namespace std;

void bubbleSort(string v, int t){
  char aux;
  for(int i=0; i<t-1; i++){
      for(int j=0; j<t-i-1; j++){
          if(v[j] < v[j+1]){
              aux = v[j];
              v[j] = v[j+1];
              v[j+1] = aux;
          }
      }
    }
    cout <<  v << endl;
}

void insertionSort(string world, int n){
  
  int x, j;
  for(int i=1; i<n; i++){
    x=world[i];
    j=i-1;
    while(j >=0 && world[j]>x){
      world[j+1] = world[j];
      j=j-1;
    }
    world[j+1] = x;
  }
  for(int i=n-1; i>=0; i--)cout << world[i];
  cout << endl;
}

void selectionSort(string world, int n){

  char aux;
  int min;

  for(int i =0; i<n-1;i++){
    min = i;
    for(int j=i+1; j<n; j++){
      if(world[j] > world[min]){
        min = j;
      }
    }
    aux = world[i];
    world[i] = world[min];
    world[min] = aux;
  }
  cout << world << endl;
  
}

int maximo(string A, int n)
 {
	int i, max = A[0];
	
	for(i = 1; i < n; i++ )
		if(A[i] > max)
			max = A[i];
			
	return max;
}

void coutingSort(string A, int n)
 {
	int i;
	int k = maximo(A, n);
	int B[n], C[k + 1];
	
	for(i = 0; i < n; i++)
		B[i] = 0;
	
	for(i = 0; i < k; i++)
		C[i] = 0;

	for(i=0;i<n;i++) C[A[i]-1]++;

	for(i=1;i<k;i++) C[i] += C[i-1];

	for(i=n-1;i>=0;i--) 
	{
		B[C[A[i]-1]-1] = A[i];
		C[A[i]-1]--;
	}

	for(i=0;i<n;i++) A[i] = B[i];

   for(int i=n-1; i>=0; i--)cout << A[i];
  cout << endl;
}

int main(){

  string v;

  cin >> v;
  int t = v.size();

  cout << "Ordenacao BubbleSort" << endl;
  bubbleSort(v, t);
  cout << "Ordenacao InsertionSort" << endl;
  insertionSort(v, t);
  cout << "Ordenacao SelectionSort" << endl;
  selectionSort(v, t);
  cout << "Ordenacao CountignSort" << endl;
  coutingSort(v, t);
 
  return 0;
}
