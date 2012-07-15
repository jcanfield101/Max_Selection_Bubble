/***************************************************************
** Name:     Jonathan Canfield				                  **
**      									                  **
***************************************************************/
#include <iostream>
#include <ctime>
#include <cstdio>
#include <fstream>
using namespace std;

using namespace std;
int best =0;

/***************************************************************
** Finding the Max size element from a N size array, returns  **
** the max element. derived from professor Wortman's Alg.     **
****************************************************************/
int MaxElement(int* RandomArray, int ArraySize){
	
	for (int i=0; i!=ArraySize; i++){
		 if (RandomArray[i] > best)
			 best = RandomArray[i];}
return best;	
}

/***************************************************************
** Selection Sort. The Alg was derived from                   **
** http://en.wikipedia.org/wiki/Selection_sort                **
***************************************************************/
void SelectionSort(int* RandomArray, int ArraySize){
	int tmp;

	for (int head = 0; head < ArraySize-1; head++){
		int location = head;
		
		for (int i = head+1; i < ArraySize; i++){
			if (RandomArray[i] < RandomArray[location])
				location = i;}
		
		if (location != head){
			tmp = RandomArray[head];
			RandomArray[head] = RandomArray[location];
			RandomArray[location] = tmp;}
	}
}
/***************************************************************
** Bubble Sort. The Alg was derived from                      **
** http://en.wikipedia.org/wiki/Bubble_sort                   **
***************************************************************/
void BubbleSort(int* RandomArray, int ArraySize){
	bool exchange = true;
	int tmp;

	while (exchange){
		exchange = false;
		for (int i = 0; i < ArraySize-1; i++){
			if (RandomArray[i] > RandomArray[i+1]){
				tmp = RandomArray[i];
				RandomArray[i] = RandomArray[i+1];
				RandomArray[i+1] = tmp;
				exchange = true;}
		}
		ArraySize = ArraySize - 1;
	}
}

/***************************************************************
** When users wants to run all the algs. this function is     **
** called. simply starts clock runs alg then stops the clock  **
** and time for the alg to run is shown                       **
***************************************************************/
void runAll (int* RandomArray,int ArraySize){
	
	double t2;
	double t1;
	t1 = clock();
	best=MaxElement(RandomArray, ArraySize);
	t2 = ( std::clock() - t1 ) / (double)CLOCKS_PER_SEC;
	cout<<"Max Element     "<<t2 << endl;
					
	t1 = clock();
	SelectionSort(RandomArray, ArraySize);
	t2 = ( std::clock() - t1 ) / (double)CLOCKS_PER_SEC;
	cout<<"Selection Sort  "<<t2 <<endl;
	
	//since the array is sorted after the selection sort the array
	//needs to be recreated with random ints. 
	for (int i = 0; i < ArraySize; i++){
		RandomArray[i] = rand()%100000;}
			
	t1 = clock();
	BubbleSort(RandomArray, ArraySize);
	t2 = ( std::clock() - t1 ) / (double)CLOCKS_PER_SEC;
	cout<<"Bubble Sort     " <<t2 << endl<<endl;
				
}



int main()
{
	int* RandomArray;    //Array used for algs.
	int ArraySize=0;	 //Size of the array
	double t1;			 //start timer				
	double t2;			 //end timer
	int num_runs=1;      //set num of run times
	int count=0;         
	int alg_choice=0;    //users alg choice 
	char run_more='y';   //option to run again
        
	  //everything sits inside this while loop. Only ends when the user
	  //input of run times ends and/or if the users wants to do another 
	  //run. 
	//while (num_runs != count){
		while (run_more=='y'){
		    if (count==0 && run_more !='n'){
			cout<<"Size of array? ";
			cin>>ArraySize;
			//cout<<"How many runs? ";
		   //cin>>num_runs;
	        cout<<"What Alg would you like to run?"<<endl;
			cout<<"Max Element:    1"<<endl;
			cout<<"Selection Sort: 2"<<endl;
			cout<<"Bubble Sort:    3"<<endl;
			cout<<"To run all:     4"<<endl;
			cin>>alg_choice;
			 }

			//setting the array to the user size
			RandomArray = new int[ArraySize];
		   
			//filling the array with random ints
			for (int i = 0; i < ArraySize; i++){
				RandomArray[i] = rand()%100000;}
				cout<<endl<<"Size of array   "<<ArraySize<<endl;
				
			//switch statement for the 3 differnt algs and the 
			//final option to run all of them for the test. the 
            //array size needs to be large for Max element to give 
			//a proper time since it runs linear. 
			switch (alg_choice){
				case 1:
					t1 = clock();
					best=MaxElement(RandomArray, ArraySize);
					t2 = ( std::clock() - t1 ) / (double)CLOCKS_PER_SEC;
					cout<<"Max Element     "<<t2<<" seconds" << endl;
					break;
				 case 2:
					t1 = clock();
					SelectionSort(RandomArray, ArraySize);
					t2 = ( std::clock() - t1 ) / (double)CLOCKS_PER_SEC;
					cout<<"Selection Sort  "<<t2<<" seconds" <<endl;
					break;
				 case 3:
					t1 = clock();
					BubbleSort(RandomArray, ArraySize);
					t2 = ( std::clock() - t1 ) / (double)CLOCKS_PER_SEC;
					cout<<"Bubble Sort     " <<t2 <<" seconds"<< endl<<endl;
					break;
				case 4:
					runAll(RandomArray, ArraySize);
					break;

			}
				
			count++;
			//increasing the array size by a factor of 2
			ArraySize = ArraySize * 2;
			
			delete [] RandomArray;

			if (count == num_runs){
				 cout<<endl<<"would you like to do another run(y or n)? ";
				 cin>>run_more;
				 if (run_more == 'y')
					 count=0;
			}
		}	

	system ("pause");
	return 0;
}