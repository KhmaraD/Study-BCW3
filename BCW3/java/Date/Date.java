public class Date {
    private int day;
    private int month;
    private int year;
    
    private void validate(int day, int month, int year) throws InvalidDateException {
        int [] days = new int [] {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        if ( year % 400 == 0 || (year % 100 != 0 && year % 4 == 0) ) {
            days[2] = 29;
        }
    
        if ( year < 1582 ) {
            throw new InvalidDateException("Invalid Year!");
        }
    
        if ( month < 1 || month > 12 ) {
            throw new InvalidDateException("Invalid Month!");
        }
    
        if ( day < 1 || day > days[month] ) {
            throw new InvalidDateException("Invalid Day!");
        }
    }
    
    public Date (int day, int month, int year) throws InvalidDateException {
        validate(day, month, year);
        
        this.day = day;
        this.month = month;
        this.year = year;
    }
    
    public Date () throws InvalidDateException {
        this(1, 1, 1970);
    }
    
    public int getDay() {
        return day;
    }
    
    public int getMonth() {
        return month;
    }
    
    public int getYear() {
        return year;
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        
        if ( day < 10 ) {
            out.append("0");
        }
        
        out.append(day + ".");
        
        if ( month < 10 ) {
            out.append("0");
        }
        
        out.append(month + "." + year);
        
        return out.toString();
    }
}
