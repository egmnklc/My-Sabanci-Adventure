---
title: Week 1 - Introdution to Java
created: 03/01/2023
Updated at: Wednesday 03-01-2023 | 14:27:24
---

# Compiler - Interpreter

## Java is both compiled and an interpreted language.
- Used for developing large-scale enterprise apps
- We'll be dealing with Java SE (Standard Editon)
## Java Techs
* Java SE
* Java EE
  * Oracle, etc...
* Java ME
    - Used in payments system such as the PoS machines.
## Java in Server Environments
> _Middleware_: Bridge between client and database.
> 
>_Monolithic Arc:_ All in one.
> 
>_JDK_: Has the runtime environment.
> 
>_JRE_: Java runtime environment.
> 
>_JVM_: The interpreter.
>> JDK > JRE > JVM

---
OpenJDK comes with Spring tools

---
- .java(uncompiled file) 
    - Compile 
        - File compiled into .class 
            - This is converted into bytecode
---

- Bytecode is interpreted in a java machine.

---
* All Java code must be written inside a class.
```Java
public class Hello {
    public static void main(String[] args)
    {
        System.out.println("Hello World");
    }
}
``` 

# Sample Class Decleration
```Java
package main;

public class BasicConcepts{
    public static void main(String[] args)
    {
        
    }
}
```
# Primitive Data Typess
- Any data that is not a primitive data type is of reference type.
```Java
// Variables
// byte, short, int
// float, double
// char -> 16 bits
int x = 12;
int y = 15;

int sum = x + y;

System.out.println(sum);

double dNum = 12.3; // Double, contains 64 bits, Integers are 32 bits.
dNum = x + y; // This is called implicit casting. Implicit casting means the byte size of the current data type is being widedened. In this example byte size of int is 32 bits and double is 64 bits. At this line, int is converted to double and operation is completed then.

// add larger types and get a smaller type result
// double + double ? = int

double d1 = 12.2;
double d2 = 23.3;

// We got 2 compile errors, Runtime and Compiler Errors.
int result = d1+d2; // Compiler error here. We need to cast them by adding paranthesis.

// This is called explicit casting. Explicit casting reduces the bits allocated by the data type. double is 64 bits and int is 32 bits.
int result = (int)(d1+d2); // We need to cast them by adding paranthesis. Precision (the decimal part) might be lost.
// Result is 35.

// Strings
// Strings are reference types but act like primitive types.
String name = "string value" // Literal stands for a value such as 42 or Hello World!. Strings begin with capital letters.
// String is not a directly primitive data type but acts like one.
// Concating strings with + is not a safe optionf or Java.


// Getting console input \ Read from the console.
Scanner input = new Scanner(System.in); // This is the constructor call.
System.out.println("What's your name?");
String name = input.nextline(); 
System.out.println("Hello " + name);

byte b1 = 32;
byte b2 = 13;

boolean check = true; // You have to type in, 1 and 0 are not allowed.
// Any integer int sized smaller is an int.
byte byteSum = b1+b2; // You're trying to add up bytes and get a byte, compiler error. Here, Java converts them automatically to int. Since there's not casting, the compiler throws error. 
byte byteSum = (byte)(b1+b2) // This will work


// Controls, if and such stuff
// && and || symbols are called short circuit opeartions. Left side is checked first and block executed related.x
if (b1>11 && b2<14){
    System.out.println("greater");
} else  {
    System.out.println("less");
}


// Primitive type assignments
int x1 = 12;
int x2 = x1;
x1++;

System.out.println("x1 :" x1); // 13
System.out.println("x2 :" x2); // 12

// Explanation: x1 points to some location in the memory of size 32 bits. 
// During the assignment, x2's value points to another memory location with the same value.
// ! [This only happens with reference types]

// The size is fixed.
String[] names = ["Ali", "Veli", "Selami", "Batuhan"]; // Array of Strings decleration

int[] numbers = new int[3]; // Array of 3 integers with name numbers
numbers[0] = 2;
numbers[1] = 3;
numbers[2] = 4;

System.out.println(names[1]); // Veli

for (int i = 0; i < numbers.length; i++){
    System.out.println(numbers[i]);
}

// Directly accessing array elements
for (String name_ : names) {
    System.out.println(name_);
}

// While loop
int incrementor = 0;
while (incrementor < numbers.length>) {
    System.out.println(numbers[incrementor]);
    incrementor++;
}

```
---
# Object Oriented Programming
## Classes
* Car anaology
* ==Class names start with an uppercase letter==
* All Java code must be written in classes, and the files must be placed in a package.
## What is an Object
* Objects have 2 major parts: State and Behaviour.

## OOP Rule - Abstraction
* Simplifying complex reality by modeling classes appropriate to the problem. Extracting objects from a real life situation.
  * Real life car → Car Class
---

## Class Decleration
```Java
package main;

public class Car {
    // This decleration is not the correct way to do so.
    // Instance variables
    // Fields
    // Global variables of a class

    // After → Say we cleared color and horsePower
    String color;
    int horsePower;
    int engineVolume = 1200;
    boolean engineStarted = false;

    int currentSpeed = 0;

    void startEngine()
    {
        if ( !engineStarted ){
            engineStarted = true;
            System.out.println("Engine started");
        } else {
            System.out.println("Engine is already started!");
        }
    }

    void changeSpeed(int speed) {
        currentSpeed = speed;
        System.out.println("Speed changed to " + currentSpeed);
    }

    void stopEngine(){
        if (engineStarted) {
            engineStarted = false; 
            System.out.println("Engine is stopped");
        } else {
            System.out.println("Engine is already stopped");
        }
    }
}
```
```Java
package main; 

public class Car2 {

    String color;
    int horsePower;
    int engineVolume;
    boolean engineStarted;
    int currentSpeed;

    public Car2(){ // This is called the default constructor of Car2 class. Another name is no-argument constructor.

        color = "blue";
        horsePower = 120;
        engineVolume = 1200;
        engineStarted = false;
        currentSpeed = 0;
    }

    // Constructor Overloading
    // Adding constructors with different sets of arguments.
    public Car2(String _color, int _engineVolume){ 

        _color = color ;
        _engineVolume = engineVolume;
    }

    // Object property name is the same with parameter name, use this. When this is used, it is known as shadowing.

    public Car2(String color, int engineVolume, int horsePower, boolean engineStarted, int currentSpeed){ 

        this.color = color;
        this.horsePower = horsePower;
        this.engineVolume = engineVolume;
        this.engineStarted = engineStarted;
        this.currentSpeed = currentSpeed;
    }


    void startEngine()
    {
        if ( !engineStarted ){
            engineStarted = true;
            System.out.println("Engine started");
        } else {
            System.out.println("Engine is already started!");
        }
    }

    void changeSpeed(int speed) {
        currentSpeed = speed;
        System.out.println("Speed changed to " + currentSpeed);
    }

    void stopEngine(){
        if (engineStarted) {
            engineStarted = false; 
            System.out.println("Engine is stopped");
        } else {
            System.out.println("Engine is already stopped");
        }
    }
}
```
## Using The Car Class
```Java
package main;

public static void main(String[]) {
    Car car1 = new Car();
    // Now we can acces the state of the car1 Object.
    System.out.println("Color: " + car1.color);
    System.out.println("Speed: " + car1.currentSpeed);
    System.out.println("HP: " + car1.horsePower);
    // If nothing is assigned in the class decleration as default value, it will return default values.
    // numeric -> 0
    // bools -> false
    // String or reference types -> null
    car1.startEngine();
    car1.changeSpeed(50);
    car1.changeSpeed(0);
    car1.stopEngine();

    Car2 carNew = new Car2("red", 1600, 190, false, 0);
    System.out.println(carNew.color);
}




```
---
## Methods





 
#### h4
##### h4



**bold**

_underlined_

Link to [Google](http://www.google.com/)
 
[Test]

[[ Test ]]
> Test
>> Test
>>> Test
>>>> Test
```
Code
```

1. Numbered list 1
2. Numbered list 2

- Unordered list
    - Sublist
      - Another sublist


*italic*

---
## Custom CSS
---
>[ This will be in red ]{: #important}

>[ This will be in yellow ]{: #note}

Dummy text here

<style>
    #important {
        color: red; 
    } 
    #note {
        color: #A5906D;
    }
</style>
---

 ~~Scratch this.~~