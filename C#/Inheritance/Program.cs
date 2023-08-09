using System;

//This class is the main onw, which defines the basic date of an animal//
class Animal
{
	public string name { get; set; } = "";
	public int Age { get; set; } = 0;
	public virtual void Speak(string sound)
	{
		Console.WriteLine("The animal makes a sound, which is {0}.\n", sound);
	}
}

class Inheritance
{
	static void Main(string[] args)
	{
		Dog Leão = new Dog();
		Daschsund Tim = new Daschsund();
		GoldenRetriever Nugget = new GoldenRetriever();
		Husky Snow = new Husky();
		Bengal Jay = new Bengal();
		Leão.name = "Leão";
		Leão.Age = 20;
		Leão.IsFriendly = true;
		Tim.name = "Tim";
		Tim.Age = 5;
		Tim.IsFriendly = true;
		Nugget.name = "Nugget";
		Nugget.Age = 3;
		Nugget.IsFriendly = true;
		Snow.name = "Snow";
		Snow.Age = 9;
		Snow.IsFriendly = true;
		Jay.name = "Jay";
		Jay.Age = 7;
		Jay.IsFriendly = false;
		Console.WriteLine("Name: {0}\nAge: {1}\nIs friendly?: {2}\nThe best boy.", Leão.name, Leão.Age, Leão.IsFriendly);
		Leão.Speak("barking");
		Console.WriteLine("Name: {0}\nAge: {1}\nIs friendly?: {2}\nIt's a {3} and a {4}.", Tim.name, Tim.Age, Tim.IsFriendly, Tim.animaltype, Tim.dogtype);
		Tim.Speak("barking");
		Console.WriteLine("Name: {0}\nAge: {1}\nIs friendly?: {2}\nIt's a {3} and a {4}.", Nugget.name, Nugget.Age, Nugget.IsFriendly, Nugget.animaltype, Nugget.dogtype);
		Nugget.Speak("barking");
		Console.WriteLine("Name: {0}\nAge: {1}\nIs friendly?: {2}\nIt's a {3} and a {4}.", Snow.name, Snow.Age, Snow.IsFriendly, Snow.animaltype, Snow.dogtype);
		Snow.Speak("howling");
		Console.WriteLine("Name: {0}\nAge: {1}\nIs friendly?: {2}\nIt's a {3} and a {4}.", Jay.name, Jay.Age, Jay.IsFriendly, Jay.animaltype, Jay.cattype);
		Jay.Speak("meowing");
	}
}