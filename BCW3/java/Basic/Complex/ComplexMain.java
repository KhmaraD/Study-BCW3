public class ComplexMain {
    public static void main(String[] args) throws CloneNotSupportedException {
        Complex a = new Complex(2, 7);
        Complex b = new Complex(6, 8);
        Complex c = b.clone();
        Complex d = new Complex();
        
        System.out.println("a:" + a);
        System.out.println("b:" + b);
        System.out.println("c:" + c);
        System.out.println("d:" + d);
        
        if ( a.equals(b) ) {
            System.out.println("a:" + a + " equals b:" + b);
        } else {
            System.out.println("a:" + a + " not equals b:" + b);
        }
        
        System.out.println("sum(a, b):" + a.sum(b));
        System.out.println("diff(a, b): " + a.diff(b));
        System.out.println("product(a, b): " + a.product(b));
        
    }
}
