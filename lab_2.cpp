#include <stdio.h>
#include <string.h>
#include <iostream>
#include <bitset>
#include <limits.h>
#include <limits>
#include <iomanip>


using namespace std;


void viewPointer(void * p)
{
    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);
    
    cout << endl <<"Pointer p "<< std::hex << p << endl;
    cout << endl << "Pointer p+1 " << (p+1) << endl;

    cout << endl << "char p1 " << std::hex << (void *)p1 << endl;
    cout << endl << "char p1+1 " << std::hex << (void *)(p1+1) << endl;

    cout << endl << "unsigned short p2 " <<std::hex << p2 << endl;
    cout << endl << "unsigned short p2+1 " <<std::hex << (p2+1) << endl;

    
    cout << endl<< "double " << std::hex << p3 << endl;
    cout << endl<< "double p3 + 1 " << std::hex << (p3+1) << endl;
    
    cout << endl << "----------end 2.1-----------"<< endl;
}

/*


*/

void printPointer(void * p) {
    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);
    int *p4 = reinterpret_cast<int *>(p);
    long *p5 = reinterpret_cast<long *>(p);
    long long *p6 = reinterpret_cast<long long *>(p);

   // cout << endl << *p << endl;
    cout << endl <<"char: " << hex <<*p1 << endl;
    cout << endl <<"char +1: " << hex <<*(p1+1) << endl;

    cout << endl << "unsigned short: "<< hex <<*p2 << endl;
     cout << endl << "unsigned short + 1: "<< hex <<*(p2+1) << endl;

    cout << endl<< "double: "<< *p3 << endl;
    cout << endl<< "double + 1: "<< *(p3+1) << endl;

    cout << endl << "int: "<< hex <<*p4 << endl;
    cout << endl << "int + 1: "<< hex <<*(p4+1) << endl;

    cout << endl << "long: "<< hex <<*p5 << endl;
    cout << endl << "long + 1: "<< hex <<*(p5+1) << endl;

    cout << endl << "long long: "<< hex <<*p6 << endl;
    cout << endl << "long long +1: "<< hex <<*(p6+1) << endl;

    cout << endl << "-----------end 2.2-----------"<< endl;

}


void print16(void * p) {
    unsigned short *p1 = reinterpret_cast<unsigned short  *>(p);
    short *p2 = reinterpret_cast<short  *>(p);


    cout << endl <<"UHex: " << hex <<*p1 << endl;
    cout << endl <<"UBin: " << bitset<16> (*p1)  << endl;
    cout << endl <<"UDec: " << dec <<*p1 << endl;
    cout << endl <<"Hex: " << hex <<*p2 << endl;
    cout << endl <<"Bin: " << bitset<16> (*p2)  << endl;
    cout << endl <<"Dec: " << dec <<*p2 << endl;
    cout << endl << "------------end 2.3------------"<< endl;

}


void print32(void * p) {
    unsigned int *p1 = reinterpret_cast<unsigned int  *>(p);
    int *p2 = reinterpret_cast<int  *>(p);
    float *p3 = reinterpret_cast<float  *>(p);


    cout << endl <<"UHex: " << hex <<*p1 << endl;
    cout << endl <<"UBin: " << bitset<32> (*p1)  << endl;
    cout << endl <<"UDec: " << dec <<*p1 << endl;

    cout << endl <<"Hex: " << hex <<*p2 << endl;
    cout << endl <<"Bin: " << bitset<32> (*p2)  << endl;
    cout << endl <<"Dec: " << dec <<*p2 << endl;

    const auto digits = std::numeric_limits<double>::digits10;
    std::cout << std::setfill(' ') << std::setw(digits + 4);
    std::cout << std::fixed << std::setprecision(digits) << *p3 << std::endl;   
    cout<<"Exponential: "<<scientific<<*p3<<endl;




    cout << endl << "------------end 2.4 32------------"<< endl;

}

void print64(void * p) {
    unsigned long long *p1 = reinterpret_cast<unsigned long long  *>(p);
    long long *p2 = reinterpret_cast<long long  *>(p);
    double *p3 = reinterpret_cast<double  *>(p);


    cout << endl <<"UHex: " << hex <<*p1 << endl;
    cout << endl <<"UBin: " << bitset<64> (*p1)  << endl;
    cout << endl <<"UDec: " << dec <<*p1 << endl;

    cout << endl <<"Hex: " << hex <<*p2 << endl;
    cout << endl <<"Bin: " << bitset<64> (*p2)  << endl;
    cout << endl <<"Dec: " << dec <<*p2 << endl;

    const auto digits = std::numeric_limits<double>::digits10;
    std::cout << std::setfill(' ') << std::setw(digits + 4);
    std::cout << std::fixed << std::setprecision(digits) << *p3 << std::endl;   
    cout<<"Exponential: "<<scientific<<*p3<<endl;




    cout << endl << "------------end 2.4 64------------"<< endl;

}



void printDump(void * p, size_t N ){
    unsigned char *p1=reinterpret_cast<unsigned char  *>(p);
    unsigned short p2=*p1;

    for (int i=0; i<N; i++) {
    unsigned short p2=*(p1+i);
    cout << hex << p2;}

    cout << endl << "------------end 2.5------------"<< endl;

}


int main(){


/* Задание Л2.з1. Разработайте функцию void 𝑣𝑖𝑒𝑤𝑃 𝑜𝑖𝑛𝑡𝑒𝑟(void * 𝑝), которая
принимает нетипизированный указатель 𝑝, преобразует его в типизированные: */


double p1=10;

viewPointer(&p1);

/*
Ответ на вопрос:
Тип char и форма void * занимают в памяти 1 байт, поэтому смещение pi+1 произвотся на 1 байт
Тип unsigned short занимает 2 байта и смещение производится на 2 байта
Тип double занимает 8 байт и смещение p3+1  на 8 байт
*/


/*
Задание Л2.з2. Разработайте функцию void 𝑝𝑟𝑖𝑛𝑡𝑃 𝑜𝑖𝑛𝑡𝑒𝑟(void *𝑝), которая
принимает нетипизированный указатель 𝑝, преобразует его в типизированные
𝑝1, 𝑝2, 𝑝3 аналогично 𝑣𝑖𝑒𝑤𝑃 𝑜𝑖𝑛𝑡𝑒𝑟() и печатает значения различных типов по
адресу 𝑝: *𝑝1, *𝑝2, *𝑝3. Можно ли рассчитать (и, соответственно, напечатать) *𝑝?
*/

char p2=13;

printPointer(&p2);

/*
Ответ на вопрос о выводе *p:

Арифметика указателя всегда зависит от размера объекта, на который указывает указатель. 
Но void имеет неизвестный размер, поэтому арифметика с указателями void* не разрешена стандартом. 
*/

long long p3=0x8877665544332211;
printPointer(&p3);

char p4[]="abcdefgh0123456789";
printPointer(&p4);


/*
Задание Л2.з3. Изучите, как интерпретируется одна и та же область памяти,
если она рассматривается как знаковое или беззнаковое целое число, а также —
как одно и то же число записывается в различных системах счисления.
*/

// минимальное целое 16-битное значение без знака;
unsigned short p5=0;
print16(&p5);

// максимальное целое 16-битное значение без знака

unsigned short p6=USHRT_MAX;
print16(&p6);

// минимальное целое 16-битное значение со знаком

short p7=SHRT_MIN;
print16(&p7);

// максимальное целое 16-битное значение со знаком;

short p8=SHRT_MAX;
print16(&p8);

// значение 𝑦, соответствующее варианту (таблица Л2.1)

short y = 5;
print16(&y);

// значение 𝑧, соответствующее варианту (таблица Л2.1)

short z=-5;
print16(&z);




/*
Задание Л2.з4. Разработайте на языке C/C++ функции 𝑝𝑟𝑖𝑛𝑡32() и 𝑝𝑟𝑖𝑛𝑡64(),
аналогичные 𝑝𝑟𝑖𝑛𝑡16() для размеров 32 и 64 бита, и дополните их интер-
претацией памяти как числа с плавающей запятой («вещественного» чис-
ла) соответствующего размера (для 32 бит — с одинарной точностью, 𝑓 𝑙𝑜𝑎𝑡;
для 64 — с двойной точностью, 𝑑𝑜𝑢𝑏𝑙𝑒).
*/

// минимальное целое значение без знака соответствующего размера;

unsigned int p9=0;
print32(&p9);
print64(&p9);

//максимальное целое значение без знака соответствующего размера;

unsigned int p10=UINT_MAX;
print32(&p10);
print64(&p10);

// минимальное целое значение со знаком соответствующего размера;

int p11=INT_MAX;
print32(&p11);
print64(&p11);


// максимальное целое значение со знаком соответствующего размера;

int p12=INT_MAX;
print32(&p12);
print64(&p12);


// значение 𝑥, соответствующее варианту

int x1=0x99887766;
print32(&x1);
print64(&x1);

// значение 𝑦, соответствующее варианту;

int y1=5;
print32(&y1);
print64(&y1);

// значение 𝑧, соответствующее варианту

int z1=5;
print32(&z1);
print64(&z1);


/*
Задание Л2.з5. Изучите, как располагаются в памяти байты, составляющие
целое число и число с плавающей запятой. Для этого на языке C/C++ разработайте
функцию void 𝑝𝑟𝑖𝑛𝑡𝐷𝑢𝑚𝑝(void * 𝑝, size_t 𝑁 ), которая печатает для области
памяти по заданному адресу 𝑝 значения 𝑁 байтов, начиная с младшего, в шестна-
дцатеричном представлении (шестнадцатеричный дамп памяти).

*/

/*
целое число 𝑥 (типа 𝑖𝑛𝑡; таблица Л2.1); по результату исследования опреде-
лите порядок следования байтов в словах для вашего процессора:
*/ 


int x = 0x99887766;
int N=sizeof(x);

printDump(&x,N);

/* При выполнении функции printDump() вывод в консоль 66778899, т.е. младший байт по младшему адресу, 
 следовательно у меня прямой порядок следования байтов */ 


// массив из трёх целых чисел 

int b[3]{ 1, 2, 3};
int N1=sizeof(b);
printDump(&b,N1);


/*
Задание Л2.з6. Выполните измерения согласно заданию Л1.з3 (sizeof типов)
на платформах, доступных на ВЦ (таблица Л2.2).
*/

/*
Очевидно ВЦ это какое-то место где находится много компиляторов. К сожалению, я не знаю где это.
У меня есть gcc на платформе win11 64, попробую запустить там
*/ 




/* доделать*/


return 0;

}

