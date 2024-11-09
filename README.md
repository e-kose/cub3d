# Cub3D

Welcome to the Cub3D project! This project was developed together with [Ertuğrul Köse](https://github.com/e-kose) as part of our educational process in 42 schools. Cub3D is a graphics application based on ray-casting technique that transforms 2D maps into an immersive 3D experience. Our goal is to transform a simple 2D maze map into an immersive 3D environment that the player can explore in real time.

This project aimed to give an in-depth understanding of graphics programming, user interactions and performance optimization. Cub3D offers a classic “Wolfenstein 3D” style gameplay with textured walls with different orientations, dynamic lighting effects and intuitive player controls. Players can freely navigate the environment with WASD and arrow keys, exploring the mysterious labyrinth while trying to reach their goals.

## Game View  
[![Game View](https://github.com/menasy/cub3d/blob/main/GameView/cub3d_GameView.png)](https://github.com/menasy/cub3d/blob/main/GameView/cub3d_demo.mov)

_Click the image above to download the demo video!_

## Installation
```bash
cd Desktop
git clone git@github.com:e-kose/cub3d.git cub3d
cd cub3d
```
For Linux install X11
```bash
sudo apt install libx11-dev libxext-dev libxxi-dev libxrandr-dev libxpm-dev libxmu-dev libxi-dev libxcursor-dev libxt-dev libbsd-dev libjpeg-dev libpng-dev libtiff- dev libgif-dev libopenexr-dev libmpc-dev libgmp-dev libgmp-dev libmpfr-dev libgomp1 libgomp-plugin-nvptx libgomp1-plugin-nvptx libatomic1 libquadmath0 libpgm-dev libssl-dev
```
## Usage
To compile the program, run:
```bash
make
```
To run the program, use one of the following commands:
```bash
./cub3d map/kvp.ber
```

## Graphics Library
In this project we used the **MLX** library, a basic graphics library for window graphics management. MLX provided us with the tools and functions necessary to create and render 3D environment, manage user input and render graphic elements effectively.

## Key Features

### Beam Casting Magic
Our project harnesses the power of ray casting to transform a 2D map into a 3D wonderland. By skillfully manipulating rays, we bring depth and dimension to what was once a flat surface. This technique allows us to create the illusion of 3D environments in real time.

### Textured Walls
We take our project one step further by adding textures to the walls. Each main direction (north, south, east and west) is decorated with its own unique texture, enhancing the immersive experience. The variety of textures adds realism and depth to our virtual world.

### Player Controls
Players can explore the 3D environment with intuitive controls:
- `W` for **forward** movement
- `S` for **backward** movement
- `A` for **left** movement
- `D` for **right** movement
- Use the left and right arrow keys to **change the viewpoint**.

These controls provide a fluid and engaging user experience that facilitates discovery.

### Error Handling
We've taken care to ensure robust error handling. Our project can elegantly handle various error scenarios that can result from an invalid map. Whether it's an unclosed border or missing items, we've got it covered. Users can expect a stable and reliable experience.

## Resources Utilized
We used the following resources to develop this project:

1. [Ray-Casting Tutorial (Lode's Computer Graphics Tutorial)](https://lodev.org/cgtutor/raycasting.html)
2. [Ray-Casting Tutorial (Permadi)](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
3. [YouTube Video: Raycasting Engine Explained](https://youtu.be/NbSee-XM7WA?si=X3YdlcCzzg--oJCx)
4. [Raycasting Engine Tutorial by Pikuma](https://pikuma.com/courses/raycasting-engine-tutorial-algorithm-javascript)
5. [Medium Article: Raycasting in Cub3D - A Practical Guide](https://medium.com/@rtailidounia/raycasting-in-cub3d-42-network-project-a-practical-tutorial-using-vectors-68eeb16b3de2)

These resources gave us a deep understanding of ray casting and the basics of 3D graphics. In particular, we used these guides to optimize ray casting algorithms and make the game world more immersive.

