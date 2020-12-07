public class CarMain {
    public static void main(String[] args) throws OutOfFuelException, ToMuchFuelException {
        Car car = new Car();

        System.out.println(car);
        
        car.refill(60);

        car.drive(new Point(3, 8));

        System.out.println(car);

        car.drive(new Point(1, 5));

        System.out.println(car);
    }
}
