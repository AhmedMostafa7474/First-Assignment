#include <iostream>
#include <algorithm>
using namespace std;
void screen();
void screen2();
void loop();
void shuffle();
int x,y,z,o,s=true,counter=0;
int arr[4][4]={{8,2,3,4},{5,6,7,1},{1,2,3,4},{5,6,7,8}};
int arr2[4][4];
int main()
{   cout<<"Welcome to our game"<<endl;
    screen();
    shuffle();
    cout<<endl<<"its shuffled now !! play "<< endl;
    screen2();
    loop();
}
void screen(){

    for(int i =0 ; i<4 ; i++){
        for(int j =0 ; j<4 ; j++){
            cout<<arr[i][j]<<"  ";}

        cout<<endl;}}

void screen2(){

    for(int i =0 ; i<4 ; i++){
        for(int j =0 ; j<4 ; j++){
            cout<<arr2[i][j]<<"  ";}

        cout<<endl;}}
void loop(){
    while (counter<16){
    cout <<"enter two row and colume"<<endl;
    cout <<"row 1 =";
    cin >> x;
    cout<<"colume 1 =";
    cin>>y;
     cout <<"row 2 =";
    cin >> z;
    cout<<"colume 2 =";
    cin>>o;
    if ( arr[x][y]==arr[z][o]){
        arr2[x][y]=arr[x][y];
        arr2[z][o]=arr[z][o];
        screen2();
    }
    else{  arr2[x][y]=arr[x][y];
           arr2[z][o]=arr[z][o];
            screen2();
            cout<<"\n\n\n\n";
           arr2[x][y]=0;
           arr2[z][o]=0;
           screen2();
}
int counter =0;
 for(int i =0 ; i<4 ; i++){
        for(int j =0 ; j<4 ; j++){
            if(arr2[i][j]>0){
                counter++;}
            }
}
 }
}
void shuffle(){
 random_shuffle(&arr[0][0], &arr[3][3]);
}
