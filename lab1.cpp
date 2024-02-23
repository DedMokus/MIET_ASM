#include <stdio.h>

#define printType(type) printf("%s is %d byte long\n", #type, (int)sizeof(type))
#define ZapMass(mass, mm) for (int i = 0;i<5;i++) {mass[i]= mm;}
#define printMass(mass, m, format, type) printf("Mass of %s\n", #type); for (int i = 0;i<5;i++) {mass[i]=m; printf("%d\t", mass[i]); printf(format, mass[i]); printf("sizeof %d\n", sizeof(type));}
#define printMassFloat(mass, m, format, type) printf("Mass of %s\n", #type); for (int i = 0;i<5;i++) {mass[i]=m; printf(format, mass[i]); printf("sizeof %d\n", sizeof(type));}

#define printM(mass) printf("\n"); for (int i = 0;i<5;i++) {printf("%d\t", mass[i]);} printf("\n");
#define printMf(mass) printf("\n"); for (int i = 0;i<5;i++) {printf("%f\t", mass[i]);} printf("\n");

void task1(){
    printf("Task 1\n");
    puts("Group 2");
    puts("Lebedev Pavel and Igor Arefyev");
}

void task2(){
    printf("Task 2\n");
    puts("OC - Windows x64");
    puts("Compiler - MinGW gcc");
    puts("AMD64");

    printType(char);
    printType(signed char);
    printType(unsigned char);
    printType(char*);
    printType(bool);
    printType(wchar_t);
    printType(short);
    printType(int);
    printType(long);
    printType(long long);
    printType(float);
    printType(double);
    printType(long double);
    printType(size_t);
    //printType(ptrdiff_t);
    printType(void*);

}

void task4(){
    printf("Task 4\n");
    const int n = 5;
    unsigned short Ms[n];
    printMass(Ms,0xFADE, "%04X\t", unsigned short);

    int Ml[n];
    printMass(Ml, 0xADE1A1DA, "%08X\t", int);

    long long Mq[n];
    printMass(Mq, 0xC1A551F1AB1E, "%016llX\t", long long);

    float mm = (float)-8/5;
    float Mfs[n];
    printMassFloat(Mfs, mm, "%.2f\t", float);

    double mmm = (double)-8/5;
    double Mfl[n];
    printMassFloat(Mfl, mmm, "%.2lf\t", double);
}

void task5(){
    printf("Task 5\n");
    int Ml[5];
    ZapMass(Ml,0xADE1A1DA );
    printf("Start - %p\n", Ml);
    printf("First element - %p\n", &(Ml[0]));
    printf("Second element - %p\n", &(Ml[1]));
}

void task6(){
    printf("Task 6\n");
    const int n = 5;
    unsigned short Ms[n];
    ZapMass(Ms,0xFADE);

    int Ml[n];
    ZapMass(Ml,23);

    long long Mq[n];
    ZapMass(Mq,255);

    float mm = (float)1.6;
    float Mfs[n];
    ZapMass(Mfs,mm);

    double mmm = (double)1.6;
    double Mfl[n];
    ZapMass(Mfl,mmm);

    printf("Before\t");
    printM(Ms);
    if (scanf("%hd", &Ms[2])!=1){
        printf("Read error");
    }
    else{
        printf("After\t");
        printM(Ms);
    }

    printf("Before\t");
    printM(Ml);
    if (scanf("%d", &Ml[2])!=1){
        printf("Read error");
    }
    else{
        printf("After\t");
        printM(Ml);
    }
    
    printf("Before\t");
    printM(Mq);
    if (scanf("%ld", &Mq[2])!=1){
        printf("Read error");
    }
    else{
        printf("After\t");
        printM(Mq);
    }
    
    printf("Before\t");
    printMf(Mfs);
    if (scanf("%f", &Mfs[2])!=1){
        printf("Read error");
    }
    else{
        printf("After\t");
        printMf(Mfs);
    }
    
    printf("Before\t");
    printMf(Mfl);
    if (scanf("%f", &Mfl[2])!=1){
        printf("Read error");
    }
    else{
        printf("After\t");
        printMf(Mfl);
    }
}

void task8(){
    printf("Task 8\n");
    int Ml[5];
    ZapMass(Ml,434 );

    printf("Before\t");
    printM(Ml);

    if (int n = scanf("%d %d %d %d %d", &(Ml[0]), &(Ml[1]), &(Ml[2]), &(Ml[3]), &(Ml[4]))!=5){
        printf("Read error! Not Read %d\n", 5-n);
        printf("After\t");
        printM(Ml);
    }
    else{
        printf("Read access!\n");
        printf("After\t");
        printM(Ml);
    }
}

void task9(){
    printf("Task 9\n");

    const int k = 10;
    char s1[1000];
    char s2[k];
    char s3[1000];

    scanf("%s",s1);
    char format[10];
    snprintf(format, sizeof(format), "%%%ds", k-1);
    
    scanf(format,s2);
    printf("Input s3\n");
    scanf("%[^\n]", s3);

    printf("***%s***\n", s1);
    printf("***%s***\n", s2);
    printf("***%s***\n", s3);
    
}

int main(){
    //task1();
    //task2();
    //task4();
    //task5();
    //task6();
    //task8();
    task9();
}