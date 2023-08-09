using System;

class Sum
{
	static void Main(string[] args)
	{
		if (args.Length == 2)
		{
			int.TryParse(args[0], out int num1);
			int.TryParse(args[1], out int num2);
			Console.WriteLine("{0} + {1} = {2}", num1, num2, (num1 + num2));
		}
		else
			Console.WriteLine("To use this program pass it two nubmers.");
	}
}