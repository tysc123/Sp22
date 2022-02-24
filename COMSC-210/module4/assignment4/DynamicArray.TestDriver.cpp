    //Programmer: Tyler Schmalenbach
    //Programmer ID: 1482664

    #include <iostream>
    #include <cassert>
    #include <string>

    #include "DynamicArray.h"
    #include "DynamicArray.h" 

    using namespace std;



int main() {
    cout << "Programmer: Tyler Schmalenbach" << endl;
    cout << "Programmer ID: 1482664" << endl;
    cout << "File Name: " << __FILE__ << endl;
    
    //int
    DynamicArray<int> ia(100);
    cout << "\nTesting DynamicArray::capacity\n";
    cout << "EXPECTED:" << 100 << endl;
    cout << "ACTUAL: " << ia.capacity( ) << endl;
    assert(100 == ia.capacity( )); //if false program will crash

    if (100 == ia.capacity( ))
        cout << "Pass" << endl;

    cout << "\nTesting DynamicArray::DynamicArray\n";
    for (int i = 0; i < ia.capacity( ); i++)
     assert(ia[i] == 0);
    cout << "Pass" << endl;

    ia[1] = 12356;
    ia[2] = 7654321;
    cout << "\nTesting DynamicArray::operator[ ] setter\n";
    cout << "EXPECTED: 12356 for ia[1]" << endl;
    cout << "ACTUAL: " << ia[1] << endl;
    assert(12356 == ia[1]);

    cout << "EXPECTED: 7654321 for ia[2]" << endl;
    cout << "ACTUAL: " << ia[2] << endl;
    assert(7654321 == ia[2]);

    ia[-1000] = 123123;
    cout << "EXPECTED: 123123 for a[-1000]\n";
    cout << "ACTUAL: " << ia[-1000] << endl;
    assert(12356 == ia[1]);
    assert(7654321 == ia[2]);
    assert(123123 == ia[-6]); // out-of-range uses dummy
    assert(123123 == ia[100]); // upper end of range
    assert(123123 != ia[99]); // upper end of range
    assert(123123 != ia[0]); // lower end of range

    //double
    DynamicArray<double> da;
    cout << "\nTesting DynamicArray::DynamicArray -- double\n";
    for (int i = 0; i < da.capacity( ); i++)
     assert(da[i] == 0);
    cout << "Pass" << endl;

    da[1] = 123.56;
    da[2] = 765.4321;

    cout << "\nTesting DynamicArray::operator[ ] setter\n";
    cout << "EXPECTED: 12356 for da[1]" << endl;
    cout << "ACTUAL: " << da[1] << endl;
    assert(123.56 == da[1]);

    cout << "EXPECTED: 7654321 for da[2]" << endl;
    cout << "ACTUAL: " << da[2] << endl;
    assert(765.4321 == da[2]);

    da[-1000] = 123.123;
    cout << "EXPECTED: 123.123 for da[-1000]\n";
    cout << "ACTUAL: " << da[-1000] << endl;
    assert(123.56 == da[1]);
    assert(765.4321 == da[2]);
    assert(123.123 == da[-6]); // out-of-range uses dummy
    assert(123.123 == da[100]); // upper end of range
    assert(123.123 != da[99]); // upper end of range
    assert(123.123 != da[0]); // lower end of range

    //char
    DynamicArray<char> ca;
    cout << "\nTesting DynamicArray::DynamicArray -- double\n";
    for (int i = 0; i < ca.capacity( ); i++)
     assert(da[i] == 0);
    cout << "Pass" << endl;

    char a, b;
    ca[1] = a;
    ca[2] = b;

    cout << "\nTesting DynamicArray::operator[ ] setter\n";
    cout << "EXPECTED: a for ca[1]" << endl;
    cout << "ACTUAL: " << ca[1] << endl;
    assert(a == ca[1]);

    cout << "EXPECTED: b for ca[2]" << endl;
    cout << "ACTUAL: " << ca[2] << endl;
    assert(b == ca[2]);

    char c;
    ca[-1000] = c;
    cout << "EXPECTED: c for ca[-1000]\n";
    cout << "ACTUAL: " << ca[-1000] << endl;
    assert(c == ca[-1000]);

    //string
    DynamicArray<string> sa;
    cout << "\nTesting DynamicArray::DynamicArray -- double\n";
    for (int i = 0; i < sa.capacity( ); i++)
     assert(da[i] == 0);
    cout << "Pass" << endl;

    string a, b;
    sa[1] = a;
    sa[2] = b;

    cout << "\nTesting DynamicArray::operator[ ] setter\n";
    cout << "EXPECTED: a for sa[1]" << endl;
    cout << "ACTUAL: " << sa[1] << endl;
    assert(a == sa[1]);

    cout << "EXPECTED: b for sa[2]" << endl;
    cout << "ACTUAL: " << sa[2] << endl;
    assert(b == sa[2]);

    sa[-1000] = c;
    cout << "EXPECTED: c for sa[-1000]\n";
    cout << "ACTUAL: " << sa[-1000] << endl;
    assert(c == ca[-1000]);
    
    //copy test
    cout << "\nCopy Test\n";
    DynamicArray<int> f = ia; // making a copy, test copy constructor function
    assert(ia.capacity() == f.capacity()); 
    for (int i = 0; i < ia.capacity(); i++)
    assert(ia[i] == f[i]);     
    for (int i = 0; i < ia.capacity(); i++) {
        ia[i]++;
        assert(ia[i] != f[i]);
    }
    cout << "Done.";

    // object assignment test
    cout << "\nObject assignment test\n"; 
    DynamicArray<int>ie; ie = ia; 
    assert(ia.capacity() == ie.capacity()); 
    for (int i = 0; i < ia.capacity(); i++)
    assert(ia[i] == ie[i]);

    for (int i = 0; i < ia.capacity(); i++) {
        ia[i]++;
        assert(ia[i] !=ie[i]);
    }
    cout << "Done.";

    
    return 0;
    }

