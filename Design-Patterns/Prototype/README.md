### Prototype design pattern
### Intent:
    - creating an object is expensive operation than copy an object
    - All objects initial state is common and takes time to build
    - composition, creation, and representation of objects should be decoupled from the system
    - hide the complexity of creating new instance from the user
    - which classes to create are specified at runtime

### Downsides:
    - copying an object can be complicated
    - circular references class can not be cloned
    - over use of this might affect the performance

### Compile:
g++ -std=c++14 prototype.cpp
