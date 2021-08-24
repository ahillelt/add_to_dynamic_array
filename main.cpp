#include <iostream>
using namespace std;

void add_to_array(int*& array, int& logical_size, int& physical_size, const int& val);

const int ARRAY_INCREASE = 2;

int main() {
    int logical_size, physical_size;
    int* dynamic_array = nullptr;
    
    logical_size = 0;
    physical_size = 1;
    
    dynamic_array =  new int [physical_size];

    add_to_array(dynamic_array,logical_size,physical_size,10);
    add_to_array(dynamic_array,logical_size,physical_size,16);
    add_to_array(dynamic_array,logical_size,physical_size,24);

    for (int i = 0; i < logical_size; i++){

        cout << dynamic_array[i] << endl;

    }

    cout << "logical size: " << logical_size << endl;
    cout << "physical size: " << physical_size << endl;


    delete [] dynamic_array;
    dynamic_array = nullptr;

    return 0;
}

void add_to_array(int*& array, int& logical_size, int& physical_size, const int& val){

    if(logical_size < physical_size){

        array[logical_size] = val;
        logical_size++;

    } else { //logical_size == physical_size

    int* new_array = new int[physical_size*ARRAY_INCREASE];

    for (int i = 0; i < logical_size; i++){

        new_array[i] = array[i];

    }

    new_array[logical_size] = val;

    logical_size++;
    physical_size *= ARRAY_INCREASE;

    delete [] array;
    array = new_array;
    }
}


