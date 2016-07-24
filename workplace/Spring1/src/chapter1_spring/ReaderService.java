/**
 * 
 */
package chapter1_spring;

/**
 * @author vedsar
 *
 */
public class ReaderService {
	private Reader reader = null;
	public ReaderService(Reader reader) {
		this.reader = reader;
	}
	String read() {
		return reader.read();
	}
}
