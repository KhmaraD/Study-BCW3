public class Car {
    private double fuelAmount;
    private double fuelCapacity;
    private double fuelConsumption;
    private Point location;
    private String model;
    
    public Car(double capacity, double consumption, Point location, String model) {
        this.fuelAmount = 0;
        this.fuelCapacity = capacity;
        this.fuelConsumption = consumption;
        this.location = location;
        this.model = model;
    }
    
    public Car() {
        this(60, 0.6, new Point(0, 0), "Mercedes");
    }
    
    public double getFuelAmount() {
        return fuelAmount;
    }
    
    public double getFuelCapacity() {
        return fuelCapacity;
    }
    
    public double getFuelConsumption() {
        return fuelConsumption;
    }
    
    public Point getLocation() {
        return location;
    }
    
    public String getModel() {
        return model;
    }
    
    public void drive(Point destination) throws OutOfFuelException {
        double fuelNeed = location.distance(destination) * this.fuelConsumption;
    
        if ( fuelNeed > fuelAmount ) {
            throw new OutOfFuelException();
        }
    
        this.fuelAmount -= fuelNeed;
        this.location = destination;
    }
    
    public void drive(double x, double y) throws OutOfFuelException {
        drive(new Point(x, y));
    }
    
    public void refill(double fuel) throws ToMuchFuelException {
        double newFuel = this.fuelAmount + fuel;
    
        if ( newFuel > this.fuelCapacity ) {
            throw new ToMuchFuelException();
        }
        this.fuelAmount = newFuel;
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        
        out.append("Car: " + model + "\n");
        out.append("Location: " + location + "\n");
        out.append("Fuel: " + fuelAmount + "/" + fuelCapacity + "\n");
        out.append("Consumption: " + fuelConsumption + "\n");
        
        return out.toString();
    } 
}
