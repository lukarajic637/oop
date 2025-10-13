#include <iostream>
#include <iomanip>
int main()
{
bool flag;
std::cout << "unesi " << true << " - " << false << std::endl;
std::cin >> flag;
std::cout << std::noboolalpha << flag << std::ends;
int a = 255;
std::cout << "hex " << std::hex << a << std::endl;
std::cout << "dec " << std::dec << a << std::endl;
std::cout << "oct " << std::oct << a << std::endl;
double pi = 3.141592;
std::cout << "pi = " << std::fixed << std::uppercase;
std::cout << std::setprecision(7) << std::setw(10);
std::cout << std::setbase('0');
std::cout << pi << std::endl;
}

