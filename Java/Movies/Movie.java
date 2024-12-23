/* This calss holds details of a movie and operations to access and modify its data. */
public class Movie 
{
	private String	title;
	private String	genre;
	private String	rating;

	/* An the getter of the class. */
	public Movie(String title, String genre, String rating)
	{
		this.title = title;
		this.genre = genre;
		this.rating = rating;
	}

	/* The getter for "title". */
	public String getTitle()
	{
		return title;
	}

	/* The setter for "title". */
	public void setTitle(String title)
	{
		this.title = title;
	}

	/* The getter for "genre". */
	public String getGenre()
	{
		return genre;
	}

	/* The setter for "genre". */
	public void setGenre(String genre)
	{
		this.genre = genre;
	}

	/* The getter for "rating". */
	public String getRating()
	{
		return rating;
	}

	/* The setter for "rating". */
	public void setRating(String rating)
	{
		this.rating = rating;
	}
}
