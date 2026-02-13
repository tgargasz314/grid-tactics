# Grid Tactics

A custom C++ game engine and tactical grid-based game project built for learning modern engine architecture, rendering pipelines, and cross-platform development using SDL3.

This project serves as both:

* A sandbox for engine architecture experimentation
* A long-term foundation for a tactical RPG / grid combat system
* A platform to deepen knowledge of rendering, input systems, timing, and process management

---

# Tech Stack

* C++20
* CMake (cross-platform build system)
* SDL3 (windowing, input, rendering backend)
* MSVC (Windows)
* GCC / Clang (Linux)
* vcpkg (Windows dependency management)

---

# Project Structure

```
grid-tactics/
│
├── engine/        # Core engine systems
│   ├── core/      # Application, process management
│   ├── platform/  # Windowing, input abstraction
│   └── render/    # Rendering systems
│
├── game/          # Game-specific implementation
│
├── CMakeLists.txt
└── README.md
```

The engine is designed to remain independent from game logic, allowing reuse for future projects.

---

# Building the Project

This project is fully cross-platform.

---

# Linux (Debian / Ubuntu)

## 1. Install Dependencies

```bash
sudo apt install build-essential cmake libsdl3-dev
```

## 2. Build

From the project root:

```bash
cmake -S . -B build
cmake --build build
```

## 3. Run

```bash
./build/grid-tactics
```

---

# Windows (VS Code + MSVC Build Tools + vcpkg)

This project does NOT require the Visual Studio IDE, but it does require the MSVC C++ build tools.

---

## 1. Install Required Tools

Install the following:

* Build Tools for Visual Studio 2022
  (Select **Desktop development with C++** OR MSVC + Windows SDK)
* CMake
* Git

---

## 2. Install vcpkg

```powershell
mkdir C:\dev
cd C:\dev
git clone https://github.com/microsoft/vcpkg
cd vcpkg
.\bootstrap-vcpkg.bat
```

---

## 3. Install SDL3 via vcpkg

```powershell
cd C:\dev\vcpkg
.\vcpkg install sdl3:x64-windows
```

(Optional) Integrate with MSBuild:

```powershell
.\vcpkg integrate install
```

---

## 4. Configure & Build

From your project root:

```powershell
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build build
```

---

## 5. Run

```powershell
cd build
.\grid-tactics.exe
```

---

# VS Code Setup (Recommended)

Install Extensions:

* CMake Tools (Microsoft)
* C/C++ (Microsoft)

Create:

```
.vscode/settings.json
```

With:

```json
{
    "cmake.configureSettings": {
        "CMAKE_TOOLCHAIN_FILE": "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake"
    },
	"cmake.generator": "Ninja"
}
```

Then:

1. Select Kit → MSVC Build Tools
2. Configure
3. Build

---

# Why This Project Exists

This project is focused on understanding:

* Engine process loops
* Delta time and frame timing
* Input abstraction layers
* Renderer architecture
* Cross-platform build systems
* Clean separation between engine and game code
* Compiler portability (GCC vs MSVC)

The goal is not just to make a game — but to understand how engines are structured internally.

---

# Current Status

* SDL window creation
* Engine application loop
* Basic rendering pipeline
* Cross-platform build confirmed (Linux + Windows)

---

# Planned Milestones

* Delta time system
* Input handling abstraction
* Grid system implementation
* Turn-based process management
* Camera system

---

# Future Plans

* Tilemap rendering
* ECS exploration
* Data-driven ability system
* Animation system
* Tooling support

---

# License

This project is currently for educational and experimental purposes.

A license may be added in the future as the project matures.
