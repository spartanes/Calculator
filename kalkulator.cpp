#include<iostream>
class Calculator {
public:
	Calculator() { memory = 0; }//constructor without parameters
	Calculator(int startValue) { memory = startValue; }//constructor with parameters

	int getCurrentValue() const { return memory };
	void setStartValue(int value)
	{
		memory = value;
	}
	//operators overloading
	Calculator& operator+(int value) 
	{
		return *this += value;
	}
	Calculator& operator-(int value)
	{
		return *this -= value;
	}
	Calculator& operator*(int value)
	{
		return *this *= value;
	}
	Calculator& operator/(int value)
	{
		return *this /= value;
	}
	Calculator& operator+=(int value)
	{
		memory += value;
		return *this;
	}
	Calculator& operator-=(int value)
	{
		memory -= value;
		return *this;
	}
	Calculator& operator*=(int value)
	{
		memory *= value;
		return *this;
	}
	Calculator& operator/=(int value)
	{
		if (value == 0)
		{
			std::cout << "You cannot divide by 0, I`m sorry(" << std::endl;
			return *this;
		}
		memory /= value;
		return *this;
	}
private:
	int memory = 0;
};

int main() {
	Calculator obj(10);
	std::cout << "Started value: " << obj.getCurrentValue() << std::endl;

	obj + 5 * 10;
	std::cout << "Result obj + 5 * 10 = " << obj.getCurrentValue() << std::endl;

	obj.setStartValue(10);
	(obj + 5) * 10;
	std::cout << "Result (obj + 5) * 10 = " << obj.getCurrentValue() << std::endl;

	obj.setStartValue(100);
	obj /= 10;
	std::cout << "Result obj /= 10 = " << obj.getCurrentValue() << std::endl;
}