# Cursus42_CPPs

![Language](https://img.shields.io/badge/language-C%2B%2B98-blue)
![Standard](https://img.shields.io/badge/std-c%2B%2B98-informational)
![Flags](https://img.shields.io/badge/flags--Wall%20--Wextra%20--Werror-critical)
![42](https://img.shields.io/badge/42-Common%20Core-black)

Colección de los **C++ modules** del Common Core de la escuela 42. Cada módulo es
una piscina temática que introduce, de forma incremental, los fundamentos de la
Programación Orientada a Objetos en **C++98**.

> Nota: estos son módulos de C++, no de C. Como indica el propio enunciado de 42,
> la Norminette **no aplica** aquí ("Goodbye Norminette!"). El código sigue el
> estándar **C++98** y, salvo excepción explícita, la **Forma Canónica Ortodoxa**.

## Módulos

| Módulo | Tema | Ejercicios | Conceptos clave |
|--------|------|-----------|-----------------|
| [`cpp00`](cpp00) | Namespaces, clases, I/O | ex00–ex02 | Clases, miembros, `std::cout`, streams. |
| [`cpp01`](cpp01) | Memoria, referencias, punteros | ex00–ex06 | `new`/`delete`, referencias, punteros a miembros. |
| [`cpp02`](cpp02) | Forma Canónica Ortodoxa, sobrecarga | ex00–ex03 | Ad-hoc polymorphism, operadores, punto fijo. |
| [`cpp03`](cpp03) | Herencia | ex00–ex02 | Herencia, herencia en diamante. |
| [`cpp04`](cpp04) | Polimorfismo y abstracción | ex00–ex03 | Funciones virtuales, clases abstractas, interfaces. |
| [`cpp05`](cpp05) | Repetición y excepciones | ex00–ex03 | `try`/`catch`, clases de excepción, factory sin `if/else`. |

## Requisitos

- Compilador `c++` con soporte de C++98 (clang o g++).
- `make`.

## Estructura del repositorio

```
Cursus42_CPPs/
├── cpp00/ … cpp05/      # un módulo por carpeta
│   ├── ex00/ … exNN/    # un ejercicio por carpeta, cada uno con su Makefile
│   └── docs/            # documentación técnica y diagramas (cuando aplica)
└── README.md
```

Cada ejercicio es autocontenido e incluye su propio `Makefile` con las reglas
estándar de 42.

## Compilación y uso

```sh
# Compilar un ejercicio concreto
cd cpp05/ex00 && make

# Ejecutar el binario resultante
./bureaucrat

# Reglas disponibles en cada Makefile
make        # compila (all)
make clean  # borra objetos
make fclean # borra objetos y binario
make re     # recompila desde cero
```

Todos los ejercicios compilan con las flags obligatorias del cursus:

```sh
c++ -Wall -Wextra -Werror -std=c++98
```

## Reglas del cursus respetadas

- Estándar **C++98** (`-std=c++98`), compilación sin warnings ni errores.
- Clases en **Forma Canónica Ortodoxa** (constructor por defecto, constructor de
  copia, operador de asignación y destructor), salvo excepción explícita del
  enunciado (p. ej. las clases de excepción).
- Prohibido `*printf()`, `*alloc()` y `free()`; prohibido `using namespace` y
  `friend` salvo indicación contraria.
- Sin contenedores ni algoritmos de la STL (hasta los módulos que los permiten).
- Gestión de memoria sin fugas: cada `new` tiene su `delete` correspondiente.
- Include guards en todas las cabeceras; sin implementación en los headers
  (excepto plantillas de función).

## Autor

Raúl (RaulMkn) — 42 Common Core.
