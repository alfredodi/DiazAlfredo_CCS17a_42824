//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
int *fillAry(int);
int *fillMod(int,int);
void prntAry(int *,int,int);
void markSrt(int *,int);
int *sort(int *,int );
int *mode(int *,int);
void prtMod(int *);
float mean(int *,int);
float median(int *,int);
float mean(int *,int );


//Execution Begins Here
int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare and allocate the array
    int size=100;
    int *array=fillAry(size);
    //Display the random array
    prntAry(array,size,10);
    //Sort the array
    markSrt(array,size);
    //Display the random array
    prntAry(array,size,10);
    // Print the Mode
    prtMod(array);
    cout << "The Mean is: " << mean(array,size) << endl;
    cout << "The Median is: " << median(array,size) << endl;
    //Deallocate Memory
    delete []array;
    //Exit stage right
    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Print Array
//Inputs
//     n->Size of the array
//     a->Array
//Output
//     a->The sorted array
////////////////////////////////////////////////////////////////////////////////
int *sort(int *a,int n){
    //Allocate a sortable array
    int *b=new int[n];
    //Copy the array
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
    //Sort the array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(b[i]>b[j]){
                b[i]=b[i]^b[j];
                b[j]=b[i]^b[j];
                b[i]=b[i]^b[j];
            }
        }
    }
    return b;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                               Print Array
//Inputs
//     n->Size of the array
//     a->Array
//     perLine->Number of integers to display per row
////////////////////////////////////////////////////////////////////////////////
void prntAry(int *a,int n,int perLine){
    //Output the Array
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                        Fill Mode Array with mod
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with repeated numbers
////////////////////////////////////////////////////////////////////////////////
int *fillMod(int n,int mod){
    //Declare and allocate memory
    int *a=new int[n];
    //Loop and fill with repetitive numbers
    for(int i=0;i<n;i++){
        *(a+i)=i%mod;
    }
    //return the pointer
    return a;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Fill Array
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *fillAry(int n){
    //Declare and allocate memory
    int *a=new int[n];
    //Loop and fill with 2 digit numbers
    for(int i=0;i<n;i++){
        *(a+i)=rand()%90+10;
    }
    //return the pointer
    return a;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Print the Mode
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
void prtMod(int *m){
    //Print the array that contains the mode
    cout << "Number of modes found = " << m[0] << endl;
    cout << "The frequency of the modes are: " << m[1] << endl;
    if(m[0]==0)
        cout << "the mode set is equal to {0}" << endl;
    else{
        cout << "the mode is: [" <<  m[0] << "," << m[1] << ",";
        for(int a=2;a<m[0]+1;a++){
            cout << m[a] << ","; 
        }
        cout << m[m[0]+1]<< "]" << endl;
    }
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                Print the Mode
//Inputs
//     n->Size of the array
//Outputs
//     a->Array filled with 2 digit integers
////////////////////////////////////////////////////////////////////////////////
int *mode(int *a,int n){
    int *b=sort(a,n);
    int increment=0,max =0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            increment++;
            if(max <increment)max =increment;
        }else{
            increment=0;
        }
    }
    cout<<"Max = "<<max +1<<endl;
    //Count number of mods
    increment=0;
    int nmods=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            increment++;
            if(max ==increment)nmods++;
        }else{
            increment=0;
        }
    }
    cout<<"Number of Modes = "<<nmods<<endl;
    //Declare and fill the mod array
    int *mod=new int[nmods+2];
    mod[0]=nmods;
    mod[1]=max +1;
    nmods=2;
    increment=0;
    for(int i=1;i<n;i++){
        if(b[i]==b[i-1]){
            increment++;
            if(max ==increment)mod[nmods++]=b[i];
        }else{
            increment=0;
        }
    }
    delete []b;
    return mod;
}
void markSrt(int *a,int n){
    for(int pos=0;pos<n-1;pos++){
        for(int row=pos+1;row<n;row++){
            if(*(a+pos)>*(a+row)){
                *(a+pos)=*(a+pos)^*(a+row);
                a[row]=a[pos]^a[row];
                *(a+pos)=*(a+pos)^*(a+row);
            }
        }
    }
}

float mean(int *a,int size){
    float mean; 
    for(int i =0;i<size;i++){
            mean += a[i];
    }
    mean /= size; 
    return mean;
}
float median(int *a,int size){
    float med;
    if (size  % 2 == 0){
      med = (a[size / 2 - 1] + a[size / 2]) / 2;
    }
    else{ 
      med = a[size / 2];
    }
    return med; 
}