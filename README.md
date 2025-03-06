# Toy Management System

## Overview
This C++ program models a toy management system using object-oriented programming principles. The system categorizes toys into action figures (`Action`) and puzzles (`Puzzle`), allowing users to add, display, and analyze toys based on their dimensions and characteristics.

## Features
- **Add Toys**: Users can add both action figures and puzzles with specific attributes.
- **Display Toys**: Prints details of all stored toys.
- **Filter by Theme**: Finds toys based on their theme.
- **Calculate Size Factor**: Computes a characteristic value for each toy.
- **Sort Toys**: Sorts the collection based on computed size factor.

## Classes
### `Jucarie` (Base Class)
- **Attributes**: `tip` (type), `tematica` (theme), `nume` (name)
- **Virtual methods**: `afisare()`, `dimensiune()` (computes a size-related value), `afis()`

### `Action` (Action Figures)
- **Inherits from**: `Jucarie`
- **Additional attributes**: `inaltime` (height), `latime` (width), `lungime` (length)
- **Overrides**: `afisare()`, `dimensiune()`, `afis()`

### `Puzzle`
- **Inherits from**: `Jucarie`
- **Additional attributes**: `numar` (number of pieces), `latime` (width), `lungime` (length)
- **Overrides**: `afisare()`, `dimensiune()`, `afis()`

### `Gestionare`
- **Stores** a collection of `Jucarie` objects in a vector
- **Provides methods to**: add, display, filter, sort, and analyze toys
