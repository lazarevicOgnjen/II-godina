# Mermaid

<br>

**Class Diagrams:**

- Inheritance: ClassA <|-- ClassB
  
- Composition: ClassA *-- ClassB
  
- Aggregation: ClassA o-- ClassB
  
- Association: ClassA --> ClassB
  
- Dependency: ClassA ..> ClassB

<br>

<pre>
  
classDiagram
    class Car {
        +String make
        +String model
        +int year
        +start()
        +stop()
    }
    
    class Engine {
        +int horsepower
        +String type
        +start()
        +stop()
    }
    
    class Driver {
        +String name
        +int age
        +drive()
    }
    
    Car "1" *-- "1" Engine : has
    Driver "1" -- "0..*" Car : drives

</pre>


