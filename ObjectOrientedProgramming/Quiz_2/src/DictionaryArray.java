import java.util.ArrayList;
public class DictionaryArray implements Dictionary{
	private ArrayList<WordDefinitionPair> DicList;
	public boolean isEmpty() {
		if(DicList.isEmpty())
			return true;
		return false;
	}
	public void insertEntry(String word,String definition) throws AlreadyExistsInDicException {
		WordDefinitionPair wdp=new WordDefinitionPair(word,definition);
		if (DicList.contains(wdp)) {
			throw new AlreadyExistsInDicException();
		}
		else {
			WordDefinitionPair wdp2=new WordDefinitionPair(word,definition);
			DicList.add(wdp2);
		}
	}
	public void getDefinition(String word) throws NotInDicException, EmptyException{
		if(DicList.isEmpty())
			throw new EmptyException();
		else {
			for(int i=0;i<DicList.size();i++) {
				if(DicList.get(i).getWord().equals(word)) {
					System.out.println(DicList.get(i).getWord()+ " : "+DicList.get(i).getDefinition());
					break;	
				}
				else
					throw new NotInDicException();
			}
		}
	}
	public void removeWord(String word) throws EmptyException,NotInDicException {
		if(DicList.isEmpty())
			throw new EmptyException();
		else {
			for(int i=0;i<DicList.size();i++) {
		
				if(DicList.get(i).getWord().equals(word)){
					DicList.remove(i);
					break;				}
				else 
					throw new NotInDicException();
			}
		}
	}
	public void printWords() throws EmptyException{
		int num=1;
		if(DicList.isEmpty())
			throw new EmptyException();
		else {
			for(WordDefinitionPair wdp:DicList) {
				System.out.print(num+". ");
				System.out.println(wdp.getWord());
				++num;			
				}
		}
	}
	public void printAll() throws EmptyException{
		if(DicList.isEmpty())
			throw new EmptyException();
		else {
			for(WordDefinitionPair wdp:DicList) {
				System.out.println("**************************************");
				System.out.println("Word : "+wdp.getWord()+"\nDefinition : " +wdp.getDefinition());
		}}
	}
	DictionaryArray(){
		DicList=new ArrayList<WordDefinitionPair>();
	}
	public ArrayList<WordDefinitionPair> getDicList() {
		return DicList;
	}	
}
