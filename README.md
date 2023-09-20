# Clunk-Lang
A simple byte-code interpreter written in C for the Lunk language. *(The name Clunk being a funny contraction.)*

The compiler is a single pass compiler, electing to avoid an intermediate form (AST or what have you).

This is based on the book, [Crafting Interpreters](https://craftinginterpreters.com/), by Robert Nystrom.

# Installation
Simply download the repo and use the **make** utility to build the project.

# Using the Compiler
Running the CLunk executable without a Lunk source file as an argument will open the REPL enviroment of CLunk. To load a Lunk script, just specify the file after the CLunk executable.