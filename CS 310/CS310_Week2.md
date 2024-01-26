---
title: CS310 Week 2
Date: Tuesday 03-07-2023 | 09:48:54
Updated at: Tuesday 03-07-2023 | 09:49:13
---

> `Each Java class has to have a constructor, if not written. Java at complile time puts a constructor for you. We need to implicitly add a constructor`
>
> Public\private access modifiers can be used with methods and instance variables.
>
> Classes cannot be `private`. 
>
> `private` variables and methods are accessible only to methods of the class in which they are declared.
> `public` variables and methods are available to all methods in the class.
>
> _**private class results in a compiler error.**_{: #important}
>
# Protected and Default
## Protected access modifier
> Classes cannot be protected.
> : `protected` fields and methods can only be accessed from the same package. 
>
## Default access modifier
> The default access modifier restricts access to the members of the same package. 
> :  This means that the members can be accessed only within the same package, but not outside the package.  
> <br> 
 > : This is useful for hiding implementation details and making the code more modular and easier to maintain.
>
# OOP Rule - Encapsulation
> Hiding of internal mechanisms and data structures' (state) of a component.
>
> Access is available via methods ONLY. {: #important}
> 
> Purpose is to achieve potential for change.
>
> Example
> : A car needs to know how much gas left in its tank. Other cars' don't matter.


> PoJo
> : Plain Old Java Object

<br>
<br>
<br>
<br>

---
Updated at: Wednesday 03-08-2023 | 14:41:36
# Week 2 Wednesday Class
###### Most of the code is located in the Composition file
---


```Java
    Car myCar = new Car("blue", 120, 1000, false, 0);
    Car mySecondCar = myCar;

    myCar.setColor("Red");
    
    System.out.println("myCar: " + myCar.getColor());
    System.out.println("myCar: " + mySecondcar.getColor());
    // Both have red color because the memloc of mySecondCar is equal to the myCar.


    myCar = null; //Null means nothing in Java. No memloc is reserved.
    mySecondCar = null;
    /* 
    In Java, we have a tool called garbage collector managed by JVM. Scans the memory and finds object without any references.
    The Car() object does not have a referance so it will be cleard by the garbage collector.

    We can call it by System.gc()
    System.exit(0); ⟶ Directly terminates the app.
    */
```

```Java
    // We can  make objects use other objects.

    package main;

    public class carPainter(){

        public void paintCar(Car car, String color){
            car.setColor(color);
            System.out.println("Car's color changed to: ", color);

        }
    }
```
```Java
    package main;

    public class PassVyRefAndVal {

        public static void main(String[] args) {
            Car myCar = new Car("blue", 120, 1000, false);

            CarPainter painter = new CarPainter();
            // Pass by reference
            painter.paintCar("Red");

            System.out.println(myCar.getColor()); // Logs Red
        }

        int x = 20;
        Valuechanger valChanger = new ValueChanger();

        valChanger.changeValue(x);

        System.out.println("x: ", x);

        // Reference types
        /*
            Say we have a car with a paint method that has blue as parameter.

            Reference types change the value reserved in the memory.
        */
    }
```

```Java
    package main;

    public class ValueChanger{

        public void changeValue(int number){
            number+=200;
        }

        // The method changeValue is overloaded.
        public int changeValue(int number, boolean check){
            number+=200;
            return value;
        }

        // method signature methodName(int, double, int)
    }
```

# OOP Rule - Composition & Aggregation

> A class can have references to objects of another classes by

```Java
// Located in Composition Project
package modal;

public class Customer {
    // Boilerplate code: It means repeating code, writing it again and again.
	private String name;
    private Address address;
    
    public void getInfo(){
        System.out.println("Customer: " + name);

        address.getInfo();
    }

    public Customer()
    {
        return Address;
    }

    public Customer(String name, Address address)
    {
        this.name = name;
        this.Address = address;
    }
    
    public String getName()
    {
        return this.name;
    }
}

public class Address {

    private int doorNo;
    private String street;
    private String addressType;

    public Address(){

    }

    public Address(int doorNo, String street, String addressType){
        this.doorNo = doorNo;
        this.street = street;
        this.addressType = addressType;
    }

    public void getInfo()
    {
        System.out.println("Address:");
        System.out.println("Door: " + doorNo);
        System.out.println("Street: " + street);
        System.out.println("Type: " + addressType);
    }

    public int getDoorNo(){
        return doorNo;
    }

    // Composition → Customer & Address relation
    //  ⟶ When customer dies, the address dies.
    // Aggregation → Customer & Product relation
    //  ⟶ When customer removed product from basket, the product flag is set to false. PRODUCT IS NOT DELETED.
}

```


```Java
package main;

import model.Address;
import model.Customer;

public class MainClass()
{
    public static void main(String[] args)
    {

        Address homeAddress = new Address(12, "Bagdat", "Home");

        Customer customer1 = new Customer("Jack", homeAddress);  
        customer1.getInfo();


        System.out.println("--------------------------------");

    
        Address emp1Home = new Address(1, "Stanford", "Home");
        Address emp2Work = new Address(20, "Some street", "Work");
        Address[] addresses = new Address[] { emp1Home, emp2Work};

        Employee emp1 = new Employee(1, "John", addresses);
    }

}
```

```Java
    package main;

    public class Employee{
        int id;
        String name;
        Add

        public Employee(){

        }

        public static void main(String[] args){
            
        }
    }
```

# OOP Rule: Inheritance
> Software reusability
>
> Create new class from existing class
>  > Absorb existing class' data and behaviours
>  > Enhance with new capabilities
>
> Subclass extends superclass
> > Subclass 
> > > More specialized gorup of objects.
> > > 
> > > Behaviours inherited from superclass.
> > > : Can customize
> > >
> > > Additional behaviours
>
> Referred as is-a relationship.
> ``` Java
> Subaru ⟶ Car ⟶ Vehicle
> public class Vehicle {/* Class body */}
> public class Car extends Vehicle {/* Class body */}
> public class Subaru extends Car {/* Class body */}
> ```

# Class Hierarchy
```Java

// Cat.java 
package model;

public class Cat extends Animal {
    private  String catType;

    // We have to create a constructor for cat and call the constructor of animal in it.

    @Override // In Java, if you're not sure if you're overriding, you need to put this to make sure that you're overwriting.
    public void makeSound(){
        System.out.println("Meoooowww");
    }

    public Cat(String catType, String habitat, String catType)
    {
        super(furColor, habitat);
        System.out.println("Cat constructor");
        this.catType = catType;
    }

            public void getInfo()
    {
        System.out.println("Cat: " + );
        super.getInfo();
    }

    public String getCatType() {
        return catType;
    }

    public void setCatType(String catType) {
        this.catType = catType;
    }
}

// Lion.Java

package model;

public class Lion extends Cat{

    private String continent;

    @Override;
    public void makeSound()
    {
        System.out.println("Roaaaar");
    }

    public Lion (String furColor, String habitat, String catType)
    {
        System.out.println("Lion constructor");
        super(furColor, furColor, catType);
    } 

    public ()
    {

    }
}

// Animal.java
// All classes in Java implicity extend from Object class. 
// Object is the root class in
package model;
public class Animal
{
    private String furColor;
    private String habitat;

    public Animal(String furColor, String habitat){
        System.out.println("Animal constructor");
        super(); // Means call superclass constructor first and move on with the initialization.
        this.furColor = furColor;
        this.habitat = habitat;
    }

    public void makeSound()
    {
        System.out.println("No sound.");
    }

    public void getInfo()
    {
        System.out.println("Animal ");
        System.out.println("Animal ");
    }
}

// MainClass.Java
package main;

import model.Animal;
import model.Cat;


public class MainClass{
    // public static void main(String[] args) {
        
    //     Cat cat1 = new Cat();
    //     cat1.setCatType("House");
    //     cat1.setFurColor("Gray");
    //     cat1.setHabitat("City");

    //     cat1.getInfo();
    // }

    Lion lion1 = new Lion("Yellow", "Forest", "Wild Cat", "Africa");

    Animal cat1 = new Cat("Yellow", "House", "House");
    System.out.println("---------Cat");
    cat1.makeSound();

    Cat lion2 = new Lion("Yellow", "Forest", "Wild Cat", "Africa");


}
```

# Introduction to 1rphism
> A reference of a class may point to objects ob subclasses.



<style>
    #important{
        color: red;
    }
</style>