#include <iostream>
#include <cstring>

using namespace std;

char nibble_to_hex(uint8_t i){
    switch (i) {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    }
}

void print_byte(uint8_t y){
    uint8_t low = ( y & 0b00001111 );
    uint8_t high = ( y & 0b11110000 ) >>4;
    cout<<nibble_to_hex(high)<<nibble_to_hex(low);
}

void print_in_hex(const void* data, size_t size){
    auto k = reinterpret_cast<const uint8_t*>(data);
    for (size_t i = 0; i < size; i++ ){
        print_byte(*(k+i));
        cout<<';';
    }
}

struct Student{
    char Name[17];
    uint16_t Year;
    double Middlemark;
    bool Sex;
    int Course;
    Student* Prefect;
};

int
main() {
    uint8_t z = 106;
    print_byte(z);
    cout<<'\n';

    int l = 694536462;
    print_in_hex(&l, sizeof(l));

    Student s[3];
    strcpy(s[0].Name, "Olga");
    s[0].Year = 2016;
    s[0].Middlemark = 4.4;
    s[0].Sex = 0;
    s[0].Course = 1;
    s[0].Prefect = nullptr;
    strcpy(s[1].Name, "Anna");
    s[1].Year = 2016;
    s[1].Middlemark = 3.8;
    s[1].Sex = 0;
    s[1].Course = 1;
    s[1].Prefect = &s[0];
    strcpy(s[2].Name, "Serega");
    s[2].Year = 2016;
    s[2].Middlemark = 0.4;
    s[2].Sex = 1;
    s[2].Course = 1;
    s[2].Prefect = &s[0];

    cout<<"\naddress m: "<<&s<<"\nsize m:"<<sizeof(s)<<"\naddress 1:"<<&s[0]<<"\nsize 1:"
            <<sizeof(s[0])<<"\naddress 2:"<<&s[1]<<"\nsize 2:"
            <<sizeof(s[1])<<"\naddress 3:"<<&s[2]<<"\nsize 4:"
            <<sizeof(s[2])<<"\ni:";
    print_in_hex(&s[0], sizeof(s[0]));


    char path[64], message[48];
    const char* greeting = "Enter path";
    fgets ( path, sizeof(path), stdin );
    char * strchr( const char * greeting, int *,  <, >, ?  |);
    strcpy ( message, greeting );
    strcat( message, ",");
    strcat( message, path );
    strcat( message, "!");
    puts ( message );

    return 0;


}