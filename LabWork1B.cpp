// WAP in C/C++ to read n integers and display the list. 
// Further remove the elements which will be multiple of 3 and display the array 

#include <iostream>
using namespace std;

int main() {
    // Write C++ code here
    int n, x;
    cout << "enter list lenght: ";
    cin >> n;
    
    // declare list 
    int arr[n];
    
    // populate list if n is valid 
    if (n>0){
        for (int i = 0; i<n; i++){
            cout << "\nenter " << i << " element ";
            cin >> arr[i];
            x++;
        }

        // display list
         cout << "\n Entered List ";
        for (int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }

        // search and delete
        for (int i=0;i<n ;i++){
            if(arr[i]%3==0){
                for (int j=i;j<n-1;j++){
                    arr[j] = arr[j+1];
                }
                i--;
                n--;
            }
        }
        
        //display new list 
        cout << "\n\nNew list ";
        for (int i = 0; i<n; i++){
            cout << arr[i] << " ";
        }


    }
}
