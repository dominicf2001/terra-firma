# Primary Goal

The primary objective of this project is to enhance my comprehension of design patterns and their implementation. To achieve this, I will be exploring the application of design patterns in contexts where they might be considered excessive or unsuitable. The focus is on learning and experimentation, rather than practicality.

# Progress
## Initialization

At the outset, I needed to establish fundamental data structures for the game. As the game's direction was not yet well-defined, I began by developing basic classes, such as Item, Harmonic (the abilities utilized in the game), and Player. The first design pattern that came to mind was the Flyweight pattern, considering the potential for numerous Items and Harmonics within the game. If multiple enemies were instantiated simultaneously, it could lead to a considerable and redundant memory footprint. Each instantiated enemy would possess a vector of Harmonics, many of which would be duplicates of those held by other enemies. Furthermore, all Harmonics would maintain a consistent state throughout the program.

The Flyweight pattern offers a solution to these issues, as each vector of Harmonics for each enemy would instead comprise pointers to the same Harmonics. This approach also incorporates lazy instantiation, which proves advantageous since Harmonics need not be instantiated until they are actually required.

Subsequently, I focused on the implementation of enemies within the game. Recognizing that both the Player and enemies required similar types of state information, I created an Actor class, from which both the Player and Enemy classes would inherit. However, I acknowledged that the Player class would necessitate additional methods and data, such as an inventory that is not required for enemies. This realization exposed a potential issue: with polymorphism integrated into the design, the client would have access to a "getInventory" request via the Actor interface, which is not ideal as it should be exclusive to the Player class.

To address this concern, I employed the Singleton pattern for the Player class, eliminating the need to access the Player through polymorphism. Instead, the getInstance method associated with the Player subclass is utilized. This approach ensures that polymorphism is primarily employed with the Enemy subclass, streamlining access to the Player's unique features while maintaining a consistent design structure.
