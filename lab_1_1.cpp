#include <stdio.h>
#include <string.h>
#include <iostream>


using namespace std;

// функция печати  размера типа данных 
template<typename T>
void print_size(std::string type_name)
{
    std::cout << type_name <<": " << sizeof(T) << std::endl;
}


// фуекция заполнения массива 
template<typename T, typename Types>
void add_number(Types Arg, T *arr) {

   // T arr[5];

    for (int i=0; i<5; i++) {
        arr[i]=Arg;
    }

    
}


// функция вывода массива любого типа
template<typename T>
void print_arr(const char* type, T *arr){
    
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

printf("\n");
printf("-------end l1.3-----\n");
printf("\n");
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
    
    // int32_t x2 = 0xC0CAC01A;
    // int64_t x3= 0xC0FFEE11BEA7;


// – 𝑀𝑠 из 16-битных целых чисел (𝑥 = 0xDEAD)
    uint16_t arr_x1[5];
    uint16_t x1 = 0xDEAD;
    add_number<uint16_t, uint16_t>(x1, arr_x1);
    print_arr<uint16_t>("hu", arr_x1);
    printf("------end 16-------\n");

// 𝑀𝑙 из 32-битных целых чисел (𝑥 = 0x C0CA C01A)
    
    int32_t x2 = 0xC0CAC01A;
    uint32_t arr_x2[5];
    add_number<uint32_t, uint32_t>(x2, arr_x2);
    print_arr<uint32_t>("u", arr_x2);
    printf("-------end 32--------\n");

// 𝑀𝑞 из 64-битных целых чисел (𝑥 = 0x C0FF EE11 BEA7)  

    int64_t x3 = 0xC0FFEE11BEA7;
    uint64_t arr_x3[5];
    add_number<uint64_t, uint64_t>(x3, arr_x3);
    print_arr<uint64_t>("llu", arr_x3);
    printf("-------end 64--------\n");

// 𝑀𝑓𝑠 из 32-битных чисел с плавающей запятой (𝑥 из таблицы Л1.1);
    
    float x4 = -10 / (float)3;
    float arr_x4[5];
    add_number<float, float>(x4, arr_x4);
    print_arr<float>(".8f", arr_x4);
    printf("-------end float--------\n");

// 𝑀𝑓𝑙 из 64-битных чисел с плавающей запятой (𝑥 из таблицы Л1.1).

    double x5 = -10 / (double)3;
    double arr_x5[5];
    add_number<double, double>(x5, arr_x5);
    print_arr<double>(".16lf", arr_x5);
    printf("-------end double--------\n");    

    printf("\n");
    printf("-------end l1.4-----\n");
    printf("\n");

    /*
    Задание Л1.з5. 
    Для каждого массива 𝑀 введите с клавиатуры новое значение элемента 𝑀[𝑖], 𝑖 = 2 при помощи функции libc 𝑠𝑐𝑎𝑛𝑓().
     Проанализировав возвращённое 𝑠𝑐𝑎𝑛𝑓() значение, определите корректность ввода; при необходимости отобразите 
     сообщение об ошибке при помощи функции libc 𝑝𝑢𝑡𝑠(). Выведите массивы на экран снова, убедитесь, что элемент 𝑀[𝑖] 
     приобрёл ожидаемое значение, а другие элементы массива не изменились. 

    */

   printf("Zamena elementa \n");
   int test_scanf=scanf("%hu", &arr_x1[2]);
   if (test_scanf==0){
    puts("Error scanf");
   }
   else {
    print_arr<uint16_t>("hu", arr_x1);
    printf("------ end 16 ---------\n");
   }

    int test_scanf_1=scanf("%u", &arr_x2[2]);
    if (test_scanf_1==0){
        puts("Error scanf");
        }
        else {
    print_arr<uint32_t>("u", arr_x2);
    printf("------ end 32 ---------\n");
   }

   int test_scanf_2=scanf("%llu", &arr_x3[2]);
   if (test_scanf_2==0){
    puts("Error scanf");
    }
    else {
        print_arr<uint64_t>("llu", arr_x3);
        printf("------ end 64 ---------\n");
        }

   int test_scanf_3=scanf("%lf", &arr_x5[2]);
   if (test_scanf_3==0){
    puts("Error scanf");
    }
    else {
        print_arr<double>(".16lf", arr_x5);
        printf("------ end double ---------\n");
        }

    printf("\n");
    printf("-------end l1.5-----\n");
    printf("\n");



   /*
   Задание Л1.з6.
   Если используется язык C++, выполните задания Л1.з4 и Л1.з5 также для массива 𝑀 𝑏 из 𝑁 8-битных целых чисел (0xED).
   
   */
  
   printf("Zamena elementa lab 1.6\n");

   unsigned char x6=0xED;
   unsigned char arr_6[5];

   add_number<unsigned char, unsigned char>(x6, arr_6);
   print_arr<unsigned char>("d", arr_6);

   int test_scanf_6=scanf("%hhu", &arr_6[2]);
   if (test_scanf_6==0){
    puts("Error scanf");
   }
   else {
    print_arr<unsigned char>("d", arr_6);
   }
   printf("\n");
   printf("-------end l1.6-----\n");
   printf("\n");printf("---------------\n");


   /*
   Задание Л1.з7.
   Для одного из массивов 𝑀 (вариант Ms) введите с клавиатуры новое значение всех пяти элементов при помощи 
   одного вызова функции libc 𝑠𝑐𝑎𝑛𝑓(). Проанализировав возвращённое 𝑠𝑐𝑎𝑛𝑓() значение, определите корректность ввода; 
   при необходимости отобразите сообщение о количестве не заданных элементов. Выведите массив на экран снова.

   */

  printf("Zamena vseh elementov \n");


  int test_scanf_7=scanf("%hu%hu%hu%hu%hu",  &arr_x1[0], &arr_x1[1],&arr_x1[2], &arr_x1[3], &arr_x1[4]);

   if (test_scanf_7 !=5){
    puts("Error scanf");
    printf("missing elements, you need %d more", 5-test_scanf_7);
   }
   else{
    printf("---------------\n");
    print_arr<uint16_t>("d", arr_x1);
     
   }

   printf("\n");
   printf("-------end l1.7-----\n");
   printf("\n");


/*
Задание Л1.з8. 
Введите с клавиатуры при помощи функций libc: 
а) слово (строку без пробелов) 𝑠1; 
б) слово 𝑠2 таким образом, чтобы принимающий его буфер гарантированно не переполнился 
(если буфер длины 𝑘 — вводить не более 𝑘 − 1 символов, при необходимости добавляя завершающий нулевой символ); 
в) строку, возможно, содержащую пробелы 𝑠3. 

*/

printf("Vvedite stroku s1\n");

char s1[32];

scanf("%s", s1);

printf("%s\n", s1);

printf("Vvedite stroku s2\n");
char s2[32];
scanf("%31s", s2);
s2[31]=0;
printf("%s\n", s2);

printf("Vvedite stroku s3\n");
char s3[32];
scanf("%[^$]s", s3);
s3[31]=0;
printf("%s\n", s3);

printf("\n");
printf("-------end l1.8-----\n");
printf("\n");printf("---------------\n");




















   
    

   

    return 0;
}
