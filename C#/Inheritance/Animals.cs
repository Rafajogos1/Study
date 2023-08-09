/// These classes specify animal types///
///IsFriendly starts as "false" do to the likelyhood of wild animals being weary of other species//
//Cat//
class Cat : Animal
{
	public bool IsFriendly { get; set; } = false;
	public override void Speak(string sound)
	{
		base.Speak(sound);
	}
}

//Dog//
class Dog : Animal
{
	public bool IsFriendly { get; set; } = false;
	public override void Speak(string sound)
	{
		base.Speak(sound);
	}
}