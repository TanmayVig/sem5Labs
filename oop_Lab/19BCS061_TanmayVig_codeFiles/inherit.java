import java.util.*;

class Employee{
    int sNo;
    String name;
    long salary;

    public Employee(int sNo, String name, long salary) {
        this.sNo = sNo;
        this.name = name;
        this.salary = salary;
    }
}

class Manager extends Employee{
    String position;

    public Manager(int sNo, String name, long salary, String position){
        super(sNo,name,salary);
        this.position = position;
    }

    public void getData(){
        System.out.println("Emoplyee Details:\nSerial Number: "+ this.sNo+"\nName: "+ this.name+"\nPosition: "+ this.position + "\nSalary "+this.salary);
    }

}

public class inherit{
    public static void main(String[] args){

        Manager m = new Manager(100,"Tanmay Vig",1000000,"General Manager");
        m.getData();

    }
}