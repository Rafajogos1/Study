import java.util.ArrayList;

/* This class is responsible to do operations on the movie list. It is an utility calss and is not supposed to have instances. */
public class MovieManager {
	private static ArrayList<Movie> movieList = new ArrayList<Movie>();

	/* Throws an exception if it is attempted to create an instance of this class. */
	private MovieManager()
	{
		throw new UnsupportedOperationException("This is a utility class and cannot be instantiated");
	}

	/* Adds a movie to the list. */
	public static void addMovie(Movie movie)
	{
		movieList.add(movie);
	}

	/* Check if the movie list is empty. */
	public static boolean checkEmpty()
	{
		if (movieList.isEmpty() == true)
			return true;
		else
			return false;
	}

	/* Returns how many elemetns are present in the movie list. */
	public static int listSize()
	{
		return (movieList.size());
	}

	/* Get info of the movie at index "pos" .*/
	public static void getInfo(int i)
	{
		System.out.println("Movie: " + movieList.get(i).getTitle());
		System.out.println("Genre: " + movieList.get(i).getGenre());
		System.out.println("Rating: " + movieList.get(i).getRating());
		System.out.println();
	}

	/* Checks if the there is a movie named "movie" at the index "i". */
	public static boolean movieExists(String movie, int i)
	{
		if (movieList.get(i).getTitle().equals(movie))
			return true;
		else
			return false;
	}

	/* Deletes the movie at the index "i". */
	public static void deleteMovie(int i)
	{
		movieList.remove(i);
	}
}
