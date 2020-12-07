public class Gun {
    private int amount;
    private int capacity;
    private boolean isReady;
    private String model;
    private int totalShots;
    
    public Gun(String model, int capacity) {
        this.amount = 0;
        this.capacity = capacity;
        this.isReady = false;
        this.model = model;
        this.totalShots = 0;
    }
    
    public Gun() {
        this("Beretta", 8);
    }
    
    public int getAmount() {
        return amount;
    }
    
    public int getCapacity() {
        return capacity;
    }
    
    public boolean ready() {
        return isReady;
    }
    
    public String getModel() {
        return model;
    }
    
    public int getTotalShots() {
        return totalShots;
    }
    
    public void prepare() {
        isReady = !isReady;
    }
    
    public void reload() {
        amount = capacity;
    }
    
    public void shoot() throws NotReadyException, OutOfRoundsException {
        if ( !ready() ) {
            throw new NotReadyException();
        }
        if ( amount == 0 ) {
            isReady = false;
            throw new OutOfRoundsException();
        }
        amount -= 1;
        totalShots += 1;
        System.out.println("Bang!");
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        
        out.append("Model: " + model + "\n");
        out.append("Capacity: " + capacity + "\n");
        out.append("Amount: " + amount + "\n");
        out.append("Total Shoots: " + totalShots + "\n");
        
        return out.toString();
    }
}
