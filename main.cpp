#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int Q[8]{0};
    int c = 0;
    int solnum = 0;

    NC:
    c++;
    if(c==8) goto Print; //End of board.
    Q[c] = -1;
    NR:
    Q[c]++; // increasing rows
    if(Q[c]==8) goto Backtrack; // cannot place a Queen in any row

    for (int i=0; i<c;i++){
        if(Q[c]==Q[i] || (c-i) == abs(Q[c]-Q[i])) goto NR;
    }
    goto NC;

    /*Print the result*/
    Print:
    solnum++;
    cout << "Solution Number: #" << solnum << "#" << endl;

    //1D Array representation
    cout << "Array Representation" << endl;
    for (int a : Q) cout << a;
    cout << endl;

    //8x8 board representation
    cout << "Board Representation: " << endl;
    for (int r=0; r<8; r++){
        for (int c=0;c<8;c++){
            if (Q[r]==c){
                cout << " Q ";
            }else{
                cout <<" _ ";
            }
        }
        cout << endl;
    }
    cout << endl;

    Backtrack: /* go back one column */
    c--;
    if(c==-1) {
        cout << "There are total of " << solnum << " solutions";
        return 0; // run out of column, all solutions found.
    }
    goto NR; // put the Queen in next row in the same column.
}
