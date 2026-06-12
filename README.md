# Design Patterns

C++ implementations of all **23 Gang of Four (GoF)** design patterns from *Design Patterns: Elements of Reusable Object-Oriented Software* (Gamma, Helm, Johnson, Vlissides).

Each pattern has its own directory with headers, a runnable example, and a `Makefile`. For intent, UML class diagrams, and per-pattern notes, see **[Patterns.md](Patterns.md)**.

## Requirements

| Dependency | Used by |
|------------|---------|
| C++17 compiler (`g++` / `clang++`) | All patterns |
| `make` | All patterns |
| `libgtest-dev` | Chain of Responsibility, Command, Iterator, Memento, Visitor |

Install Google Test on Debian/Ubuntu:

```bash
sudo apt install libgtest-dev
```

## Project Structure

```
Design_Patterns/
├── Creational/     # 5 patterns — object creation
├── Structural/     # 7 patterns — composition & structure
├── Behavioral/     # 11 patterns — collaboration & behavior
├── Patterns.md     # UML reference for all 23 patterns
└── README.md
```

## Quick Start

```bash
cd Behavioral/Interpreter
make
./interpreter
```

| Target | Action |
|--------|--------|
| `make` | Build the example |
| `make re` | Clean rebuild |
| `make fclean` | Remove binary and object files |

### Build every pattern

```bash
for makefile in Creational/*/Makefile Structural/*/Makefile Behavioral/*/Makefile; do
  (cd "$(dirname "$makefile")" && make -s re)
done
```

Patterns that use Google Test run their test suite when executed (e.g. `./command`).

## Pattern Index

### Creational (5)

| Pattern | Path | Run |
|---------|------|-----|
| Abstract Factory | [`Creational/Abstract_Factory`](Creational/Abstract_Factory) | `make` → `./abstract_factory` |
| Builder | [`Creational/Builder`](Creational/Builder) | `make` → `./builder` |
| Factory Method | [`Creational/Factory_Method`](Creational/Factory_Method) | `make` → `./factory_method` |
| Prototype | [`Creational/Prototype`](Creational/Prototype) | `make` → `./prototype` |
| Singleton | [`Creational/Singleton`](Creational/Singleton) | `make` → `./logger` |

### Structural (7)

| Pattern | Path | Run |
|---------|------|-----|
| Adapter | [`Structural/Adapter`](Structural/Adapter) | `make` → `./app` |
| Bridge | [`Structural/Bridge`](Structural/Bridge) | `make` → `./bridge` |
| Composite | [`Structural/Composite`](Structural/Composite) | `make` → `./composite` |
| Decorator | [`Structural/Decorator`](Structural/Decorator) | `make` → `./decorator` |
| Facade | [`Structural/Facade`](Structural/Facade) | `make` → `./app` |
| Flyweight | [`Structural/Flyweight`](Structural/Flyweight) | `make` → `./flyweight` |
| Proxy | [`Structural/VirtualProxy`](Structural/VirtualProxy) | `make` → `./virtual_proxy` |

### Behavioral (11)

| Pattern | Path | Run |
|---------|------|-----|
| Chain of Responsibility | [`Behavioral/ChainOfResponsibility`](Behavioral/ChainOfResponsibility) | `make` → `./chainofresponsability` |
| Command | [`Behavioral/Command`](Behavioral/Command) | `make` → `./command` |
| Interpreter | [`Behavioral/Interpreter`](Behavioral/Interpreter) | `make` → `./interpreter` |
| Iterator | [`Behavioral/Iterator`](Behavioral/Iterator) | `make` → `./iterator` |
| Mediator | [`Behavioral/Mediator`](Behavioral/Mediator) | `make` → `./mediator` |
| Memento | [`Behavioral/Memento`](Behavioral/Memento) | `make` → `./memento` |
| Observer | [`Behavioral/Observer`](Behavioral/Observer) | `make` → `./observer` |
| State | [`Behavioral/State`](Behavioral/State) | `make` → `./state` |
| Strategy | [`Behavioral/NVI_Strategy`](Behavioral/NVI_Strategy) | `make` → `./banking` |
| Template Method | [`Behavioral/TemplateMethod`](Behavioral/TemplateMethod) | `make` → `./template_method` |
| Visitor | [`Behavioral/Visitor`](Behavioral/Visitor) | `make` → `./visitor` |

## UML Reference

[Patterns.md](Patterns.md) is the canonical reference. For each of the 23 patterns it provides:

- **Intent** — what problem the pattern solves
- **Example** — what the local demo demonstrates
- **UML** — Mermaid class diagram
- **Implementation** — link to source with build command

## Conventions

- Header-only or `.hpp` / `.cpp` split per pattern
- C++17, `-Wall -Wextra -Werror` where enforced
- Demos print to `stdout` or use Google Test for verification

## License

Educational reference project. Use and adapt freely.
