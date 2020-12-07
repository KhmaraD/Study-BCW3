public class DateMain {
    public static void main(String[] args) throws InvalidDateException {
        Date date1 = new Date();
        Date date2 = new Date(3, 5, 2019);
        
        System.out.println(date1);
        System.out.println(date2);
    }
}
