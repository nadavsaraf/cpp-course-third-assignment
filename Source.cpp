#include <iostream>
#include <cmath>
using namespace std;

// task 1 functions

// this function checks if the number is a prime number
bool isprime(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			return false;
		}
	}
	return true;
}
int nearest_prime(int n)
{
	if (n == 0)
	{
		return 2;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (isprime(n))
	{
		return n;
	}
	int aboveN = -1;
	int belowN = -1;
	int num1;
	num1 = n + 1;
	while (true)
	{
		if (isprime(num1))
		{
			aboveN = num1;
			break;
		}
		else
		{
			num1++;
		}
	}
	num1 = n - 1;
	while (true)
	{
		if (isprime(num1))
		{
			belowN = num1;
			break;
		}
		else
		{
			num1--;
		}
	}
	int dist1 = aboveN - n;
	int dist2 = n - belowN;
	if (dist1 == dist2)
	{
		return belowN;
	}
	if (dist1 > dist2)
	{
		return belowN;
	}
	else
	{
		return aboveN;
	}

}

// task 2 functions

int GCD(int num1, int num2)
{
	int min_num; // the smallest number between the two numbers
	min_num = min(num1, num2);
	for (int i = min_num - 1; i > 1; i--)
	{
		if (num1 % i == 0 && num2 % i == 0)
		{
			return i;
		}
	}
}

// task 3 functions

// this function the value of the x in the tylor series
int powerx(int x)
{
	int series = 1;
	for (int i = 1; i <= x; i++)
	{
		series = series * i;
	}
	return series;
}
void Tylor(int x, int m)
{
	double sum = 0;
	cout << "e^" << x << "=";
	for (int i = 0; i < m; i++)
	{
		sum = sum + pow(x, i) / powerx(i);
		cout << pow(x, i) << "/" << powerx(i) << " + ";
	}
	cout << " = " << sum;
}

// task 4 functions

bool perfect(int n)
{
	int sum = 0; // calculates the sum of the dividers
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			sum = sum + i;
		}
	}
	if (sum == n)
	{
		return true;
	}
	else
	{
		return false;
	}
}


int main()
{
	// this program present the menu of the task, the program reads the user's selection and
	// sends it to the selected task

	int task_number; // the number of task that the user select
	cout << "menu: \n";
	cout << "\n";
	cout << "0. exit \n";
	cout << "1. for nearest prime \n";
	cout << "2. for GCD  \n";
	cout << "3. for Tylor series \n";
	cout << "4. for test if number is perfect \n";
	cout << "please select the number of task you want to check \n";
	cin >> task_number;

	while (task_number != 0)
	{
		switch (task_number)
		{

		case 1:


			// This program recevies a natural number, the program will print the prime number
			// that is the closest to the natural number

			int num; // the natural number
			cout << "please enter a number \n";
			cin >> num;
			cout << "the nearest prime number is:" << endl;
			cout << nearest_prime(num) << endl;

			break;

		case 2:


			// this program recevies two natural numbers, the program will print
			// their largest common dividing number

			int num1, num2; // the two natural numbers
			cout << "please enter the first number \n";
			cin >> num1;
			cout << "please enter the second number \n";
			cin >> num2;
			cout << "the GCD number is: \n";
			cout << GCD(num1, num2) << endl;

			break;

		case 3:

			// this program present the tylor series with two random numbers

			int x; // the value of the x in the series
			int m; // the value of the m in the series
			cout << "please enter the x value" << endl;
			cin >> x;
			cout << "please enter the m value" << endl;
			cin >> m;
			Tylor(x, m);
			cout << "\n";


			break;

		case 4:

			// this program recevies a natural number, the program checks if the sum of all its divisors
			// are equal to the natural number 

			int num4; // the natural number
			cout << "please enter a number \n";
			cin >> num4;
			cout << "is this a perfect number?" << endl;
			if (perfect(num4))
			{
				cout << "true" << endl;
			}
			else
			{
				cout << "false" << endl;
			}

			break;

		}
		cout << "menu: \n";
		cout << "\n";
		cout << "0. exit \n";
		cout << "1. for nearest prime \n";
		cout << "2. for GCD  \n";
		cout << "3. for Tylor series \n";
		cout << "4. for test if number is perfect \n";
		cout << "please select the number of task you want to check \n";
		cin >> task_number;
	}
	cout << "thank you and goodbye";

	return 0;
}
