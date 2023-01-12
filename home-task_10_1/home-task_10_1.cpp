#include <iostream>
#include <iomanip>
using namespace std;

const int col = 2, row = 3;
int n, step, choice, arr[row][col]{}, arr2[row][4]{};

//Задание 1
void task1();
//Задание 2
void task2();
//Задание 3;
void showArr();
void menu();
void stepArrRight(int arr2[][4], int row, int col, int step);
void stepArrLeft(int arr2[][4], int row, int col, int step);
void stepArrDown(int arr2[][4], int row, int col, int step);
void stepArrUp(int arr2[][4], int row, int col, int step);
void showArr2();

int main() {

	setlocale(LC_ALL, "");
	//Задание 1
	//Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу:
	//пользователь вводит число(например, 3) первый элемент
	//массива принимает значение этого числа, последующий элемент массива принимает значение этого числа
	//умноженного на 2 (т.е. 6 для нашего примера), третий
	//элемент массива предыдущий элемент умноженный на
	//2 (т.е. 6 * 2 = 12 для нашего примера).Созданный массив
	//вывести на экран.
	task1();

	//Задание 2
	//Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу :
	//пользователь вводит число(например, 3) первый элемент
	//массива принимает значение этого числа, последующий
	//элемент массива принимает значение этого числа + 1 (т.е.
	//4 для нашего примера), третий элемент массива предыдущий элемент + 1 (т.е. 5 для нашего примера).Созданный
	//массив вывести на экран.
	task2();

	//Задание 3;
	//Создайте двухмерный массив.Заполните его
	//случайными числами и покажите на экран.Пользователь
	//выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).
	//Выполнить сдвиг массива и показать на
	//экран полученный результат.Сдвиг циклический.
	showArr();
	menu();
	showArr2();
}
void task1() {
	cout << "Home task #10.1.1\n\n";
	cout << "Введите 1 элемент\n";
	cin >> n;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = n;
			n *= 2;
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << string(30, '-') << endl;
}
void task2() {
	cout << "Home task #10.1.2\n\n";
	cout << "Введите 1 элемент\n";
	cin >> n;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			arr[i][j] = n;
			n++;
			cout << setw(3) << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << string(30,'-')<<endl;
}
void showArr() {
	cout << "Home task #10.1.3\n\n";
	srand(time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 4; j++) {
			arr2[i][j] = rand() % 20;
			cout << setw(3) << arr2[i][j] << " ";
		}
		cout << endl;
	}
}
void showArr2() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < 4; j++) {
			cout << setw(3) << arr2[i][j] << " ";
		}
		cout << endl;
	}
}
void menu() {
	cout << "Выберете кол-во сдвигов: ";
	cin >> step;
	cout << "Выберете направление сдвига:\n"
		<< "Влево-1\n"
		<< "Вправо-2\n"
		<< "Вниз-3\n"
		<< "Вверх-4\n";
	cin >> choice;
	switch (choice) {
	case 1:
		stepArrLeft(arr2, row, 4, step);
		break;
	case 2:
		stepArrRight(arr2, row, 4, step);
		break;
	case 3:
		stepArrDown(arr2, row, 4, step);
		break;
	case 4:
		stepArrUp(arr2, row, 4, step);
		break;
	default:
		cout << "Неверный ввод!\n";
		break;
	}
}
void stepArrRight(int arr2[][4], int row, int col1, int step) {
	if (step > 0) {
		for (int i = 0; i < row; i++) {
			int temp = arr2[i][col1 - 1];
			for (int j = col1 - 1; j > 0; j--) {
				arr2[i][j] = arr2[i][j - 1];
			}
			arr2[i][0] = temp;
		}
		stepArrRight(arr2, row, col1, --step);
	}
}
void stepArrLeft(int arr2[][4], int row, int col, int step) {
	if (step > 0) {
		for (int i = 0; i < row; i++) {
			int temp = arr2[i][0];
			for (int j = 0; j < col; j++) {
				arr2[i][j] = arr2[i][j + 1];
			}
			arr2[i][col - 1] = temp;
		}
		stepArrLeft(arr2, row, col, --step);
	}
}
void stepArrDown(int arr[][4], int row, int col, int step) {
	if (step > 0) {
		for (int j = 0; j < col; j++) {
			int temp = arr[row - 1][j];
			for (int i = row - 1; i > 0; i--) {
				arr[i][j] = arr[i - 1][j];
			}
			arr[0][j] = temp;
		}
		stepArrDown(arr, row, col, --step);
	}
}
void stepArrUp(int arr[][4], int row, int col, int step) {
	if (step > 0) {
		for (int j = 0; j < col; j++) {
			int temp = arr[0][j];
			for (int i = 0; i < row - 1; i++) {
				arr[i][j] = arr[i + 1][j];
			}
			arr[row - 1][j] = temp;
		}
		stepArrUp(arr, row, col, --step);
	}
}