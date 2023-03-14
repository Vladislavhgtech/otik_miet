#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <cstddef>
#include <string>
#include <iomanip>

using namespace std;


template<typename T>
void print_size(std::string type_name)
{
    std::cout << type_name <<": " << sizeof(T) << std::endl;
}



template<typename T, typename Types>
void print_number(std::string type_name, Types Arg, char* type) {

    T arr[5];

    for (int i=0; i<5; i++) {
        arr[i]=Arg;
    }

    char* format = new char[strlen(type) + 4];
    strcpy(&format[1], type);
    format[0] = '%';

    for(int i=0; i < 5; i++){
        printf(format, arr[i]);
        printf("\n");
    }
}

int main()

{
    /*
Задание Л1.з3. При помощи оператора sizeof языка С/С++ выясните,
сколько байтов занимают переменные следующих типов языка С/С++: void*,
char, signed char, unsigned char, char*, wchar_t, wchar_t*, short,
unsigned short, short*, int, unsigned int, int*, long, unsigned
long, long long, unsigned long long, float, double, long double,
double*, size_t, ptrdiff_t.

*/

print_size<char>("char");
print_size<bool>("bool");
print_size<wchar_t>("wchar_t");
print_size<short>("short");
print_size<int>("int");
print_size<long>("long");
print_size<long long>("long long");
print_size<float>("float");
print_size<double>("double");
print_size<long double>("long double");
print_size<size_t>("size_t");
print_size<ptrdiff_t>("ptrdiff_t");
print_size<void*>("void*");

    /*
Задание Л1.з4. Разработайте программу на языке C/C++, создающую, инициализирующую одинаковыми значениями 𝑥
и выводящую на экран при помощи
функции libc 𝑝𝑟𝑖𝑛𝑡𝑓() массивы из 𝑁 = 5 чисел:
– 𝑀𝑠 из 16-битных целых чисел (𝑥 = 0xDEAD)
– 𝑀𝑙 из 32-битных целых чисел (𝑥 = 0x C0CA C01A)
– 𝑀𝑞 из 64-битных целых чисел (𝑥 = 0x C0FF EE11 BEA7)
– 𝑀𝑓𝑠 из 32-битных чисел с плавающей запятой (𝑥 из таблицы Л1.1);
– 𝑀𝑓𝑙 из 64-битных чисел с плавающей запятой (𝑥 из таблицы Л1.1).

*/
    uint16_t x1 = 0xDEAD;
    int32_t x2 = 0xC0CAC01A;
    int64_t x3= 0xC0FFEE11BEA7;

    print_number<uint16_t, uint16_t>("uint16_t", x1, "hu");
    print_number<int32_t, int32_t >("int32_t ", x2, "u");
    print_number<int64_t, int64_t >("int64_t ", x3, "llu");


    float x5 = -10 / (float)3;
    double x6 = -10 / (double)3;
    print_number<float, float>("float", x5, ".6f");
    print_number<double, double>("double", x6, ".6f");

    return 0;
}
