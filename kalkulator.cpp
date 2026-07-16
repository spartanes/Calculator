#include<iostream>
class Calculator {
public:
	Calculator() //constructor without parameters
	{
		memory = 0;
	}
	Calculator(int startValue) //constructor with parameters
	{
		memory = startValue;
	}
	static int calculate(const int& value_1,const int& value_2, const char& operation)//static method
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

	Calculator& calculate(const int& value, const char& operation) 
	{
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
		return *this;
	}
	
	int getCurrentValue() const { return memory };
	
	void setStartValue(int value)
	{
		memory = value;
	}
private:
	int memory = 0;
};

int main() {
	
	int result = Calculator::calculate(10, 5, '-');
	std::cout << "Result 10 - 5: " << result << std::endl;

	Calculator my_calc(2);

	int result_1 = my_calc.calculate(5, '+').calculate(4, '-').calculate(3, '*').getCurrentValue();
	std::cout << "Operation and value: +, 5 - " << result_1 << std::endl;
}