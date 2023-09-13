# Primary Goal

This project aims to enhance my understanding of design patterns and their implementation through exploration and experimentation, focusing on learning rather than practicality.

# Progress
## Initialization

I began by creating basic classes (Item, Harmonic, and Player) and implementing the Flyweight pattern to reduce redundant memory usage for numerous Items and Harmonics. This also included lazy instantiation for efficiency.

Next, I focused on enemy implementation, creating an Actor class for both Player and Enemy classes to inherit. To address the issue of exclusive methods for the Player class (e.g., "getInventory"), I used the Singleton pattern. This streamlined access to Player-specific features while maintaining a consistent design structure.

The possibility of further differentiation between Player and Enemy behaviors highlights the advantages of adopting a composition-based approach over inheritance. This refactoring would enhance adaptability and ease of modification, ensuring a more scalable game structure.

## Battle system

Considering the numerous potential directions for the game, I started by focusing on the battle system. Anticipating the need for modularization, I opted for a simplistic function-based implementation, with the intention of abstracting the logic into a class or series of classes at a later stage. I devised a rudimentary turn-based loop reminiscent of the Pokémon-style battle system, where the player selects from a set of Harmonics (abilities) to use against the enemy. To establish the foundational logic, I began by incorporating a basic attack Harmonic.

Here, I recognized the value of incorporating a "utilities" file containing general-purpose operations to be utilized throughout the game. Among these utilities was a random number generator, which, when implemented idiomatically in C++, necessitates the employment of a class. This streamlined the development of the battle system.

Following the implementation of battle logic, I devised a BattleSystem class to improve scalability and flexibility. This involved separating the Actor classes' implementation and consolidating it within the BattleSystem. Consequently, Actor classes maintain state and delegate behavior to the BattleSystem, which is expected to benefit future applications involving the Actor classes, particularly the Player class. This approach seems to be a mixture of the Bridge and Mediator design patterns.

### Harmonics

Harmonics are specialized abilities within the game's battle mode. To seamlessly integrate them with the BattleSystem while maintaining decoupling, the command design pattern is employed. The abstract Harmonic class has a pure virtual "use" method, which takes a callback function with an integer argument, representing various effects. This approach allows Harmonics to remain decoupled, enabling diverse utilization, with the eventual goal of expanding their use beyond the BattleSystem.
