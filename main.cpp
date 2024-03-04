#include <iostream>

#include "Sum_array.h"

int main() {
	setlocale(LC_ALL, "Rus");
	int n = 100000;
	int m = 4;

	SumArray sum_array(n, m);
	sum_array.Run();

	int result = sum_array.GetResult();

	std::cout << "Сумма элементов массива: " << result << std::endl;

	return 0;
}
