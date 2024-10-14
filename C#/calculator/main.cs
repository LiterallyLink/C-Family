using System;

namespace Calculator
{
    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                try
                {
                    double num1 = GetNumberInput("Enter the first number:");
                    double num2 = GetNumberInput("Enter the second number:");
                    char operation = GetOperationInput();

                    double result = PerformOperation(num1, num2, operation);
                    Console.WriteLine($"The result is: {result}");
                }
                catch (Exception ex)
                {
                    Console.WriteLine($"An error occurred: {ex.Message}");
                }

                if (!ContinueCalculation())
                {
                    break;
                }
            }
        }

        static double GetNumberInput(string prompt)
        {
            while (true)
            {
                Console.WriteLine(prompt);
                if (double.TryParse(Console.ReadLine(), out double number))
                {
                    return number;
                }
                Console.WriteLine("Invalid input. Please enter a valid number.");
            }
        }

        static char GetOperationInput()
        {
            while (true)
            {
                Console.WriteLine("Enter the operation (+, -, *, /):");
                char operation = Console.ReadKey().KeyChar;
                Console.WriteLine();

                if ("+-*/".Contains(operation))
                {
                    return operation;
                }
                Console.WriteLine("Invalid operation. Please enter +, -, *, or /.");
            }
        }

        static double PerformOperation(double a, double b, char operation)
        {
            return operation switch
            {
                '+' => a + b,
                '-' => a - b,
                '*' => a * b,
                '/' => Divide(a, b),
                _ => throw new InvalidOperationException("Invalid operation")
            };
        }

        static double Divide(double a, double b)
        {
            if (b == 0)
            {
                throw new DivideByZeroException("Cannot divide by zero");
            }
            return a / b;
        }

        static bool ContinueCalculation()
        {
            Console.WriteLine("Do you want to perform another calculation? (y/n)");
            return Console.ReadKey().KeyChar.ToString().ToLower() == "y";
        }
    }
}