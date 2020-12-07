public class Unit {
    private int damage;
    private int hitPoints;
    private int hitPointsLimit;
    private String name;
    
    private void ensureIsAlive() throws UnitIsDeadException {
        if ( hitPoints == 0 ) {
            throw new UnitIsDeadException();
        }
    }
    
    public Unit(String name, int hp, int dmg) {
        this.damage = dmg;
        this.hitPoints = hp;
        this.hitPointsLimit = hp;
        this.name = name;
    }
    
    public int getDamage() {
        return damage;
    }
    
    public int getHitPoints() {
        return hitPoints;
    }
    
    public int getHitPointsLimit() {
        return hitPointsLimit;
    }
    
    public String getName() {
        return name;
    }
    
    public void addHitPoints(int hp) throws UnitIsDeadException {
        ensureIsAlive();
        
        hitPoints += hp;
    
        if ( hitPoints > hitPointsLimit ) {
            hitPoints = hitPointsLimit;
        }
        
        System.out.println("The " + this.getName() + " was healed for " + hp + " hp!");
    }
    
    public void takeDamage(int dmg) throws UnitIsDeadException {
        ensureIsAlive();
        
        hitPoints -= dmg;
        
        if ( hitPoints <= 0 ) {
            hitPoints = 0;
            System.out.println("The " + this.getName() + " is dead!" );
            throw new UnitIsDeadException();
        }
    }
    
    public void attack(Unit enemy) throws UnitIsDeadException {
        ensureIsAlive();
        
        System.out.println("The " + this.getName() + " attacked " + enemy.getName());
        
        enemy.takeDamage(this.damage);
        
        if (enemy.getHitPoints() > 0 ) {
            enemy.counterAttack(this);
        }
    }
    
    public void counterAttack(Unit enemy) throws UnitIsDeadException {
        ensureIsAlive();
        
        enemy.takeDamage(this.damage/2);
        
        System.out.println("The " + this.getName() + " counter attacked " + enemy.getName());
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        
        out.append("Name: " + name + "\n");
        out.append("Hit Points: " + getHitPoints() + "/" + getHitPointsLimit() + "\n");
        out.append("Damage: " + getDamage() + "\n");
        
        return out.toString();
    }
}
