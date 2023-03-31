# Primary Goal

This project aims to enhance my understanding of design patterns and their implementation through exploration and experimentation, focusing on learning rather than practicality.
#Progress
##Initialization

I began by creating basic classes (Item, Harmonic, and Player) and implementing the Flyweight pattern to reduce redundant memory usage for numerous Items and Harmonics. This also included lazy instantiation for efficiency.

Next, I focused on enemy implementation, creating an Actor class for both Player and Enemy classes to inherit. To address the issue of exclusive methods for the Player class (e.g., "getInventory"), I employed the Singleton pattern. This streamlined access to Player-specific features while maintaining a consistent design structure.
