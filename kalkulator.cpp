#include<iostream>
class Calculator {
public:
	Calculator() //constructor without parameters
	{
		memory = 0;
	}
	Calculator(int startValue) //constructor wit parameters
	{
		memory = startValue;
	}

	int calculator(char operation, int value) {
		int result = 0;
		if (operation == '+') {
			memory += value;
		}
		else if (operation == '-')
			memory -= value;
		else if (operation == '*')
			memory *= value;
		else if (operation == '/') {
			// CANNOT DIVIDE BY 0
			if (value == 0)
			{
				std::cout << "You cannot divide by 0, I`m sorry(" << std::endl;
				return memory;
			}
			memory /= value;
		}
		return memory;
	}
	void setStartValue(int value)
	{
		memory = value;
	}
private:
	int memory = 0;
};

int main() {
	Calculator calc1 = 10;
	int result = calc1.calculator('-', 5);
	std::cout << "Result 10 - 5: " << result << std::endl;

	calc1.setStartValue(5);
	std::cout << "Started Value: 5 " << std::endl;

	int result_1 = calc1.calculator('+', 5);
	std::cout << "First operation and value: +, 5 - " << result_1 << " In memory: " << result_1 << std::endl;

	int result_2 = calc1.calculator('*', 2);
	std::cout << "Second operation and value: *, 2 - " << result_2 << " In memory: " << result_2 << std::endl;

	int result_3 = calc1.calculator('-', 11);
	std::cout << "Third value and operation: -, 11 - " << result_3 << " In memory: " << result_3 << std::endl;

	int result_4 = calc1.calculator('/', 3);
	std::cout << "Fourth value and operation: /, 3 - " << result_4 << " In memory: " << result_4 << std::endl;
}