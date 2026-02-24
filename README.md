# UNO_ED
Juego de UNO para aprender sobre estructura de datos.

## Requisitos

- CMake 3.10 o superior
- Compilador C++ con soporte C++17

### Windows
- Visual Studio 2022 (Desktop development with C++) **o** MinGW-w64

### Linux
- `g++` o `clang++`
- `build-essential` (en Ubuntu/Debian)

## Compilar en Windows (PowerShell)

```powershell
cd Game
cmake -S . -B build
cmake --build build --config Release
```

Ejecutar:

```powershell
.\build\Release\UNO.exe
```

Si no existe `Release` (por ejemplo con MinGW), prueba:

```powershell
.\build\UNO.exe
```

## Compilar en Linux (bash)

```bash
cd Game
cmake -S . -B build
cmake --build build -j
```

Ejecutar:

```bash
./build/UNO
```

## Notas de portabilidad

- El proyecto ya usa C++17 de forma estricta (`CMAKE_CXX_EXTENSIONS OFF`).
- La limpieza de pantalla se hace por plataforma:
	- Windows: `cls`
	- Linux/macOS: secuencia ANSI (`\033[2J\033[H`)
- Si en Linux falla CMake por falta de compilador:

```bash
sudo apt update
sudo apt install -y build-essential cmake
```
