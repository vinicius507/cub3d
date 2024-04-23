<p align="center">
    <img src="https://game.42sp.org.br/static/assets/achievements/cub3dm.png">
</p>

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%2B%2B98-orange.svg" alt="Language">
    <img src="https://img.shields.io/badge/Grade-110%2F100-brightgreen.svg" alt="Grade">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

# Cub3D
[![build](https://github.com/vinicius507/cub3d/actions/workflows/build.yaml/badge.svg)](https://github.com/vinicius507/cub3d/actions/workflows/build.yaml)

An [École 42](https://42.fr) project.

![GIF of the game](/assets/showcase.gif)

Cub3D is a
[graphics engine](<https://en.wikipedia.org/wiki/Rendering_(computer_graphics)>)
inspired by the game
[Wolfenstein 3D](https://en.wikipedia.org/wiki/Wolfenstein_3D).

Developed in C using the [MinilibX](https://github.com/42Paris/minilibx-linux)
graphics library, Cub3D uses the
[Raycasting](https://en.wikipedia.org/wiki/Ray_casting) technique to render 3D
graphics in a 2D window.

## Usage

1. Clone the repository:

```bash
$ git clone https://github.com/vinicius507/cub3d
```

2. Change to the project directory:

```bash
$ cd cub3d
```

3. Build the project:

```bash
$ make
```

4. Run the game with one of the test maps:

```bash
$ ./cub3D ./test_maps/test.cub
```

>[!NOTE]
> Only the maps test.cub and test2.cub are working maps. The other maps are for testing purposes.

## Authors
- [Vinicius Oliveira (vgoncalv)](https://github.com/vinicius507)
- [Felipe Camargo](https://github.com/unilui)
