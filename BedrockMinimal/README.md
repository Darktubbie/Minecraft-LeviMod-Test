# Bedrock Minimal
Proyecto mínimo de mod nativo para LeviLauncher + Preloader Android.

Requisitos: Android NDK 28.2.13676358 (r28c), CMake 3.22+, Ninja y Git.

El proyecto usa únicamente la API pública de Preloader y fija la dependencia
preloader-android en 0.2.2.

El libminecraftpe.so usado para el análisis de firmas no se incluye en el mod.

Construcción:
cmake -S . -B build-arm64-v8a -G Ninja \
  -DCMAKE_TOOLCHAIN_FILE="$ANDROID_NDK/build/cmake/android.toolchain.cmake" \
  -DANDROID_ABI=arm64-v8a -DANDROID_PLATFORM=android-28 \
  -DANDROID_STL=c++_shared
cmake --build build-arm64-v8a --target levi_package


## GitHub Actions

El workflow `.github/workflows/build.yml` compila el mod sin Android Studio.
Instala NDK 28.2.13676358 (r28c), CMake y construye para `arm64-v8a`.

Después de subir el proyecto a GitHub:
1. Abre **Actions**.
2. Selecciona **Build LeviLauncher Mod**.
3. Usa **Run workflow** o haz push a `main`.
4. Descarga el artifact `BedrockMinimal-LeviLauncher`.
