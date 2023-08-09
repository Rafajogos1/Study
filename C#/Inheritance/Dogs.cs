///These classes specify dog breeds///
//Daschsund//
class Daschsund : Dog
{
	public string animaltype { get; set; } = "Dog";
	public string dogtype { get; set; } = "Daschsund";
}

//Golden Retriever//
class GoldenRetriever : Dog
{
	public string animaltype { get; set; } = "Dog";
	public string dogtype { get; set; } = "Golden Retriever";
}

//Husky//
class Husky : Dog
{
	public string animaltype { get; set; } = "Dog";
	public string dogtype { get; set; } = "Husky";
	public override void Speak(string sound)
	{
		base.Speak(sound);
	}
}