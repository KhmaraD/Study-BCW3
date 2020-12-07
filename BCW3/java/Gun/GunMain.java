public class GunMain {
    public static void main(String[] args) throws NotReadyException, OutOfRoundsException {
        Gun gun = new Gun();
        Gun colt = new Gun("Colt", 10);
        
        System.out.println(gun);
        System.out.println(colt);
        System.out.println("*******************");

        gun.reload();
        gun.prepare();

        System.out.println(gun);

        gun.shoot();

        System.out.println(gun);
        System.out.println("*******************");

        colt.reload();
        colt.prepare();
    
        System.out.println(colt);
    
        colt.shoot();
        colt.shoot();
        colt.shoot();

        System.out.println(colt);
    }
}