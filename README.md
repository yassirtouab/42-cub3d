# 42-cub3d


<h1 align="center">
	📖 cub3d
</h1>

<p align="center">
	<b><i>my first raycasting game</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/isaad18/42-cub3d?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/isaad18/42-cub3d?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/isaad18/42-cub3d?color=red" />
	<img alt="GitHub top language" src="https://img.shields.io/github/search/isaad18/42-cub3d/visit?color=green" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/isaad18/42-cub3d?color=green" />
</p>

## QuickStart

### Makefile provided, you can compile using the command
```
make all
```

### The executable (cub3d) takes one arguement which is the map, where you can choose some of our demo maps
```
./cub3d maps/*
```

## Description

#### This game is done using the raycasting way where I sent vectors from the starting position of the player that checks everytime it hits a grid till it reaches a wall '1' and then calculate the exact distance by taking the grid size as a 1 unit. Depending on the distance from the player to the wall, the vertical size of the wall is calculated.

#### You can start the game as said before in QuickStart. For the moves, you can using the keys (WASD) and use the arrows to look around or you can use the mouse inside the window.
