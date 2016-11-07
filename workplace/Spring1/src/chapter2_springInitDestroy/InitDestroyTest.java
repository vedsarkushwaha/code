/**
 * 
 */
package chapter2_springInitDestroy;

/**
 * @author vedsar
 *
 */
public class InitDestroyTest {
	
	String cons = null;
	String settergetter = null;
	String initi = null;
	String dest = null;

	public InitDestroyTest() {
	}
	
	public InitDestroyTest(String a) {
		this.cons = a;
	}
	
	/**
	 * @return the a
	 */
	public String getA() {
		return settergetter;
	}
	/**
	 * @param a the a to set
	 */
	public void setA(String a) {
		this.settergetter = a;
	}
		
	public static void init_method() {
		String initi = "Setting initi from init_method";
	}
	
	public void destroy_method() {
		this.dest = "Setting dest from destroy_method";
	}
}