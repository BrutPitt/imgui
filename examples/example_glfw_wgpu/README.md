## How to Build     

### Using CMake
#### Building for desktop (WebGPU-native) with Google Dawn:
 1. `git clone https://github.com/google/dawn dawn`
 2. `cmake -B build -DIMGUI_DAWN_DIR=dawn`
 3. `cmake --build build`
The resulting binary will be found at one of the following locations:
  * build/Debug/example_sdl2_wgpu[.exe]
  * build/example_sdl2_wgpu[.exe]

#### Building for desktop (WebGPU-Native) with WGPU:
 1. download WGPU-Native autogenerated binary modules for your platform/compiler from: https://github.com/gfx-rs/wgpu-native/releases
 2. unzip the downloaded file in `your_preferred_folder`
 3. move into `your_preferred_folder` (e.g. typing: `cd your_preferred_folder`)
 4. `cmake -B build -DIMGUI_WGPU_DIR=your_preferred_folder`  ("full path" or "relative" starting from current directory)
 5. `cmake --build build`
The resulting binary will be found at one of the following locations:
  * build/Debug/example_sdl2_wgpu[.exe]
  * build/example_sdl2_wgpu[.exe]

#### Building for Emscripten:
 1. Install Emscripten SDK following the instructions: https://emscripten.org/docs/getting_started/downloads.html
 2. Install Ninja build system
 3. `emcmake cmake -G Ninja -B build`
 4. `cmake --build build`

To run:
 - `emrun build/index.html`

or
 - `python -m http.server`  then open WGPU browser with url: `http://localhost:8000/build`


### Using makefile 

- You need to install Emscripten from https://emscripten.org/docs/getting_started/downloads.html, and have the environment variables set, as described in https://emscripten.org/docs/getting_started/downloads.html#installation-instructions

- Depending on your configuration, in Windows you may need to run `emsdk/emsdk_env.bat` in your console to access the Emscripten command-line tools.

- You may also refer to our [Continuous Integration setup](https://github.com/ocornut/imgui/tree/master/.github/workflows) for Emscripten setup.

- Then build using `make -f Makefile.emscripten` while in the `example_glfw_wgpu/` directory.

- Requires recent Emscripten as WGPU is still a work-in-progress API.

## How to Run

To run on a local machine:
- Make sure your browse supports WGPU and it is enabled. WGPU is still WIP not enabled by default in most browser.
- `make serve` will use Python3 to spawn a local webserver, you can then browse http://localhost:8000 to access your build.
- Otherwise, generally you will need a local webserver:
  - Quoting [https://emscripten.org/docs/getting_started](https://emscripten.org/docs/getting_started/Tutorial.html#generating-html):<br>
_"Unfortunately several browsers (including Chrome, Safari, and Internet Explorer) do not support file:// [XHR](https://emscripten.org/docs/site/glossary.html#term-xhr) requests, and can’t load extra files needed by the HTML (like a .wasm file, or packaged file data as mentioned lower down). For these browsers you’ll need to serve the files using a [local webserver](https://emscripten.org/docs/getting_started/FAQ.html#faq-local-webserver) and then open http://localhost:8000/hello.html."_
  - Emscripten SDK has a handy `emrun` command: `emrun web/example_glfw_wgpu.html --browser firefox` which will spawn a temporary local webserver (in Firefox). See https://emscripten.org/docs/compiling/Running-html-files-with-emrun.html for details.
  - You may use Python 3 builtin webserver: `python -m http.server -d web` (this is what `make serve` uses).
  - You may use Python 2 builtin webserver: `cd web && python -m SimpleHTTPServer`.
  - If you are accessing the files over a network, certain browsers, such as Firefox, will restrict Gamepad API access to secure contexts only (e.g. https only).
