# GP34
1.introduction of the game:
______________________________
Nonogram consist of a table, contain black and white dot. Each row and column have a set of numbers, for example “1 2” represents there are 2 parts that are black, first one only ocupies 1 spaces, and the second one ocupies two spaces.

The task is to fill the spaces such that it fulfill the requirements of rows and columns, for example. In the table ,”4” is fullfill by 4-consecutive1 “11110”, and “1 1”is fullfill by “10100”.
2. the program:
_______________________
The program consist of numerous parts.

The convertToString() funtion generate the requirements of rows and coloumn from char array
    =================
The save() fuction save the correct answer and the current attempt by player to two file,
    =====
anwer.txt and try.txt

The read fuction help recover the less saved session from anwer.txt and try.txt
    ====
Init 2d array ()help generate dynamic array with specfic size
     ===========
Insert_into2d array() help correct individual spaces
=====================
Getrandom () will generate a new game set with conntaining random individual spaces
============
MyFunc () help print the arr of correct answer
---------
Row collum () will show the rows and collums requiremments as well as the current attempt
-------------
Printinst() will print the instruction for nonogram game from instruction.txt
------------
Printeachattempt () will print what players can do
--------------------
Get row()/get column() will generate the sets of number for each rows and column 
-----------------------
according to the 2d array, then the array the consist of the generated rows or collumns can be compareby the function check() to examine whether the players is correct

3.Work flow of the game:
___________________________
./main will show the title and the game instruction

Then we may choose to resume the game or not

If press (n) for new game, it will generate a new sets of rule, and all spaces to 0 represent not been filled.

We may press “i” if we would like to view the instructions again
If we press v to swith the spaces,the program will ask which row and which column
e.g we answer 0 row and 4 column

Arr[0][4]will swith accordingly between “1” and “0”.
We mignt press s and q to save and quit our game progress.

Then the answer.txt will save the correct answers and try.txt will save the input by users

If we run the cpp again and press (y) to resume the last saved session


We will see the last-modified game will correct spaces and sets of number.

Assume now the input exatly match the sets of requirements, if we press c to check the answer

It will show true and congraduation

Now we resume the game to recover the correct answer input by users and change the answers by input v, row:0 ,column:0

If we then check the answer,it will shows false,try again

CODING REQIREMENTS:
___________________________
1. Generation of random game sets or events
___________________________________________________
void getrandonm(int size,int** arr){
    srand (time(NULL));
    int a = rand() % 2;
    for(int i = 0; i<size;i++){
            for(int in = 0; in<size ; in++){
                a = rand() % 2;
                if(a<1){
                    Insert_into_2D_Array(arr, i,in,size,0 ); 
                }
                else{
                    Insert_into_2D_Array(arr, i,in,size,1 ); 
                }
            }
    }
    
}
________________________________________________________________

Get random() will generate random number(either 1, or 0) By rand()%2
_______________________________________________
2. Data structures for storing game status
+______________________________________________
Two txt file (answer.txt)(try.txt) for storing concurrent game status(the 2D-array)
____________________________________________________
3. Dynamic memory management
___________________________________________________
3.a
void Init_2D_Array(int*** arr, int x)
{

  *arr = new int*[x]; 
3.b
void save(int** arr,string filename){
_____________________________________
use dynamic array to store the arr into file.txt
3.c
void read(int** arr,string filename){
_________________________________
use dynamic array to input the arr from file.txt
3.d
void Init_2D_Array(int*** arr, int x)
{

  *arr = new int*[x]; 
  for (int i=0;i<x;i++)
  {
      (*arr)[i] = new int[x];
  }
________________________________
use dynamic arr to init the content of game
3.e
void Insert_into_2D_Array(int** arr, int x, int y, int size,int value)
{
  if (x < size && y < size) {
    arr[x][y] = value;
  }
}
_________________________________________________
change value with out using return by daynamic array
3.f
void getrandonm(int size,int** arr){
}
_______________________________________
assign random variable to arr directly by dynamic array
3.g
void MyFunc(int** arr,int size) {}
__________________________________
use dynamic array to print the correct answer's arr
3.h
 int** arr=NULL;
 ______________________
 initialise the game content with dynamic array
3.i
void rowcollum(int** arr,int size,int** attempt){}
_________________________________
cout the arr content with dynamic array
3.j
string * getcolumn(int size,int** arr ) {

    string* c = new string[5];
...
}
__________________________________________________________
to calculate the "list of space numbers of columns and row " through dynaic array
3.k
bool check(int** arr,int size,int** attempt){}
_______________________________________________
check whether two dynaic array match each others

4.File input/output:
_________________________
void save(int** arr,string filename){

  ofstream out(filename);
    if (! out) {
        cout << "cantopenfile" << endl; 
        
    }    
    for(int r = 0; r < 5; r++) {  
        for(int c = 0; c < 5; c++){
            out<<arr[r][c]<<" ";
        }
        out << "\n";
    }
    out.close();
}

void read(int** arr,string filename){
    ifstream op(filename);
    if (! op) {
        cout << "cantopenfile" << endl; 

    }    
    for(int row = 0; row < 5; row++) {  // stop loops if nothing to read
        for(int column = 0; column < 5; column++){
            op >>arr[row][column];
            if ( ! op ) {
                cout << "cantopenfile "; 

            }
        }
    }
    op.close();
    for(int i=0; i<5; i++){
        for(int in=0; in<5; in++){
            cout << arr[i][in] << " ";
        }
        cout<<endl;
    }
}
______________________
5.Proper indentation and naming styles:

Init_2D_Array(&arr, x); represent creating the array

getrandonm(x,arr); represent getting random correct answers

read(arr,"answer.txt"); arr refer to the model answers 2d array

read(attempt,"try.txt"); attemt refer to the inputs anwers by players

printinst("instruction.txt"); it will print the intructions
___________________________________________________________
6.In-code documentation:
// stop loop 
//print(3)
//cout <<"false"
