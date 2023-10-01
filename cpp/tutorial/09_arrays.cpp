#include <iostream>
#include <string>
using namespace std;

// access arrays
void ex00();

// change array element
void ex01();

// loop through an array
void ex02();

// loop through an array
void ex03();

// loop through an array
void ex04();

// foreach
void ex05();

// omit array size
void ex06();

// omit elements on declaration 
void ex07();

// get the size of an array
void ex08();

// loop through an array with sizeof
void ex09();

// Access the elements of a mult-dimensional array
void ex10();

// Change Elements in a Multi-Dimensional Array
void ex11();

// Loop through a multi-dimensional array
void ex12();

// Loop through a 3-dimensional array
void ex13();

// Battleships
void battleShip();

int main(){
    // access arrays
    // ex00();

    // change array element
    // ex01();

    // loop through an array
    // ex02();

    // loop through an array
    // ex03();

    // loop through an array
    // ex04();

    // foreach
    // ex05();

    // omit array size
    // ex06();

    // omit elements on declaration
    // ex07();

    // get the size of an array
    // ex08();

    // loop through an array with sizeof
    // ex09();

    // Access the elements of a mult-dimensional array
    // ex10();

    // Change Elements in a Multi-Dimensional Array
    // ex11();

    // Loop through a multi-dimensional array
    // ex12();

    // Loop through a 3-dimensional array
    // ex13();

    battleShip();
    return 0;
}

// access arrays
void ex00(){
    // assign a literal to a string array with 4 elements

    // syntax:
    // datatype array[number of elements] = r_value{}
    string cars[4] = {"Volvo", "Hyundai", "Toyota", "Mercedes"};

    // print the 1st element of the array
    cout << cars[0] << endl;
}

// change array element
void ex01(){
    // assign a literal to a string array with 4 elements
    string cars[4] = {"Volvo", "Hyundai", "Toyota", "Mercedes"};

    // change the 1st element of the array
    cars[0] = "Opel";

    // print the first element
    cout << cars[0] << endl;
}

// loop through an array
void ex02(){
    // assign a literal to a string array with 5 elements
    string cars[5] = {"Volvo",  "Hyundai", "Toyota", "Mercedes", "Tesla"};
    
    // loop through the array
    // if idx is less than 5 while increasing each time
    for(int idx = 0; idx < 5; idx++){
        // print the idx(th) of the the array
        cout << cars[idx] << endl;
    }
}

// loop through an array
void ex03(){
    // assign a literal to a string array with 5 elements
    string cars[5] = {"Volvo", "Hyundai", "Toyota", "Mercedes", "Tesla"};

    // loop through the array
    for(int idx = 0; idx < 5; idx++){
        // this time print the idx number and the array element
        cout << idx+1 << " = " << cars[idx] << endl;
    }
}

// loop through an array
void ex04(){
    // assign a literal to a integer array with 5 elements
    int numbers[5] = {10, 20, 30, 40, 50};

    // loop through the numbers array
    for(int idx = 0; idx < 5; idx++){
        // print the element
        cout << numbers[idx] << endl;
    }
}

// foreach
void ex05(){
    // assign a literal to a integer array with 5 elements
    int myNumbers[5] = {10, 20, 30, 40, 50};

    // for each element of myNumbers assign it to number
    for( int number : myNumbers){
        // print number
        cout << number << endl;
    }
}

// omit array size
void ex06(){
    // you can omit array size if using literal
    string cars[] = {"Volvo", "Hyundai", "Toyota", "Mercedes", "Tesla"};

    // for each element of cars assign it to brand
    for(string brand : cars){
        // print brand
        cout << brand << endl;
    }
}

// omit elements on declaration 
void ex07(){
    // you can omit the literal if you add the array size
    string cars[5];

    // assign each element like this:
    // array[index number] = r_value
    cars[0] = "Volvo";
}

// get the size of an array
void ex08(){
    // create an integer array
    int myNumbers[5] = {10, 20, 30, 40, 50};

    // sizeof returns in bytes instead of elements
    // integer = 4 byte
    // 4 * 5 = 20

    // print the number of bytes of myNumbers
    cout << sizeof(myNumbers) << endl;
}

// loop through an array with sizeof
void ex09(){
    // create an integer number
    int myNumbers[] = {10, 20, 30, 40, 50};

    // if number is less than 
    // myNumbers' number of bytes divided by the number of bytes of an integer
    // (20/ 4 = 5 gives you size of a array)
    for(int number = 0; number < sizeof(myNumbers)/sizeof(int); number++){
        // print nth element
        cout << myNumbers[number] << endl;
    }
}

// Access the elements of a mult-dimensional array
void ex10(){
    // two dimensional array with 2 rows and 4 columns
    string letters[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}
    };

    // print the element on the 1s row and 3rd column.
    cout << letters[0][2] << endl; 
}

// Change Elements in a Multi-Dimensional Array
void ex11(){
    // two dimensional array with 2 rows and 4 columns
    string letters[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}
    };

    // change the element on the 1st row and column to Z
    letters[0][0] = "Z";

    // print element on the 1st row and column
    cout << letters[0][0] << endl;
}

// Loop through a multi-dimensional array
void ex12(){
    // two dimensional array with 2 rows and 4 columns
    string letters[2][4] = {
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}
    };

    // loop through each dimension
    // loop the rows
    for(int idx = 0; idx < 2; idx++){
        // loop the columns
        for(int jdx = 0; jdx < 4; jdx++){
            // print the element on the idxth row and jdxth column
            cout << letters[idx][jdx] << endl;
        }
    }
}

// Loop through a 3-dimensional array
void ex13(){
    // create an array with
    // 2 tables
    // 2 rows
    // 2 columns
    string letters[2][2][2] = {
        {
            {"A", "B"},
            {"C", "D"}
        },
        {
            {"E", "F"},
            {"G", "H"}
        }
    };

    // loop through each dimension
    // loop the tables
    for(int idx = 0; idx < 2; idx++) {
        // loop the rows
        for(int jdx = 0; jdx < 2; jdx++) {
            // loop the rows
            for(int kdx = 0; kdx < 2; kdx++){
                // print the element of the idxth table 
                // the jdxth row
                // and the kdxth column
                cout << letters[idx][jdx][kdx] << endl;
            }
        }
    }
}

// Battleships
void battleShip(){
    // put "1" to indicate ship
    // 4 by 4 arr of ships
    bool ships[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };

    // number of hits a player has
    int hits = 0;
    // number of turns player has played
    int noOfTurns = 0;

    // Allow player to keep player until hit all 4 ships
    while(hits < 4){
        // variables for row and column (coordinates)
        int row;
        int col;

        // get input for coordinates
        cout << "Input coordinates:" << endl;
        cout << "Input Row (number between 1 and 4): ";
        cin >> row;
        row--;

        cout << "Input Col (number between 1 and 4): ";
        cin >> col;
        col--;

        // If ship exist in user coordinates
        if(ships[row][col]){
            // remove ship
            ships[row][col] = 0;

            // increase the hit counter
            hits++;

            // print Hit and amount of ships left
            cout << "HIT!" << endl;
            cout << "Amount of ships left : " << (4-hits) << endl;
        } else{
            // Print miss
            cout << "MISS!" << endl;
        }

        // increase number of turns
        noOfTurns++;
    }
    // print Victory
    cout << "Victory!" << endl;

    // print number of turns took
    cout << "Number of turns taken to complete the mission : " << noOfTurns << endl;
}