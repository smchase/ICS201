/*#include <iostream>
#include <fstream>
#include <array>

#define SIZE 9

using namespace std;

struct node {
    struct node *left;
    struct node *right;
    struct node *up;
    struct node *down;
    struct header *header;
    array<int, 2> pos;
    int num;
};

struct header {
    struct node *left;
    struct node *right;
    struct node *up;
    struct node *down;
    int quantity;
};

struct column {
    header h;
    array<node, SIZE*SIZE*SIZE> n;
};

int main ()
{
    fstream file("problem.txt");
    char output;
    array<array<int, SIZE>, SIZE> problem;
    int i = 0;
    while (file.get(output)) {
        problem[i/SIZE][i%SIZE] = output-48;
        if (output != '\n') i ++;
        cout << output;
    }

    column arr[SIZE*SIZE*4];
    //array<array<column, SIZE*SIZE>, 4> matrix;
}*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <stdbool.h>

#define MAX_ROW 50L
#define MAX_COL 100L

using namespace std;

struct str_node {
    struct str_node * Header;
    struct str_node * Left;
    struct str_node * Right;
    struct str_node * Up;
    struct str_node * Down;
    int HeaderID,RowIndex,ColIndex;
};


int nCol;
int nRow;
struct str_node Matrix[MAX_ROW][MAX_COL];
vector<struct str_node*>ResultRow;
struct str_node Root;
struct str_node *RootNode = &Root;
bool Data[MAX_ROW][MAX_COL];
int maxResult;

//functions to get the neighbours (are circular)
inline int dataLeft(int i) { return (i-1 < 0) ? nCol-1 : i-1 ; }
inline int dataRight(int i) { return (i+1) % nCol ; }
inline int dataUp(int i) { return (i-1 < 0) ? nRow-1 : i-1 ; }
inline int dataDown(int i) { return (i+1) % nRow ; }

void CreateToroidalMatrix(void) {

    int a,b, i, j;

    for(a = 0 ; a <= nRow ; a++) {

        for(b=0 ; b < nCol ; b++) {

            if(Data[a][b]) {

                Matrix[a][b].RowIndex = a;
                Matrix[a][b].ColIndex = b;

                // Left pointer
                i = a; j = b; do {j = dataLeft(j); } while (!Data[i][j]);
                Matrix[a][b].Left = &Matrix[i][j];

                // Right pointer
                i = a; j = b; do {j = dataRight(j); } while (!Data[i][j]);
                Matrix[a][b].Right = &Matrix[i][j];

                // Up pointer
                i = a; j = b; do {i = dataUp(i); } while (!Data[i][j]);
                Matrix[a][b].Up = &Matrix[i][j];

                // Down pointer
                i = a; j = b; do {i = dataDown(i); } while (!Data[i][j]);
                Matrix[a][b].Down = &Matrix[i][j];

                //Head pointer
                Matrix[a][b].Header = &Matrix[0][b];
                Matrix[a][b].HeaderID = b+1;

            }
        }
    }

    //Initialize root
    RootNode->Right = &Matrix[0][0];
    RootNode->Left = &Matrix[0][nCol-1];
    Matrix[0][0].Left = RootNode;
    Matrix[0][nCol-1].Right = RootNode;
}

void Cover(struct str_node *ColNode){

    cout<<"Covering header node "<<ColNode->HeaderID<<'\n';

    struct str_node *RowNode, *RightNode;

    ColNode->Right->Left = ColNode->Left;
    ColNode->Left->Right = ColNode->Right;

    for(RowNode = ColNode->Down ; RowNode!=ColNode ; RowNode = RowNode->Down) {
        for(RightNode = RowNode->Right ; RightNode!=RowNode ; RightNode = RightNode->Right) {
            RightNode->Up->Down = RightNode->Down;
            RightNode->Down->Up = RightNode->Up;
        }
    }
}

void UnCover(struct str_node *ColNode) {
    //uncover the covered nodes to find a different solution
    struct str_node *RowNode, *LeftNode;

    for(RowNode = ColNode->Up; RowNode!=ColNode; RowNode = RowNode->Up) {
        for(LeftNode = RowNode->Left; LeftNode!=RowNode; LeftNode = LeftNode->Left) {
            LeftNode->Up->Down = LeftNode;
            LeftNode->Down->Up = LeftNode;
        }
    }
    ColNode->Right->Left = ColNode;
    ColNode->Left->Right = ColNode;
}

void Search(int k){

    //all columns covered

    if( RootNode->Right == RootNode){
        cout<<"found\n";
        if(maxResult < k)
            maxResult = k;
        return;
    }

    //if not covered
    else{

        struct str_node *Column = RootNode->Right;
        struct str_node *RowNode;
        struct str_node *RightNode;
        struct str_node *LeftNode;

        Cover(Column);

        for( RowNode = Column->Down ; RowNode!=Column ; RowNode = RowNode->Down){

            ResultRow.push_back(RowNode);

            for(RightNode = RowNode->Right; RightNode!=RowNode; RightNode = RightNode->Right)
                Cover(RightNode->Header);

            Search(k+1);
            RowNode = ResultRow.back();
            ResultRow.pop_back();
            Column = RowNode->Header;

            for(LeftNode = RowNode->Left; LeftNode!=RowNode; LeftNode = LeftNode->Left)
                UnCover(LeftNode->Header);
        }
        UnCover(Column);
    }
}

void GetData(void){
    int pos,k;
    scanf("%d%d",&nCol, &nRow);

    nRow++;//this is the change

    for(int i=0 ; i<nCol ; i++)
        Data[0][i] = true;

    for(int i=1 ; i<nRow ; i++){
        scanf("%d",&k);
        for(int j=0 ; j<k ; j++){
            scanf("%d",&pos);
            Data[i][pos-1] = true;
        }
    }
    CreateToroidalMatrix();
}

int main(void){
    GetData();
    Search(0); // from level 0
    printf("%d\n",maxResult+1);
    return 0;
}
