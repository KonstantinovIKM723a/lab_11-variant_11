#include <iostream>;
#include "windows.h";
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //1. Ввести значення 2-х цілих змінних а і b. Направити два покажчика на ці змінні. Потім поміняти місцями значення змінних а і b через їх покажчики.

    int a, b;
    cout << "Введіть значення змінної a: ";
    cin >> a;
    cout << "Введіть значення змінної b: ";
    cin >> b;

    cout << "a = " << a << "; b = " << b << endl;

    int *pa = &a;
    int *pb = &b;

    a = *pa + *pb;
    b = *pa - *pb;
    a = *pa - *pb;

    cout << "a = " << a << "; b = " << b << endl << endl;

    //2. Описати 2 покажчика на логічний тип. Виділити для них динамічну пам'ять. Присвоїти значення true і false у виділену пам'ять. Поміняти місцями їх значення.

    bool *c = new bool;
    bool *d = new bool;

    *c = true;
    *d = false;

    cout << "*c = " << *c << "; *d = " << *d << endl;

    bool *e = c;

    c = d;
    d = e;

    cout << "*c = " << *c << "; *d = " << *d << endl << endl;

   // c = d;

    delete c;
    delete d;
    c = nullptr;
    d = nullptr;

    //3. Створити динамічні масиви, використовуючи покажчики. 
    //Дано 2 масиви х[n] і у[m]. Скільки разів зустрічається останній елемент першого масиву х[n] у другому масиві у[m]?

    int m, n, k = 0;
    cout << "Введіть довжину масива \"x\": ";
    cin >> n;
    cout << "Введіть довжину масива \"y\": ";
    cin >> m;

    int *x = new int[n];
    int *y = new int[m];

    srand(time(NULL));

    for (int i = 0; i < n; i++) x[i] = rand() % 19 - 9;
    for (int i = 0; i < m; i++) y[i] = rand() % 19 - 9;

    cout << endl << "Масив \"x\": ";
    for (int i = 0; i < n; i++) cout << x[i] << "\t"; 
    cout << endl << "Масив \"y\": ";
    for (int i = 0; i < m; i++) cout << y[i] << "\t";
    cout << endl;

    for (int i = 0; i < m; i++) {
        if (y[i] == x[n - 1]) k++;
    }

    cout << "Значення " << x[n - 1] << " (останній елемент в масиві \"x\"), зустрічається в масиві \"y\" " << k << " разів" << endl;
}