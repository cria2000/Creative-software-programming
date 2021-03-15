
public interface Dictionary {
	public boolean isEmpty();
	void insertEntry(String word, String definition) throws AlreadyExistsInDicException;
	void getDefinition(String word) throws EmptyException, NotInDicException;;
	void removeWord(String word) throws EmptyException, NotInDicException;
	void printWords()throws EmptyException;
	void printAll() throws EmptyException;
}